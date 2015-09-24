#ifndef _DECLARE_H_
#define _DECLARE_H_
//static void err_doit( int errnoflag, int level, const char *fmt, va_list ap );
void err_sys( const char *fmt, ... );
void err_quit( const char *fmt, ... );
void Listen( int fd, int backlog );
int Socket( int family, int type, int protocol );
void Bind( int fd, struct sockaddr* addr, socklen_t addrlen );
void Write( int fd, char* buff, int len );
int Accept( int fd, struct sockaddr* addr, socklen_t* addrlen );
char* Inet_ntop( int fd, const void* src, char* dst, socklen_t len );
ssize_t writen( int fd, const void* vptr, size_t n );
ssize_t readn( int fd, void* vptr, size_t n );
ssize_t Readline( int fd, void* vptr, size_t maxlen );
void Close( int fd );
void str_echo( int sockfd );
int Inet_pton( int family, char* strptr, void* addrptr );
void Connect( int fd, struct sockaddr* sa, socklen_t len );
pid_t Fork();
char* Fgets( char* ptr, int n, FILE* stream );
void Fputs( const char* ptr, FILE* stream );
void str_cli( FILE* fp, int sockfd );
void sig_chld( int signo );
Sigfunc* Signal( int signo, Sigfunc* func );
#endif //_DECLARE_H_
