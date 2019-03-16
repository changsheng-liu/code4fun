#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_LEN 64
#define CLIENT_PORT 2222
//nc -l 2222
#define SERVER_PORT 1115 
//telnet 127.0.0.1 1115
//nc -n 127.0.0.1 1115

int main(int argc, char *argv[]) {
	//client
	int client_fd;
	if((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("fatal error!\n");
		exit(-1);
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	if(inet_aton("127.0.0.1", &addr.sin_addr)<=0) { 
		printf("fatal error!\n");
		exit(-1);
	} 
	addr.sin_port = htons(CLIENT_PORT);

	if(connect(client_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		printf("fatal error!\n");
		exit(-1);
	}

	//server
	int listen_fd;
	if((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("fatal error!\n");
		exit(-1);
	}

	struct sockaddr_in addr2;
	bzero(&addr2, sizeof(addr2));
	addr2.sin_family = AF_INET;
	addr2.sin_addr.s_addr = htonl(INADDR_ANY);
	addr2.sin_port = htons(SERVER_PORT);

	if((bind(listen_fd, (struct sockaddr*)&addr2, sizeof(addr2))) < 0) {
		printf("fatal error!\n");
		exit(-1);
	}
	
	if(listen(listen_fd, 1) < 0){
		printf("fatal error!\n");
		exit(-1);
	}
	int addr_len = sizeof(addr2);
	int server_fd = accept(listen_fd, (struct sockaddr *)&addr2, (socklen_t *) &addr_len);
	if(server_fd < 0) {
		printf("fatal error!\n");
		exit(-1);	
	}

	//select 
	fd_set rset;
	char buf[BUF_LEN];   
	int maxsock = server_fd;
	int ret; 
	while (1) {
		FD_ZERO(&rset);
		FD_SET(client_fd, &rset);
		FD_SET(server_fd, &rset);
		
		ret = select(maxsock + 1, &rset, NULL, NULL, NULL);
		if (ret < 0) {
			printf("fatal error!\n");
			close(client_fd);
			close(listen_fd);
			break;
		}
		if (FD_ISSET(client_fd, &rset)) {
			ret = read(client_fd, buf, BUF_LEN);
			if (ret <= 0) {        // client close
				printf("client close\n");
				close(client_fd);
				FD_CLR(client_fd, &rset);
				client_fd = 0;
			} else {        // receive data
				if (ret < BUF_LEN)
					buf[ret] = 0x00;
				printf("from server:%s\n", buf);
			}
		}
		
		if (FD_ISSET(server_fd, &rset)) {
			ret = read(server_fd, buf, BUF_LEN);
			if (ret <= 0) {        // client close
				printf("client close\n");
				close(server_fd);
				FD_CLR(server_fd, &rset);
				server_fd = 0;
			} else {        // receive data
				if (ret < BUF_LEN)
					buf[ret] = 0x00;
				printf("from client:%s\n", buf);
				
			}
		}
		
		bzero(buf, BUF_LEN);
	}
		
	return 1;
}