#include <malloc.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_LINE 80
int number_of_args;
int fdi,fdo;
char *args[MAX_LINE /2+1];
int SaveStdin,SaveStdout;

// Cấp phát bộ nhớ cho mảng
void Allocate_Memory(char *args_aray[])
{
    for (int i=0;i<MAX_LINE /2+1;i++)
    {
        args_aray[i] = (char *)malloc(sizeof(char) * MAX_LINE /2); 
        // Cấp phát bộ nhớ cókích thước MAX_LINE/2 và con trỏ trỏ tới mảng này
    }
}

// nhập lệnh
void EnterCommand(char command[])
{
    fgets(command,MAX_LINE,stdin);
    short int len =strlen(command); // len = độ dài chuỗi
    command[len -1] = 0;// bỏ ký tự xuống dòng trong chuỗi
}

// tách lệnh thành các thành phần
void Tokernizer(char *tokens[],char *source,char *delim,int *num_of_words)
{
    char *p=strtok(source,delim); 
    // Tìm kiếm ký tự đầu tiên trong source mà không có trong delim
    // con trỏ *p trỏ đến chuỗi con trong source được tách ra từ các ký tự trong delim
    int count =0;
    while (p!= NULL)
    {
        strcpy(tokens[count], p); // sao chép chuỗi p trỏ đến vào tokens[count];
        count++; // tăng count 1 đơn vị
        p=strtok(NULL,delim); // tiếp tực tìm kiếm các chuỗi con trong source
    }
    *num_of_words =count;// gán số lượng chuỗi con vừa tìm được vào nWord
    return;
}

// kiểm tra kết thúc lệnh
void control_sig(int sign)
{
    printf("\n");
    fflush(stdout);
}

// chuyển hướng đầu ra vào file
void redirect_output()
{
    SaveStdout =dup(STDOUT_FILENO); 
    // tạo một bản sao củafile descriptor STDOUT_FILENO rồi gán cho SaveStdout

    fdo =open(args[number_of_args -1], O_CREAT |O_WRONLY |O_TRUNC); 
    // mởfile args[number_of_args - 1] với các quyền tạo, chỉnh sửa

    dup2(fdo,STDOUT_FILENO); 
    // Sao chép file fdo vàoSTDOUT_FILENO và bất kỳ đầu ra nào được ghi và sẽ được chuyển hướng vào file này.
    
    free(args[number_of_args -2]); // giải phóng bộ nhớ
    
    args[number_of_args -2] = NULL;// Đặt args[number_of_args -2] = NULL
}

// chuyển hướng đầu vào (input redirection) trong một chương trình chạy
void redirect_input()
{
    SaveStdin =dup(STDIN_FILENO); 
    // tạo một bản sao của file descriptorSTDIN_FILENO và gán cho SaveStdin

    fdi =open(args[number_of_args -1], O_RDONLY); 
    // mở file args[number_of_args -1] chỉ với quyền đọc và gán cho fdi
    
    dup2(fdi,STDIN_FILENO); 
    // sao chép file descriptor fdi vào STDIN_FILENO

    free(args[number_of_args -2]);args[number_of_args -2] = NULL;
    // giải phóng bộ nhớ đã cấp phát và gán thành NULL
}

// khôi phục lại stdout sau khi đã thực hiện chuyển hướng đầu ra (output redirection) vào một file.
void RestoreOut()
{
    close(fdo); // đóng file và giải phóng tài nguyên

    dup2(SaveStdout,STDOUT_FILENO); 
    // sao chép file descriptor SaveStdout vào STDOUT_FILENO
    
    close(SaveStdout); // đóng file saved_sdtout và giải phóng tài nguyên
}

// khôi phục lại stdin sau khi đã thực hiện chuyển hướng đầu vào (input redirection) từ một file
void RestoreIn()
{
    close(fdi); // đóng file và giải phóng tài nguyên
    dup2(SaveStdin,STDIN_FILENO); // sao chép file descriptor saved_sdtin vào STDIN_FILENO
    close(SaveStdin); // đóng file và giải phóng tài nguyên
}

