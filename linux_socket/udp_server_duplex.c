#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include<sys/select.h>  

#define BUFF_LEN 1024

void err(void) {
    fprintf(stderr, "err!");
    exit(-1);
}

int main(int argc, char* argv[])
{

    // fd_set fdrs, fdws;
    // FD_ZERO(&fdrs);
    // FD_ZERO(&fdws);


    int server_fd;
    struct sockaddr_in ser_addr,clent_addr; 
    struct sockaddr_in addr;

    if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        err();
    }

    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ser_addr.sin_port = htons(atoi(argv[1]));

    if((bind(server_fd, (struct sockaddr*)&ser_addr, sizeof(ser_addr))) < 0) {
        err();
    }

    char buf[BUFF_LEN];  

    socklen_t len;
    struct sockaddr_in ;
    // for( ; ; ) {
        bzero(buf, BUFF_LEN);
        len = sizeof(clent_addr);
        if(recvfrom(server_fd, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, &len) < 0) {
            err();
        }
        fputs(buf, stdout);
        // sendto(server_fd, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, len);
    
    // sendto(server_fd, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, len);


     int s;
    if((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        err();
    }
  
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = 0;
    if((bind(s, (struct sockaddr*)&addr, sizeof(addr))) < 0) {
        err();
    }
    len = sizeof(addr);

    if (getsockname(s, (struct sockaddr *)&addr, &len) == -1) {
		printf("getsockname() failed");
	}
    sprintf(buf, "%d",addr.sin_port);
    len = sizeof(clent_addr);
    sendto(s, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, len);
    
    if(recvfrom(s, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, &len) < 0) {
        err();
    }
    fputs(buf, stdout);
    sendto(s, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, len);
    
    close(s);
    close(server_fd);

    return 0;
}