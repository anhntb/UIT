// Chưa đồng bộ

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int* a;
int n;
int iNum = 0;

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
        srand((int)time(0));
        a[iNum] = rand();
        iNum++;
        printf("So phan tu trong a = %d\n", iNum);
    }
}

void* ProcessB(void* mess)
{
    while(1)
    {
        srand((int)time(0));
        if(iNum == 0)
            printf("Nothing in array\n");
        else
        {
            int r = rand() % iNum;
            Arrange(a, r);
            printf("So phan tu trong a sau khi lay ra = %d\n", iNum);
        }
    }
}

int main()
{
    printf("Nhap so phan tu: \n");
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &ProcessA, NULL);
    pthread_create(&pB, NULL, &ProcessB, NULL);
    while(1){}

    return 0;
}