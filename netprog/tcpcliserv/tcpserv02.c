#include "unp.h"
#include "declare.h"

int main( int argc, char** argv )
{
	int      listenfd, connfd;
	pid_t    childpid;
	socklen_t childlen;
	struct sockaddr_in cliaddr, servaddr;

	listenfd = Socket( AF_INET, SOCK_STREAM, 0 );

	bzero( &servaddr, sizeof(servaddr) );

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
	servaddr.sin_port = htons( SERV_PORT );
	
	Bind( listenfd, (SA*)&servaddr, sizeof(servaddr) );

	Listen( listenfd, LISTENQ );

	Signal(SIGCHLD, sig_chld);

	while(1)
	{
		childlen = sizeof(cliaddr);
		connfd = Accept( listenfd, (SA*)&cliaddr, &childlen );
		//printf("11111\n");
		if ( ( childpid = Fork() ) == 0 )
		{
			//printf("2222\n");
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close( connfd );
	}

	return 0;
}
