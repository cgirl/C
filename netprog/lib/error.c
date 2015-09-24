#include "unp.h"
#include <syslog.h>
#include <stdarg.h>

int daemon_proc; /* set nonzero by deamon_init() */

static void err_doit( int errnoflag, int level, const char *fmt, va_list ap )
{
    int errno_save, n;
    char buf[MAXLINE+1];

    errno_save = errno; /* value caller might want printed */

#ifdef HAVE_VSNPRINTF
    vsnprintf( buf, MAXLINE, fmt, ap );
#else
    vsprintf( buf, fmt, ap );
#endif

    n = strlen(buf);
    printf( "=====%d======\n", errnoflag );
    if ( errnoflag )
    {
        snprintf( buf+n, MAXLINE, ":%s", strerror(errno_save) );
    }
    strcat( buf, "\n" );

    if (daemon_proc)
    {
        syslog( level, buf );
    }
    else
    {
        fflush( stdout );
        fputs( buf, stderr );
        fflush( stderr );
    }

    return ;
}

void err_sys( const char *fmt, ... )
{
    va_list ap;
    va_start( ap, fmt );
    err_doit( 1, LOG_ERR, fmt, ap );
    va_end( ap );
    exit(1);
}

void err_quit( const char *fmt, ... )
{
    va_list ap;
    va_start( ap, fmt );
    err_doit( 0, LOG_ERR, fmt, ap );
    va_end( ap );
    exit(1);
}
