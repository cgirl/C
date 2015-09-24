#include "unp.h"

ssize_t writen( int fd, const void* vptr, size_t n )
{
	ssize_t nleft, nwrite;
	const char* ptr;

	ptr = vptr;
	nleft = n;

	while( nleft > 0 )
	{
		if ( ( nwrite = write( fd, ptr, nleft ) ) < 0 )
		{
			if ( errno == EINTR )
				nwrite = 0;
			else
				return -1;
		}
		else if ( nwrite == 0 )
		{
			break;
		}
		nleft -= nwrite;
		ptr += nwrite;
	}
	return n;
}
