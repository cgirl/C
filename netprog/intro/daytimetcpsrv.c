#include "unp.h"
#include "declare.h"
#include <time.h>

int main( int argc, char** argv )
{
    int listenfd, connfd;
    struct sockaddr_in sockaddr;
    time_t ticks;
    char buff[MAXLINE];

    bzero( &sockaddr, sizeof(sockaddr) );

    listenfd = socket( AF_INET, SOCK_STREAM, 0 );
    if ( listenfd < 0 )
    {
        err_sys( "socket error server" );
    }
    
    /* #define INADDR_ANY ((in_addr_t) 0x00000000)
     * INADDR_ANY-0.0.0.0,表示任意地址，不确定的地址，htonl将无符号长整型转换为网络字节顺序 */
    //sockaddr.sin_addr.s_addr = htonl( INADDR_ANY );
    sockaddr.sin_addr.s_addr = inet_addr( "192.168.16.121" );
    sockaddr.sin_family = AF_INET;
    /* htons将无符号短整型转换为网络字节顺序 */
    sockaddr.sin_port = htons(1122);
    
    /* 绑定 */
    if ( bind( listenfd, (SA *)&sockaddr, sizeof(sockaddr) ) < 0 )
    {
        err_sys( "bind error" );
    }

    /* 监听 */
    if ( listen( listenfd, LISTENQ ) < 0 )
    {
        err_sys( "listen error" );
    }

    /* 监控 */
    while( 1 )
    {
        connfd = accept( listenfd, (SA *)NULL, NULL );
        if ( connfd < 0 )
        {
            err_sys( "accept error" );
        }
        ticks = time( NULL );
        snprintf( buff, sizeof(buff), "%.24s\r\n", ctime(&ticks) );
        if ( write( connfd, buff, strlen(buff) ) < 0 )
        {
            err_quit( "write error" );
        }
        close( connfd );
    }
    return 0;
}
