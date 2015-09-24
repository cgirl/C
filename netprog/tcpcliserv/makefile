.SUFFIX: .c .o
.c.o:
	$(CC) $(INCL) -g -c $*.c -Wall

BIT = $(shell getconf LONG_BIT)
BIT32 = 32
BIT64 = 64

ifeq ($(BIT),$(BIT32))
	CC = cc -m32
else 
	CC = cc -m64
endif

#OBJ = daytimetcpcli.o daytimetcpcliv6.o daytimetcpsrv.o byteorder.o

LIBS    = -ltool -lpton

EXEDIR = $(HOME)/netprog/bin

INCL = -I.\
	   -I$(HOME)/netprog/include

LIBSDIR = -L.\
		  -L$(HOME)/netprog/libs


tcpserv01: tcpserv01.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
tcpserv02: tcpserv02.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
tcpserv03: tcpserv03.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
tcpcli01: tcpcli01.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
tcpcli04: tcpcli04.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
tcpserv04: tcpserv04.o sigchldwaitpid.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
tcpcli11: tcpcli04.o str_cli11.o 
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
tcpserv08: tcpserv04.o sigchldwaitpid.o str_echo08.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
