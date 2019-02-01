#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


#define BUFSIZE 10
int buffer[BUFSIZE];
sem_t produce_cnt;
sem_t consume_cnt;
int write_pt = 0;
int read_pt = 0;
int num = 0;

void * produce(void * p) {
	int i;
	int r;
	for (i = 0;i < 1000;i++) {
		sem_wait(&produce_cnt); 
		buffer[write_pt] = i;
		num++;
		write_pt = (write_pt+1) % BUFSIZE;
		printf("producer: add %d\n", i);
		sem_post(&consume_cnt);
	}
	pthread_exit(NULL);
	return NULL;
}

void * consume(void * p) {
	int i, readnum;
	for (i = 0;i < 1000;i++) {
		sem_wait(&consume_cnt);		
		readnum = buffer[read_pt];
		num--;
		read_pt = (write_pt+1) % BUFSIZE;
		printf("consumer: remove %d\n", i);

		sem_post(&produce_cnt);
	}
//	pthread_exit(NULL);
	return NULL;
}

int main(int argc, char *argv[]) {
	sem_init(&produce_cnt, 0, BUFSIZE);
	sem_init(&consume_cnt, 0, 0);
	pthread_t producer, consumer;
	int rc;
	rc = pthread_create(&producer, NULL, produce, NULL);
	if (rc) {
		printf("error!!!!");
		_exit(1);
	}
	rc = pthread_create(&consumer, NULL, consume , NULL);
	if(rc) {
		printf("error!!!!");
		_exit(-1);
	}
//	pthread_join(producer, NULL);
//	pthread_join(consumer, NULL);

	pthread_exit(NULL);
	return 0;
}