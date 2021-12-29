#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void * Rand (void * param)
{
	int randomnumber;
    randomnumber = rand() % 10;
    return (int *) randomnumber;
}
int main()
{
	int sum;
	int ran[5];
	pthread_t thread[5];
	for (int i = 0; i < 5; i++) 
	{ 
		pthread_create (&thread[i], 0, Rand, 0);
		pthread_join(thread[i], (void**)&ran[i]);
		sum += ran[i];
		printf("%d", ran[i]);
	}
	printf("The sum = %d", sum);
}
