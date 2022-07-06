/*
 * udpserver.c
 *
 * This is an example TCP/IP UDP socket server.
 * It will read packets sent to 'portno'.
 * It will loop forever and must be killed in order to make
 * it terminate.
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

int main(int argc,char **argv)
{
	struct sockaddr_in server;
	struct sockaddr_in server2;
	struct sockaddr_in from;
	char buf[MAXBUF];
	int ackvar = ACK;
	int fromlen;
	extern int errno;
	char *mode;
	int port;
	int port2;
    int rc;
    const char* hostname;
    const char* port_num;
    struct addrinfo* res;
    int err;
    int fd;
	extern int onintr();
	int current = 0;
	if (argc != 4 && argc != 3) {
        printf("Error needs to be 3 or 4 arguments\n");
        exit(-1);
	}
    else if(strcmp(argv[1],"catch") == 0 && argc != 3){
        printf("mode has to be ['catch'] listen_port\n");
        exit(-1);
    }
    else if(strcmp(argv[1],"relay") == 0 && argc != 4){
        printf("mode has to be ['relay'] listen_port send_port\n");
        exit(-1);
    }
	mode = argv[1];
    port = atoi(argv[2]);
    if(strcmp(argv[1],"relay") == 0 && argc != 4){
        port2 = atoi(argv[3]);
    }
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
	if (bind(sock, &server, sizeof(server))) {
		perror("binding udp socket\n");
		exit(1);
	}

	for ( ;; ) {     /* do forever */
		rc = -1;

		if ((rc=recvfrom(sock, buf, MAXBUF, 0, &from, &fromlen)) < 0 ) {
			printf("server error: errno %d\n",errno);
			perror("reading datagram");
			exit(1);
		}

		printf("udpserver: got packet %d: ", current);
		printFrom(&from);

        if(strcmp(mode,"relay") == 0){
            hostname = 0; /* localhost */
            port_num = argv[3];
            struct addrinfo hints;
            memset(&hints,0,sizeof(hints));
            hints.ai_family = AF_INET;
            hints.ai_socktype = SOCK_DGRAM;
            hints.ai_protocol = 0;
            hints.ai_flags = AI_ADDRCONFIG;
            res = 0;
            err = getaddrinfo(hostname,port_num,&hints,&res);
            if (err != 0) {
                printf("failed to resolve remote socket address (err=%d)",err);
                exit(-1);
            }
            fd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
            if (fd == -1) {
                printf("%s",strerror(errno));
                exit(-1);
            }
            if (sendto(fd,buf,sizeof(buf),0,
                       res->ai_addr,res->ai_addrlen)==-1) {
                printf("%s",strerror(errno));
                exit(-1);
            }
            current++;
        }
        if(strcmp(mode,"catch") == 0){
            current++;
        }
	}
	/* can't get here, but just in case: close sockets
	*/
	close(sock);
	return(0);
}


printFrom(from)
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

onintr()
{
	close(sock);
	exit(0);
}