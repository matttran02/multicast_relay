#include <errno.h>
#include <string.h>
#include<stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/uio.h>
#define SIZE 75
int main(){
    const char* hostname=0; /* localhost */
    const char* port_num = "2000";
    char content[SIZE];
    strcpy(content,"Hello");
    struct addrinfo hints;
    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    hints.ai_flags = AI_ADDRCONFIG;
    struct addrinfo* res = 0;
    int err=getaddrinfo(hostname,port_num,&hints,&res);
    if (err!=0) {
        printf("failed to resolve remote socket address (err=%d)",err);
        exit(-1);
//        die("failed to resolve remote socket address (err=%d)",err);
    }
    int fd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    if (fd==-1) {
        printf("%s",strerror(errno));
        exit(-1);
//        die("%s",strerror(errno));
    }
    if (sendto(fd,content,sizeof(content),0,
               res->ai_addr,res->ai_addrlen)==-1) {
        printf("%s",strerror(errno));
        exit(-1);
//        die("%s",strerror(errno));
    }
}