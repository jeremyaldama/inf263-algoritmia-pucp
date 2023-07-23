all: solucion

solucion: main.o cola.o lse.o
	gcc main.o cola.o lse.o -o solucion

main.o: main.c cola.h lse.h
	gcc -c main.c

cola.o: cola.c cola.h
	gcc -c cola.c

lse.o: lse.c lse.h
	gcc -c lse.c