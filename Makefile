all: sort.c methods.h methods.c
	gcc -Wall -g -o sort.o sort.c methods.c

run :
	./sort.o
