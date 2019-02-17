#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void * hello(void * param) {
	int i = (int)param;
	printf("~%d\n", i);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	long i = 0;
	int *index = NULL;
	int num;
	if (argv[1])
			num = atoi(argv[1]);

	index = calloc (num, sizeof (int));
	for(i = 0; i < num; i++)
	{
			index[i] = i;
	}
	pthread_t *ptr;

	ptr = malloc(sizeof(pthread_t)*num);
	for(i = 0; i < num; i++) {
		pthread_create(&ptr[i], NULL, hello, (void *)i);
	}
	for(i = 0; i < num; i++)
		pthread_join(ptr[i], NULL);

	return 0;
}