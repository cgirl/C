#include "unp.h"
#include "declare.h"

/**
  静态(局部/全局)变量：作用域(定义函数内/所有函数)，生命周期整个程序，只初始化一次，以后值保留直到进程结束
  **/
static int read_cnt;
static char* read_ptr;
static char read_buf[MAXLINE];

/**
  静态函数：只在本文件中调用，其他文件无法调用，其他文件即使和本文件的函数同名也是允许的
  时间：2015-2-13 15:46:46
  功能：每次从文件描述符中读出一个字符存到静态全局变量中
  章节：5.3 5.4
  主调：netprog/lib/readline.c|readline
  **/
static ssize_t my_read( int fd, char* ptr )
{
again:
	if ( read_cnt <= 0 )
	{
		if ( ( read_cnt = read(fd, read_buf, sizeof(read_buf) ) ) < 0 )
		{
			if ( errno == EINTR )
			{
				printf("EINTR\n");
				goto again;
			}
			return -1;
		}
		else if ( read_cnt == 0 )
			return 0;
		read_ptr = read_buf;
	}

	read_cnt--;
	*ptr++ = *read_ptr++;

	return 1;
}

/**
  时间：2015-2-13 15:35:25
  功能：逐个字符读取一行字符串，最多只能读取maxlen个值
  章节：5.3 5.5
  主调：netprog/lib/readline.c|Readline
  **/
ssize_t readline( int fd, void* vptr, size_t maxlen )
{
	ssize_t n, rc;
	char c, *ptr;

	ptr = vptr;
	for ( n = 1; n < maxlen; n++ )
	{
		if ( ( rc = my_read(fd, &c) ) == 1 )
		{
			*ptr++ = c;
			if ( c == '\n' )
				break;
		}
		else if ( rc == 0 )
		{
			*ptr = 0;
			return n - 1;
		}
		else
		{
			return -1;
		}
	}

	*ptr = 0;
	return n;
}

ssize_t Readline( int fd, void* vptr, size_t maxlen )
{
	ssize_t n;
	
	if ( ( n = readline(fd, vptr, maxlen) ) < 0 )
		err_sys( "readline error" );

	return n;
}
