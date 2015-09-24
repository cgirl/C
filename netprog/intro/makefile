.SUFFIX: .c .o
.c.o:
	$(CC) $(INCL) -g -c $*.c -Wall

BIT = $(shell getconf LONG_BIT)
BIT32 = 32
BIT64 = 64

#ifeq ( $(BIT), $(BIT32) )
	CC = cc -m32
#else 
#	CC = cc -m64
#endif
#OBJ = daytimetcpcli.o daytimetcpcliv6.o daytimetcpsrv.o byteorder.o

LIBS    = -ltool -lpton

EXEDIR = $(HOME)/netprog/bin

INCL = -I.\
	   -I$(HOME)/netprog/include

LIBSDIR = -L.\
		  -L$(HOME)/netprog/libs


daytimetcpcli: daytimetcpcli.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"

15011802: daytimetcpcliv6.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"

15011803: daytimetcpsrv.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
	
15011901: byteorder.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"

daytimetcpsrv1: daytimetcpsrv1.o
	$(CC) -o $@ $? $(INCL) $(LIBSDIR) $(LIBS)
	mv $@ $(EXEDIR)
	rm *.o
	@echo "编译成功[$@]"
