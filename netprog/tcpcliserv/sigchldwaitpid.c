#include "unp.h"

/**
  终极正确版本
  时间：2015-2-27 14:41:18
  **/
void sig_chld( int signo )
{
	pid_t pid;
	int stat;

	while( ( pid = waitpid( -1, &stat, WNOHANG ) ) > 0 )
		printf( "chlid %d teminated!\n", pid );

	return ;
}
