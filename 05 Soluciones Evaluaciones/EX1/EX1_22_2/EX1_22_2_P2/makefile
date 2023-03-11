all: solucion

solucion: main.o pila.o lse.o
	gcc main.o pila.o lse.o -o solucion

main.o: main.c
	gcc -c main.c

lse.o: lse.c lse.h
	gcc -c lse.c

pila.o: pila.c pila.h lse.h
	gcc -c pila.c

