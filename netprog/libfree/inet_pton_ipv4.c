#include "unp.h"

const char* Inet_ntop( int family, const void* addrptr, char* strptr, size_t len )
{
	const u_char* p = (const u_char*)addrptr;
	if( family == AF_INET )
	{
		char tmp[INET_ADDRESTRLEN];
		
		snprintf( tmp, sizeof(tmp), "%d.%d.%d.%d", p[0], p[1], p[2], p[3] );
		
		if ( strlen(tmp) > len )
		{
			errno = ENOSPC;
			return NULL;
		}
		strcpy( strptr, tmp );
		return strptr;
	}

	errno = EAFNOSUPPORT;
	return NULL;
}


