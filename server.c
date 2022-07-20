/*
 * udpserver.c
 *
 * This is an example TCP/IP UDP socket server.
 * It will read packets sent to 'portno'.
 * It will loop forever and must be killed in order to make
 * it terminate.
 *
 * Test 012
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/times.h>
#include <errno.h>
#include <sys/uio.h>
#include <signal.h>

#define TRUE 1
#define FALSE 0
#define SIZE 6
#define ACK  'z'


#define MAXBUF	10 * 1024

int sock;
int sock2;
// ./server catch 3000
void printFrom(from)
struct sockaddr_in *from;
{
    char *ns;
    struct hostent *gethostbyaddr();
    struct hostent *h;
    char *inet_ntoa();

    fprintf(stdout,": client port %d: ",from->sin_port&0xffff);
    /* convert inet number to inet network string
    */
    ns = inet_ntoa(from->sin_addr);
    /*
    h = gethostbyaddr(ns,sizeof(ns),AF_INET);
    */
    fprintf(stdout,"client ip addr: %s\n",ns);
}
void onintr()
{
    close(sock);
    exit(0);
}
int main(int argc,char **argv)
{
	struct sockaddr_in server;
	struct sockaddr_in server2;
	struct sockaddr_in from;
	char buf[MAXBUF];
	int ackvar = ACK;
	int fromlen;
	extern int errno;
	char *url;
	char udp[7];
	int port;
	int port2;
	int ip_address;
    int rc;
    const char* hostname;
    char ip[SIZE];
    const char* port_num;
    struct addrinfo* res;
    int err;
    int fd;
    int i = 0;
    int j = 0;
    char send_port[5];
	extern void onintr();
	int current = 0; //./server mode 2000 3000 ip_address
	if (argc != 2) {
        printf("Error, the command line needs to be 2 arguments\nExample: ./server udp://127.0.0.1:5000\n");
        exit(-1);
	}
	url = argv[1];
    port = 2000;
    memset(udp,0,7);
    while(i < 6){
        udp[i] = url[i];
        i++;
    }
    if(strcmp(udp,"udp://") != 0){
        printf("URL error\n");
    }
    memset(ip,0,15);
    while(url[i] != ':'){
        ip[i-6] = url[i];
        i++;
    }
    i++;
    while(i < strlen(url)){
        send_port[j] = url[i];
        i++;
        j++;
    }
    send_port[j] = '\0';
	fromlen = sizeof( struct sockaddr_in );

	signal(SIGINT, onintr);

	/* create INTERNET, udp datagram socket
	*/
	sock = socket(AF_INET, SOCK_DGRAM, 0);

    if ( sock < 0 ) {
		perror("udp server: socket call\n");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;   /* ok from any machine */
	server.sin_port = htons(port);      /* specific port */

	/* bind protocol to socket
	*/
	if (bind(sock, (struct sockaddr *)&server, sizeof(server))) {
		perror("binding udp socket\n");
		exit(1);
	}

	for ( ;; ) {     /* do forever */
		rc = -1;
        fd = -1;
		if ((rc=recvfrom(sock, buf, MAXBUF, 0, (struct sockaddr *)&from, &fromlen)) < 0 ) {
			printf("server error: errno %d\n",errno);
			perror("reading datagram");
			exit(1);
		}

		printf("udpserver: got packet %d: ", current);
		printFrom(&from);

        sprintf(ip,"%d",ip_address);
        hostname = ip; /* localhost */
//        port_num = argv[3];
        struct addrinfo hints;
        memset(&hints,0,sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_DGRAM;
        hints.ai_protocol = 0;
        hints.ai_flags = AI_ADDRCONFIG;
        res = 0;
        err = getaddrinfo(hostname,send_port,&hints,&res);
        if (err != 0) {
            printf("failed to resolve remote socket address (err=%d)",err);
            exit(-1);
        }
        fd = socket(res -> ai_family,res -> ai_socktype,res -> ai_protocol);
        if (fd == -1) {
            printf("%s\n",strerror(errno));
            exit(-1);
        }
        if (sendto(fd,buf,sizeof(buf),0,
                   res -> ai_addr,res -> ai_addrlen) == -1) {
            printf("%s\n",strerror(errno));
            exit(-1);
        }
        current++;



	}
    close(sock);
	/* can't get here, but just in case: close sockets
	*/
	return(0);
}




