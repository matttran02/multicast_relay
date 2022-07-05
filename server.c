/*
 * udpserver.c
 *
 * This is an example TCP/IP UDP socket server.
 * It will read packets sent to 'portno'.
 * It will loop forever and must be killed in order to make
 * it terminate.
 *
 * This is the july_5_02 branch
 *
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/times.h>
#include <errno.h>
#include <signal.h>

#define TRUE 1
#define FALSE 0
#define SIZE 6
#define ACK  'z'


#define MAXBUF	10 * 1024 

int sock;
int sock2;
// ./server catch 3000
main(argc,argv)
char **argv;
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
	extern int onintr();
	int current = 0;

	if (argc != 4) {
		printf("./server mode ['catch' or 'relay'] listen_port send_port\n");
		exit(1);
	}
	mode = argv[1];
	if(strcmp(mode,"catch") != 0 && strcmp(mode,"relay") != 0){
	    printf("mode has to be ['catch' or 'relay']\n");
	    exit(-1);
	}
    port = atoi(argv[2]);
	port2 = atoi(argv[3]);
	fromlen = sizeof( struct sockaddr_in ); 

	signal(SIGINT, onintr);

	/* create INTERNET, udp datagram socket
	*/
	sock = socket(AF_INET, SOCK_DGRAM, 0);
    sock2 = socket(AF_INET, SOCK_DGRAM, 0);

    if ( sock < 0 ) {
		perror("udp server: socket call\n");
		exit(1);
	}
    if ( sock2 < 0 ) {
        perror("udp server: socket2 call\n");
        exit(1);
    }


	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;   /* ok from any machine */
	server.sin_port = htons(port);      /* specific port */
    server2.sin_family = AF_INET;
    server2.sin_addr.s_addr = INADDR_ANY;   /* ok from any machine */
    server2.sin_port = htons(port2);

	/* bind protocol to socket
	*/
	if (bind(sock, &server, sizeof(server))) {
		perror("binding udp socket\n");
		exit(1);
	}
    if (bind(sock2, &server2, sizeof(server2))) {
        perror("binding udp socket\n");
        exit(1);
    }

	for ( ;; ) {     /* do forever */
		int rc;

		if ((rc=recvfrom(sock, buf, MAXBUF, 0, &from, &fromlen)) < 0 ) {
			printf("server error: errno %d\n",errno);
			perror("reading datagram");
			exit(1);
		}

		printf("udpserver: got packet %d: ", current);
		printFrom(&from);

		if( sendto(sock2,&ackvar,sizeof(long), 0,
			&from,sizeof (struct sockaddr_in)) < 0 ) {
			perror("sendto");
			if (errno == ENOBUFS)
				continue;
			exit(1);
		}
		current++;

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