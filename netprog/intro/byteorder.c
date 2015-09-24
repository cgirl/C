/**
  确定主机字节的程序
  2015-1-19 20:53:01
  **/
#include "unp.h"
int main( int argc, char** argv )
{
	union{
		short s;
		char c[sizeof(short)];
	}un;

	un.s = 0x0102;
	printf( "%s:", CPU_VENDOR_OS );
	if ( un.c[0] == 1 && un.c[1] == 2 )
	{
		printf( "big-endian\n" );
	}
	else if ( un.c[0] == 2 && un.c[1] == 1 )
	{
		printf( "little-endian\n" );
	}
	else
	{
		printf( "unknown\n" );
	}

	printf( "sizeof(short) = %d\n", sizeof(short) );

	return 0;
}

