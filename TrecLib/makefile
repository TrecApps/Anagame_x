
# Set the Compiler
CC=g++

ARGS= -c -Wall -Werror -Wno-sign-compare -fPIC

build:
	$(CC) $(ARGS) *.cpp
	$(CC) -shared -o ../$(OUTDIR)/TrecLib.so *.o

clean:
	rm -f *.o core

rebuild: clean build

