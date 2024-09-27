#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define BUFFER_SIZE 10

typedef struct
{
    int data[BUFFER_SIZE];
    int index;
} SharedBuffer;

void producer(SharedBuffer *buffer)
{
    while (1)
    {
        // Tạo số ngẫu nhiên trong khoảng 10, 20]
        int num = rand() % 11 + 10;

        // Ghi dữ liệu vào buffer
        buffer->data[buffer->index] = num;
        printf("Produced: %d\n", num);

        // Tăng chỉ số
        buffer->index = (buffer->index + 1) % BUFFER_SIZE;

        // Ngủ một khoảng thời gian ngẫu nhiên [0,1) giây
        usleep(rand() % 1000000);

        // Kiểm tra nếu tổng lớn hơn 100 thì dừng lại
        int sum = 0;
        for (int i = 0; i < BUFFER_SIZE; i++)
            sum += buffer->data[i];
        
        if (sum > 100)
            break;
    }
}

void consumer(SharedBuffer *buffer)
{
    int sum = 0;
    while (1)
    {
        // Đọc dữ liệu từ buffer
        int num = buffer->data[buffer->index];
        printf("Consumed: %d\n", num);

        // Tính tổng
        sum += num;

        // Tăng chỉ số
        buffer->index = (buffer->index + 1) % BUFFER_SIZE;

        // Ngủ một khoảng thời gian ngẫu nhiên [0,1) giây
        usleep(rand() % 1000000); 

        // Kiểm tra nếu tổng lớn hơn 100 thì dừng lại
        if (sum > 100)
            break;
    }
    printf("Total sum: %d\n", sum);
}

int main()
{
    // Tạo segment shared-memory
    key_t key = ftok("/tmp", 'a');
    int shmid = shmget(key, sizeof(SharedBuffer), 0666 | IPC_CREAT);
    SharedBuffer *buffer = (SharedBuffer *)shmat(shmid, NULL, 0);

    // Khởi tạo chỉ số của buffer
    buffer->index = 0;

    // Tạo tiến trình con
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Tiến trình con đóng vai trò là Consumer
        consumer(buffer);
    }
    else 
    {
        // Tiến trình con đóng vai trò là Producer
        srand(time(NULL));
        producer(buffer);

        // Chờ tiến trình con kết thúc
        wait(NULL);

        // Gỡ bỏ segment shared-memory
        shmdt(buffer);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}