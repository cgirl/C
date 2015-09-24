#include "unp.h"
#include "declare.h"

void str_cli( FILE* fp, int sockfd )
{
	char sendline[MAXLINE], recvline[MAXLINE];
	
	while( Fgets( sendline, MAXLINE, fp ) != NULL )
	{
		Write( sockfd, sendline, 1 );
		sleep(1);
		Write( sockfd, sendline+1, strlen(sendline)-1 );

		if ( Readline( sockfd, recvline, MAXLINE ) == 0 )
			err_sys( "str_cli:server terminated prematurely!" );

		Fputs( recvline, stdout );
	}
}
