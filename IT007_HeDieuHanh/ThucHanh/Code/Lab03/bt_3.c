#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// Một biến cần được khai báo dưới dạng biến volatile khi nào? Khi mà giá trị của nó có thể thay đổi một cách không báo trước.
// sig_atomic_t: Đây là kiểu int và được sử dụng như là một biến trong bộ xử lý tín hiệu (signal handler).
// Sử dụng biến volatile để tránh lỗi optimize
volatile sig_atomic_t loop_forever = 2;

void on_sigint(int sigmun)
{
    if(loop_forever == 2)
        printf("\ncount.sh has stopped!\n");
    loop_forever--;
}

int main()
{
    printf("Welcome to IT007, I am 22520066!\n");

    // Đăng ký hàm on_sigint để xử lý tín hiệu SIGINT
    signal(SIGINT, on_sigint);

    // Tạo process mới (con)
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");

        // Thoát chương trình nếu fork thất bại
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // Process on
    {
        // Thực thi script count.sh
        execlp("./count.sh", "count.sh", "120", NULL);

        exit(EXIT_FAILURE);
    }
    else // Process cha
    {
        int status;

        // Chờ process con kết thúc
        waitpid(pid, &status, 0);
    }

    while (loop_forever) {}

    return 0;
}