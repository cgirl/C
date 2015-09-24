#include "unp.h"
#include "declare.h"
#include <time.h>

int main( int argc, char** argv )
{
    int                 listenfd, connfd;
    socklen_t           len;
	struct sockaddr_in  servaddr, cliaddr;
    time_t              ticks;
    char                buff[MAXLINE];

    listenfd = Socket( AF_INET, SOCK_STREAM, 0 );
    bzero( &servaddr, sizeof(servaddr) );
    
    servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
    servaddr.sin_family      = AF_INET;
    servaddr.sin_port        = htons(13);
    
    /* °ó¶¨ */
    Bind( listenfd, (SA *)&servaddr, sizeof(servaddr) );

    /* ¼àÌý */
    Listen( listenfd, LISTENQ );

    /* ¼à¿Ø */
    for( ; ; )
    {
		len = sizeof(cliaddr);
        connfd = Accept( listenfd, (SA *)&cliaddr, &len );
		printf( "connect from %s:%d.\n listenfd=%d, connfd=%d\n", Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)), ntohs(cliaddr.sin_port), listenfd, connfd );
		ticks = time(NULL);
		snprintf( buff, sizeof(buff), "%.24s\r\n", ctime(&ticks) );
		if ( write( connfd, buff, strlen(buff) ) < 0 )
			err_sys( "write error" );
        close( connfd );
    }
}
