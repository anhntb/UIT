#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x = 0;
pthread_mutex_t mutex;

void* ProcessA(void* mess)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        x = x + 1;
        if(x == 20)
            x = 0;
        printf("x(pA) = %d\n", x);
        pthread_mutex_unlock(&mutex);
    }
}

void* ProcessB(void* mess)
{
	while(1)
    {
        pthread_mutex_lock(&mutex);
		x = x + 1;
		if (x == 20)
			x = 0;
		printf("x(pB) = %d\n", x);
        pthread_mutex_unlock(&mutex);
	}
}

int main()
{
    pthread_t pA, pB;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&pA, NULL, &ProcessA, NULL);
    pthread_create(&pB, NULL, &ProcessB, NULL);
    while(1){}

    return 0;
}