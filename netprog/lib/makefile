.SUFFIX: .c.o
.c.o:
	$(CC) $(INCL) -fPIC -g -c $*.c -Wall

BIT = $(shell getconf LONG_BIT)
BIT32 = 32
BIT64 = 64

#ifeq ( $(BIT), $(BIT32) )
	CC = cc -m32
#else 
#	CC = cc -m64
#endif

INCL = -I.\
	   -I$(HOME)/netprog/include

EXEDIR = $(HOME)/netprog/libs

OBJ = error.o sock_ntop.o wrapsock.o sockfd_to_family.o str_echo.o readn.o writen.o readline.o str_cli.o signal.o sigchldwait.o

libtool.so: $(OBJ)
	$(CC) -shared -o $@ $?
	mv $@ $(EXEDIR)
	rm *.o
	@echo "����ɹ�[$@]"
