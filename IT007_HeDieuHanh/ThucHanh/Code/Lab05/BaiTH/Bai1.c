#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int sells = 0, products = 0;
sem_t sem1, sem2;

void *ProcessA(void* mess)
{
    while(1)
    {
        sem_wait(&sem1);
        sells++;
        printf("Sells = %d\n", sells);
        sem_post(&sem2);
    }
}

void *ProcessB(void* mess)
{
    while(1)
    {
        sem_wait(&sem2);
        products++;
        printf("Products = %d\n", products);
        sem_post(&sem1);
    }
}

int main()
{
    printf("start\n");
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 66);
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &ProcessA, NULL);
    pthread_create(&pB, NULL, &ProcessB, NULL);
    printf("end\n");
    while(1){}

    return 0;
}