#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
int main()
{
	struct sockaddr_in addr;
	socklen_t addrLen;
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		printf("Failed to create socket");
	}
	addr.sin_family = AF_INET;
	addr.sin_port = 0; 
	addr.sin_addr.s_addr = INADDR_ANY; 
	if (bind(fd, (const struct sockaddr *)&addr, sizeof(addr)) == -1) {
		printf("Failed to bind");
	}
	addrLen = sizeof(addr);
	if (getsockname(fd, (struct sockaddr *)&addr, &addrLen) == -1) {
		printf("getsockname() failed");
	}
	printf("port=%d \n", addr.sin_port);
	return 0;
}