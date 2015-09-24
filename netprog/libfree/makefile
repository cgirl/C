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

OBJ = inet_pton_ipv4.o inet_ntop_ipv4.o

libpton.so: $(OBJ)
	$(CC) -shared -o $@ $?
	mv $@ $(EXEDIR)
	rm *.o
	@echo "±‡“Î≥…π¶[$@]"
