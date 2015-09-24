#include "unp.h"
#include "declare.h"

/**
  ÖÕ¼«°æ
  Ê±¼ä£º2015-2-27 15:12:54
  **/
int main( int argc, char** argv )
{
	int listenfd, connfd;
	socklen_t clilen;
	pid_t pid;
	struct sockaddr_in servaddr, cliaddr;

	listenfd = Socket( AF_INET, SOCK_STREAM, 0 );

	bzero( &servaddr, sizeof(servaddr) );
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons( SERV_PORT );
	servaddr.sin_addr.s_addr = htonl( INADDR_ANY );

	Bind( listenfd, (SA*)&servaddr, sizeof(servaddr) );

	Listen( listenfd, LISTENQ );

	Signal( SIGCHLD, sig_chld );

	while( 1 )
	{
		clilen = sizeof( cliaddr );
		if ( ( connfd = accept( listenfd, (SA*)&cliaddr, &clilen ) ) < 0 )
		{
			if ( errno == EINTR )
				continue;
			else
				err_sys( "accept error" );
		}
		
		if ( ( pid = Fork() ) == 0 )
		{
			Close( listenfd );
			str_echo( connfd );
			exit(0);
		}
		
		Close( connfd );
	}

	return 0;
}
