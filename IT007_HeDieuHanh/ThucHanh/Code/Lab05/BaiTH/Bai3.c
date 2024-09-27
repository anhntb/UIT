#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int x = 0;

void* ProcessA(void* mess)
{
    while(1)
    {
        x = x + 1;
        if(x == 20)
            x = 0;
        printf("x(pA) = %d\n", x);
    }
}

void* ProcessB(void* mess)
{
	while(1)
    {
		x = x + 1;
		if (x == 20)
			x = 0;
		printf("x(pB) = %d\n", x);
	}
}

int main()
{
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &ProcessA, NULL);
    pthread_create(&pB, NULL, &ProcessB, NULL);
    while(1){}

    return 0;
}