#include "unp.h"
void err_sys( const char *fmt, ... );
void err_quit( const char *fmt, ... );

int Accept( int fd, struct sockaddr* addr, socklen_t* addrlen )
{
	int n;
again:
	if ( ( n = accept(fd, addr, addrlen ) ) < 0 ){
#ifdef ERROTO
		if ( errno == ERROTO || errno = ECONNABORTED )
#else
		if ( errno == ECONNABORTED )
#endif
			goto again;
		else
			err_quit("write error");
	}

	return n;
}

void Bind( int fd, const struct sockaddr* addr, socklen_t addrlen )
{
	if ( bind(fd, addr, addrlen) < 0 )
		err_sys("bind error!");
}

void Close( int fd )
{
	if ( close(fd) < 0 )
		err_sys("close error!");
}

void Connect( int fd, struct sockaddr* sa, socklen_t len )
{
	if ( connect(fd, sa, len) < 0 )
		err_sys("connect error!");
}

char* Fgets( char* ptr, int n, FILE* stream )
{
	char* vptr;
	if ( ( (vptr = fgets(ptr, n, stream)) == NULL ) && ( ferror(stream) ) )
		err_sys("fgets error!");

	return vptr;
}

void Fputs( const char* ptr, FILE* stream )
{
	if ( fputs( ptr, stream ) == EOF )
		err_sys("fputs error!");
}

pid_t Fork()
{
	pid_t pid;
	if ( ( pid = fork() ) == -1 )
		err_sys("fork error!");
	return pid;
}

char* Inet_ntop( int fd, const void* src, char* dst, socklen_t len )
{
	if ( inet_ntop(fd, src, dst, len) == NULL )
		err_quit("write error");

	return dst;
}

void Listen( int fd, int backlog )
{
	char* ptr;
	if ( (ptr = getenv("LISTENQ")) != NULL )
		backlog = atol(ptr);
	if ( listen( fd, backlog ) < 0 )
		err_sys("listen error!");
}

int Socket( int family, int type, int protocol )
{
	int n;
	if ( (n=socket(family, type, protocol)) < 0 )
		err_sys("socket error!");
	return n;
}


void Write( int fd, char* buff, int len )
{
	if ( write(fd, buff, len) < 0 )
		err_quit("write error");
}
