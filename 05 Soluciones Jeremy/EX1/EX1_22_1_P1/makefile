all: solu

solu: main.o pila.o
	gcc -o solu main.o pila.o

main.o: main.c
	gcc -c main.c

pila.o: pila.c pila.h
	gcc -c pila.c

clean:
	-rm main.o pila.o