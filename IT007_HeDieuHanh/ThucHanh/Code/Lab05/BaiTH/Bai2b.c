// Đã đồng bộ

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

int* a;
int n;
int iNum = 0;
sem_t sem1, sem2, busy;

void Arrange(int *a, int x)
{
    if(x == iNum)
        iNum--;
    else
    {
        for(int i = x; i < iNum-1; i++)
            a[i] = a[i+1];
        iNum--;
    }
}

void* ProcessA(void* mess)
{
    while(1)
    {
        sem_wait(&sem2);
        sem_wait(&busy);
        srand((int)time(0));
        a[iNum] = rand();
        iNum++;
        printf("So phan tu trong a = %d\n", iNum);
        sem_post(&sem1);
        sem_post(&busy);
    }
}

void* ProcessB(void* mess)
{
    while(1)
    {
        sem_wait(&sem1);
        sem_wait(&busy);
        srand((int)time(0));
        if(iNum == 0)
            printf("Nothing in array\n");
        else
        {
            int r = rand() % iNum;
            Arrange(a, r);
            printf("So phan tu trong a sau khi lay ra = %d\n", iNum);
        }
        sem_post(&sem2);
        sem_post(&busy);
    }
}

int main()
{
    printf("Nhap so phan tu: \n");
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, n);
    sem_init(&busy, 0, 1);
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &ProcessA, NULL);
    pthread_create(&pB, NULL, &ProcessB, NULL);
    while(1){}

    return 0;
}