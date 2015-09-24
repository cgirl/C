#include "unp.h"

ssize_t readn( int fd, void* vptr, size_t n )
{
	ssize_t nleft, nread;
	char* ptr;

	ptr = vptr;
	nleft = n;
	
	memset( ptr, 0x00, nleft );

	while( nleft > 0 )
	{
		//printf("readn:%d\n", nleft);
		if ( ( nread = read( fd, ptr, nleft ) ) < 0 )
		{
			if ( errno == EINTR ){
				//printf("EINTR\n");
				nread = 0;
			}
			else{
				//printf("return -1\n");
				return -1;
			}
		}
		else if ( nread == 0 )
		{
			printf("nread=0\n");
			break;
		}
		else if ( *(ptr+nread-1) == '\n')
		{
			//printf("nread=%d,ptr=%s\n", nread, ptr);
			nleft -= nread;
			ptr += nread;
			//printf("»Ø³µ\n");
			break;
		}
		/*printf("nread=%d,ptr=%s\n", nread, ptr);
		nleft -= nread;
		ptr += nread;*/
	}
	return n-nleft;
}
