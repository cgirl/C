#include "unp.h"
#include "declare.h"

void str_echo( int sockfd )
{
	ssize_t n;
	char line[MAXLINE];

	while(1)
	{
		if ( ( n = Readline(sockfd, line, MAXLINE) ) == 0 )
		{
			printf("K.O\n");
			return;
		}
		//printf("¶ÁÈ¡µ½%d¸ö×Ö·û£º%s\n", n, line);
		Write(sockfd, line, n);
	}
}
