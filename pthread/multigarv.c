#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_param {
	int thread_id;
	char * message;
};

struct thread_param thread_array[5];

void * hello(void * param) {
//	sleep(1);
	struct thread_param * myargv = (struct thread_param *)param;	
	printf("thread %d, message: %s\n", myargv->thread_id, myargv->message);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_t threads[5];
	long i;
	char * m[5];
	m[0] = "hello1";
	m[1] = "mello2";
	m[2] = "what3";
	m[3] = "ttt4";
	m[4] = "hfwiuvh5";
	for (i = 0; i<5;i++) {
		thread_array[i].thread_id = i;
		thread_array[i].message = m[i];
		if(pthread_create(&threads[i], NULL, hello, &thread_array[i]) != 0){
			printf("error!\n");
			exit(-1);
		}
		printf("Main create thread %ld\n", i);
	}
	
	pthread_exit(NULL);
	return 0;
}