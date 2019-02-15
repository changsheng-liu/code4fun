#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void significateErr(void) {
	fprintf(stderr, "err\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	int tcpsocket = socket(AF_INET, SOCK_STREAM, 0);
	if(tcpsocket < 0) {
		significateErr();
	}
	struct sockaddr_in addr; 
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(atoi(argv[1]));
	if(bind(tcpsocket, (struct sockaddr *)&addr, sizeof(addr)) < 0){
		significateErr();
	}
	if(listen(tcpsocket, 1) < 0){
		significateErr();
	}
	while (1) {
		int addr_len = sizeof(addr);
		int server_sock = accept(tcpsocket, (struct sockaddr *)&addr, (socklen_t *) &addr_len);
		if(server_sock < 0) {
			significateErr();			
		}
		char buf[100];
		memset(buf,0,sizeof(char)*100);
		if(read(server_sock,buf,sizeof(char) * 100)){
			printf("connected!\n");
			close(server_sock);
		}
	}
		
	return 1;
}