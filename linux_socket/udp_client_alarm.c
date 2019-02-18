#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include<errno.h>

#define BUFF_LEN 1024

static void sig_alrm(int);

static void sig_alrm(int signo)
{return; /* just interrupt the recvfrom() */ }

void err(void) {
    fprintf(stderr, "err!");
    exit(-1);
}

int main(int argc, char* argv[])
{
    int client_fd;
    struct sockaddr_in ser_addr;

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
    socklen_t len;
    // struct sockaddr_in src;
    char buf[BUFF_LEN];
    char recv[BUFF_LEN];
    int n;
    for( ; ; ) {
        while(fgets(buf, BUFF_LEN, stdin) != NULL){
            len = sizeof(ser_addr);
            sendto(client_fd, buf, BUFF_LEN, 0, (struct sockaddr*)&ser_addr, len);
            // recvfrom(client_fd, recv, BUFF_LEN, 0, (struct sockaddr*)&src, &len);
            alarm(5);
            if((n = recvfrom(client_fd, recv, BUFF_LEN, 0, NULL, NULL)) < 0) {
                if(errno == EINTR) {
                    printf("interrupted\n");
                }else {
                    printf("errorrrrr\n");
                }
            }else {
                alarm(0);
                fputs(recv, stdout);
                bzero(recv, BUFF_LEN);
            }
        }
    }

    close(client_fd);

    return 0;
}