// thực thi hai lệnh được kết nối bằng một pipe trong một chương trình
void Execute_pile(char *parsed[],char *parsedpipe[])
{
    pid_t PID1,PID2;
    int stat;
    int fd[2];
    PID1 =fork(); // tạo tiến trình con p1

    if (PID1 <0)
    {
        // in ra lỗi nếu không thể tạo
        printf("\nLỗi không thể tạo tiến trình con");
        return;
    }
    
    if (PID1 == 0)
    {
        // Khi ở trong tiến trình con p1, tạo 1 tiến trình con khác: p2
        if (pipe(fd) < 0)
        {
            printf("\nTạo ống thất bại");
            return;
        }
        PID2 =fork();
        if (PID2 <0)
        {
            printf("\nLỗi không thể tạo tiến trình con");
            exit(0);
        }
        
        // Khi ở trong tiến trình con p2
        if (PID2 == 0)
        {
            // đóng đầu đọc của pipe
            close(fd[0]);
            // sao chép đầu ghi của pipe vào STDOUT_FILENO
            dup2(fd[1], STDOUT_FILENO);
            if (execvp(parsed[0], parsed) < 0)
            {
                printf("\nKhông thể thực thi");exit(0);
            }
        }
        else
        {
            // Khi p1 đang thực thi
            wait(NULL); // đợi tiến trình con p2 kết thúc
            close(fd[1]); // đóng đầu ghi của pipe
            dup2(fd[0], STDIN_FILENO); // sao chép đầu đọc của pipe vào STDIN_FILENO
            
            if (execvp(parsedpipe[0], parsedpipe) < 0)
            {
                printf("\nKhông thể thực thi");
                exit(0);
            }
        }
    }
    else
    {
        wait(NULL); // đơi p1 kết thúc
    }
}

// tìm kiếm ký tự pipe
int Find_pile_char(char *cmd,char *cmdpiped[])
{
    int i;
    for (i=0;i<2;i++)
    {
        cmdpiped[i] = strsep(&cmd,"|"); 
        // Tìm kiếm ký tự "|", khi thấy sẽ loại bỏ lý tự nàyrồi gán vào mảng
        
        if (cmdpiped[i] == NULL)
        break;
    }
    
    if (cmdpiped[1] == NULL)
        return 0;// trả về 0 khi không tìm thấy
    else
    {
        return 1;// Trả về 1 nếu tìm thấy
    }
}

// tách một chuỗi lệnh (cmd) thành các đối số riêng biệt dựa trên ký tự khoảng trắng và 
// lưu chúng vào mảng parsedArg
void parseCommandLine(char *cmd,char *parsedArg[])
{
    int i=0;
    while (cmd != NULL)
    {
        parsedArg[i] = strsep(&cmd," "); 
        // tìm kiếm ký tự khoảng trắng đầu tiên trong cmd
        // thay thế nó bằng ký tự null và trả về con trỏ đến đầu chuỗi
        if (parsedArg[i][0] != 0)// Nếu chuỗi không rỗng, tăng i lên 1 đơn vị
            i++;
    }
    parsedArg[i] = NULL;
}

// Kiểm tra có ký tự pipe
int ExecuteString(char *cmd,char *parsed[],char *parsedpipe[])
{
    char *cmdpiped[2]; // Mảng 2 con trỏ lưu 2 chuỗi lệnh được tách ra
    int piped =0;// khởi tạo Piped = 0
    piped =Find_pile_char(cmd,cmdpiped); // gán Piped bằng giá trị trả về của hàm kiểm tra có ký tự Pipe hay không
    // Nếu có sẽ gán 1, ngược lại sẽ gán 0
    if (piped)// Nếu có, phần thứ nhất sẽ gán vào parse, phần thứ 2 sẽ gán vào parsedpipe
    {
        parseCommandLine(cmdpiped[0], parsed);
        parseCommandLine(cmdpiped[1], parsedpipe);
    }
    return piped;
}


