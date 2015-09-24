#include "unp.h"
#include "declare.h"

void str_cli( FILE* fp, int sockfd )
{
	char sendline[MAXLINE], recvline[MAXLINE];

	while( Fgets(sendline, MAXLINE, fp) != NULL )
	{
		//printf("1111:[%s]\n", sendline);
		Write( sockfd, sendline, strlen(sendline) );

		//printf("=======\n");
		if ( Readline(sockfd, recvline, MAXLINE ) == 0 )
			err_quit("str_cli: server terminated prematurely!");
		//printf("11=======\n");

		//printf("222:%s\n", recvline);
		Fputs(recvline, stdout);
		//*sendline = '\0';
		//*recvline = '\0';
	}
}
