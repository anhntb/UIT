#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

int x1=1, x2=2, x3=3, x4=4, x5=5, x6=6;
int w=0, v=0, y=0, z=0, ans=0;
sem_t semAB, semCD, semCD_extra, semEF, semEF_extra, semG, busy;

void* ProcessAB(void* mess)
{
    while(1)
    {
        sem_wait(&semG);
        sem_wait(&busy);
        w=x1*x2;
        v=x3*x4;
        printf("w = x1*x2 = %d\n", w);
        printf("v = x3*x4 = %d\n", v);
        sem_post(&semCD_extra);
        sem_post(&semAB);
        sem_post(&busy);
    }
}

void* ProcessCD(void* mess)
{
    while(1)
    {
        sem_wait(&semCD_extra);
        sem_wait(&semAB);
        sem_wait(&busy);
        y=v*x5;
        z=v*x6;
        printf("y = v*x5 = %d\n", y);
        printf("z = v*x6 = %d\n", z);
        sem_post(&semAB);
        sem_post(&semCD);
        sem_post(&semEF_extra);
        sem_post(&busy);
    }
}

void* ProcessEF(void* mess)
{
    while(1)
    {
        sem_wait(&semEF_extra);
        sem_wait(&semCD);
        sem_wait(&semAB);
        sem_wait(&busy);
        y=w*y;
        z=w*z;
        printf("y = w*y = %d\n", y);
        printf("z = w*z = %d\n", z);
        sem_post(&semEF);
        sem_post(&busy);
    }
}

void* ProcessG(void* mess)
{
    while(1)
    {
        sem_wait(&semEF);
        sem_wait(&busy);
        ans = y+z;
        printf("ans = y+z = %d\n", ans);
        sem_post(&semG);
        sem_post(&busy);
    }
}

int main()
{
    pthread_t pAB, pCD, pEF, pG;
    sem_init(&semAB, 0, 0);
    sem_init(&semCD, 0, 0);
    sem_init(&semCD_extra, 0, 0);
    sem_init(&semEF, 0, 0);
    sem_init(&semEF, 0, 0);
    sem_init(&semG, 0, 1);
    sem_init(&busy, 0, 1);
    pthread_create(&pAB, NULL, &ProcessAB, NULL);
    pthread_create(&pCD, NULL, &ProcessCD, NULL);
    pthread_create(&pEF, NULL, &ProcessEF, NULL);
    pthread_create(&pG, NULL, &ProcessG, NULL);
    while(1){}

    return 0;
}