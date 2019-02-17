#include <stdio.h>
#include <time.h>
int main(int argc, char *argv[]) {
	char sendline[1024];
	time_t ticks = time(NULL);
	printf("%.24s\n",ctime(&ticks));
	
	while(fgets(sendline, 1024, stdin) != NULL){
//		printf("input: %s\n",sendline);
		fputs(sendline, stdout);
	}
}