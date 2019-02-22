#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFF_LEN 1024

void err(void) {
    fprintf(stderr, "err!");
    exit(-1);
}

int main(int argc, char* argv[])
{
    int client_fd;
    struct sockaddr_in ser_addr, ser_addr2;

    if((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        err();
    }
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    // ser_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    ser_addr.sin_port = htons(atoi(argv[1]));  
    if(inet_aton("127.0.0.1", &ser_addr.sin_addr)<=0) { 
        err();
    } 
    char str[100];
    printf("port : %d \n", (int)ntohs(ser_addr.sin_port));
	printf("ip : %s \n",inet_ntop(AF_INET,&ser_addr.sin_addr ,str, INET_ADDRSTRLEN));
    socklen_t len;

    char buf[BUFF_LEN];
    char shoudao[BUFF_LEN];

    if(fgets(buf, BUFF_LEN, stdin) != NULL){
        len = sizeof(ser_addr);
        sendto(client_fd, buf, BUFF_LEN, 0, (struct sockaddr*)&ser_addr, len);
    }

    recvfrom(client_fd, shoudao, BUFF_LEN, 0,(struct sockaddr*)&ser_addr, &len);
    fputs(shoudao, stdout);

    int new_sock;
    if((new_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        err();
    }
    if(fgets(buf, BUFF_LEN, stdin) != NULL){
        len = sizeof(ser_addr);
        sendto(new_sock, buf, BUFF_LEN, 0, (struct sockaddr*)&ser_addr, len);
    }

    recvfrom(new_sock, shoudao, BUFF_LEN, 0,(struct sockaddr*)&ser_addr, &len);
    fputs(shoudao, stdout);    

    close(client_fd);
    close(new_sock);
    return 0;
}