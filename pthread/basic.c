#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * hello(void * param) {
	
	printf("I am thread %ld !\n", (long) param);
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_t threads[5];
	long i;
	for (i = 0; i<5;i++) {
		if(pthread_create(&threads[i], NULL, hello, (void *)i) != 0){
			printf("error!\n");
			exit(-1);
		}
		printf("Main create thread %ld\n", i);
	}
	
	pthread_exit(NULL);
	return 0;
}