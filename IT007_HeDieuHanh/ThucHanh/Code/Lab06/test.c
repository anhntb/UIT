#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void) 
{
    // char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program*/
    char line[MAX_LINE];
    while (should_run) 
    { 
        printf("it007sh> "); 
        fflush(stdout);

        fgets(line, MAX_LINE, stdin);

        pid_t child_pid;

        // Tạo tiến trình con
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            return 1;
        }

        if (child_pid == 0)
        {
            // Tiến trình con
            // Thực thi lệnh shell
            execl("/bin/sh", "sh", "-c", line, NULL);
            perror("execl");
            exit(1);
        }
        else
        {
            // Tiến trình cha
            // Đợi tiến trình con kết thúc
            wait(NULL);

        }
    }

    return 0;
}
