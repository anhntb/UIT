#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <command\n", argv[0]);
        return 1;
    }

    struct timeval start, end;
    pid_t child_pid;

    // Lấy thời gian bắt đầu
    gettimeofday(&start, NULL);

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
        execl("/bin/sh", "sh", "-c", argv[1], NULL);
        perror("execl");
        exit(1);
    }
    else
    {
        // Tiến trình cha
        // Đợi tiến trình con kết thúc
        wait(NULL);

        // Lấy thời gian kết thúc
        gettimeofday(&end, NULL);

        // Tính toán thời gian thực thi
        int sec = end.tv_sec - start.tv_sec;
        int usec = end.tv_usec - start.tv_usec;
        double time_elapsed = (sec * 1000000.0 + usec) / 1000000.0;

        // In ra kết quả
        printf("Thời gian thực thi: %.6f giây\n", time_elapsed);
    }

    return 0;
}