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

int main()
{
    printf("size = %d", (int)sizeof(SharedBuffer));

    exit(0);
}