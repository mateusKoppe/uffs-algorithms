All: start

start: compile
	./main

compile: main.o sllist.o stack.o
	gcc main.o sllist.o stack.o -o main

.SUFFIXES: .o .c

.c.o:
	gcc -c $*.c -Wall -O2 -ansi

order:
	rm -f *.o

clean: order
	rm -f main
