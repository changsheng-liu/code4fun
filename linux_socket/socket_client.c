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
	if(inet_aton("127.0.0.1", &addr.sin_addr)<=0) { 
        significateErr();
    } 
	// addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(atoi(argv[1]));
	int addr_len = sizeof(addr);
	if(connect(tcpsocket, (struct sockaddr *)&addr, sizeof(addr)) < 0){
		significateErr();
    }
	const char * hi = "hi";
	write(tcpsocket, hi, sizeof(char) * 3);
	printf("connected!\n");
	close(tcpsocket);
	return 1;
}