#include <stdio.h>
#include <pthread.h>

#define BUFSIZE 10
int buffer[BUFSIZE];
int write_pt = 0;
int read_pt = 0;
int num = 0;
pthread_mutex_t lock;// = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t prod;// = PTHREAD_COND_INITIALIZER;
pthread_cond_t cons;// = PTHREAD_COND_INITIALIZER;

void * produce(void * p) {
	int i;
	int r;
	for (i = 0;i < 1000;i++) {
		pthread_mutex_lock(&lock);
		while (num == BUFSIZE) {
			pthread_cond_wait(&cons, &lock);
		}
		buffer[write_pt] = i;
		num++;
		write_pt = (write_pt+1) % BUFSIZE;
		printf("producer: add %d\n", i);
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&prod);
	}
	pthread_exit(NULL);
}

void * consume(void * p) {
	int i, readnum;
	for (i = 0;i < 1000;i++) {
		pthread_mutex_lock(&lock);
		while (num == 0) {
			pthread_cond_wait(&prod, &lock);
		}
		
		readnum = buffer[read_pt];
		num--;
		read_pt = (write_pt+1) % BUFSIZE;
		printf("consumer: remove %d\n", i);

		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&cons);
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&prod, NULL);
	pthread_cond_init(&cons, NULL);
	pthread_t producer, consumer;
	int rc;
	rc = pthread_create(&producer, NULL, produce, NULL);
	if (rc) {
		printf("error!!!!");
		exit(-1);
	}
	rc = pthread_create(&consumer, NULL, consume , NULL);
	if(rc) {
		printf("error!!!!");
		exit(-1);
	}
	pthread_exit(NULL);
	return 0;
}