int main(void)
{
    int count_HF =0;
    int should_run =1; /* flag to determine when to exit program*/
    char command[MAX_LINE]; // mảng lưu command
    char history_command[MAX_LINE][MAX_LINE]; // mảng lưu lịch sử lệnh
    char *First_Command[MAX_LINE /2+1]; // command đầu tiên của pipe
    char *Second_command[MAX_LINE /2+1]; // command thứ 2 của pipe
    int iPileExe =0;// cờ kiểm tra có thực hiện pipe
    pid_t pid;
    int iRedirectOut =0,iRedirectIn =0;// cờ chuyển hướng đầu ra và đầu vào
    signal(SIGINT,control_sig);
    while (should_run)
    {
        do
        {
            printf("it007sh>");
            fflush(stdout);
            EnterCommand(command);
        }while (command[0] == 0);
        
        if (strcmp(command,"HF") == 0)
        {
            // Kiểm tra lệnh nhập vào có phải yêu cầu lịch sử câu lệnh hay không
            if (history_command[count_HF -1] == 0)
            {
                // Nếu không có lệnh nào trong mảng history_command đã lưu, in ra NULL
                printf("NULL\n");continue;
            }
            else
            {
                // Ngược lại, in ra thưc thi câu lệnh này
                for (int i=0;i<= count_HF -1;i++)
                {
                    printf("%s\n",history_command[i]);
                    strcpy(command,history_command[i]);
                }
            }
        }
        else
        {
            // Lưu câu lệnh trong mảng history_command
            strcpy(history_command[count_HF], command);
            count_HF++;
        }
        iPileExe =ExecuteString(command,First_Command,Second_command);
        // iPileExe sẽ trả về 0 khi là câu lệnh đơn giản như ls, pwd,... và 
        // sẽ trả về 1 khi là câulệnh với input của lệnh đầu tiên sẽ là
        // đầu vào của lệnh tiếp theo (có ký tự pipe (|)).
        if (iPileExe == 0)
        {
            // Nếu không có ký tự pipe trong lệnh
            Allocate_Memory(args); // cấp phát bộ nhớ cho mảng
            strcpy(command,history_command[count_HF -1]); // sao chép chuỗi history_command vào Command
            Tokernizer(args,command," ", &number_of_args); // tách command thành các đối số riêng biệt và lưu chúng vào mảng args
            free(args[number_of_args]);args[number_of_args] = NULL;// đặt vị trí cùng là NULL
            if (strcmp(args[0], "exit") == 0)
            {
                // Kiểm tra lệnh có phải là exit hay không, nếu phải thì sẽ kết thúc
                break;
            }
            else
            {
                if (strcmp(args[0], "~") == 0)
                {
                    // kiểm tra vị trí đầu tiên của mảng có phải là ~
                    char *homedir =getenv("HOME"); // trả về đường dẫn của thu mục HOME và in ra
                    printf("Home : %s\n",homedir);
                }
                else // cd (change directory)
                if (strcmp(args[0], "cd") == 0)
                {
                    // so sánh chuỗi có phải là cd hay không
                    char dir[MAX_LINE];strcpy(dir,args[1]); // Khai báo mảng và sao chép chuỗi vào mảng này
                    if (strcmp(dir,"~") == 0)// Nếu chuỗi vừa được sao chép là ~, copy mảng là đường dẫn đến thư mục HOME
                    {
                        strcpy(dir,getenv("HOME"));
                    }
                    chdir(dir); // thay đổi thư mục hiện tại thành thư mục chỉ định như trong mảng
                    printf("Thư mục hiện tại : ");
                    getcwd(dir,sizeof(dir)); // lấy đường dẫn đầy đủ của thư mục và in ra nó
                    printf("%s\n",dir);
                }
                else
                {
                    int iParrent =strcmp(args[number_of_args -1], "&"); // Kiểm tra vị trí cuối cùng trong chuỗi có phải là & hay không
                    // nếu đúng thì gán iParrent = 0, ngược lại gán iParrent != 0
                    if (iParrent == 0)
                    {
                        // Nếu iParrent = 0
                        free(args[number_of_args -1]); // giải phóng vùng nhớ và gán lại bằng NULL
                        args[number_of_args -1] = NULL;
                    }
                    // Nếu có nhiều hơn 1 đối số và đối số cuối là > thì sẽ chuyển hướng đầu ra 
                    // thông qua hàm redirect_output()
                    if ((number_of_args >1) && strcmp(args[number_of_args -2], ">") == 0)
                    {
                        redirect_output();
                        iRedirectOut =1;// đánh dấu đã thực hiện
                    }
                    else
                    // Nếu có nhiều hơn 1 đối số và đối số cuối là < thì sẽ chuyển hướng đầuvào thông qua hàm redirect_input()
                    if ((number_of_args >1) && strcmp(args[number_of_args -2], "<") ==0)
                    {
                        redirect_input();
                        iRedirectIn =1;// đánh dấu đã thực hiện
                    }
                    pid =fork(); // Tạo tiến trình con pid
                    // thông báo lỗi nếu tạo không thành công
                    if (pid <0)
                    {
                        fprintf(stderr,"Lỗi không thể tạo tiến trình công\n");
                        return -1;
                    }
                    
                    // Khi đang ở trong tiến trình con
                    if (pid == 0)
                    {
                        // thực thi lệnh và nếu lệnh thực hiện thành công, ret = 1, ngược lại ret =-1 và in ra lỗi
                        int ret =execvp(args[0], args);
                        if (ret == -1)
                        {
                            printf("Lệnh không hợp lệ\n");
                        }
                        exit(ret);
                    }
                    else
                    {
                        // khi đang ở trong tiến trình cha
                        if (iParrent)
                        {
                            while (wait(NULL) != pid){}
                            // Tiến trình cha đợi tiến trình con kết thúc
                            if (iRedirectOut)
                            {
                                // Nếu cờ chuyển hướng đầu ra bật lên
                                RestoreOut();
                                iRedirectOut =0;// khôi phục cờ chuyển hướng đầu ra về ban đầu
                            }
                            
                            if (iRedirectIn)
                            {
                                // Nếu cờ chuyển hướng đầu vào bật lên
                                RestoreIn();
                                iRedirectIn =0;// khôi phục cờ chuyển hướng đầu vào về ban đầu
                            }
                        }
                    }
                }
            }
        }
        else 
        // Ngược lại, khi có ký tự pipe trong lệnh, thực hiện lệnh kết nối bằng pipe 
        // thông qua hàm Execute_pile
        Execute_pile(First_Command,Second_command);
    }
    return 0;
}