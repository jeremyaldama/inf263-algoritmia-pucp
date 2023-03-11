all: 1

1: main.o pila.o
	gcc main.o pila.o -o solu

main.o: main.c
	gcc -c main.c

pila.o: pila.c
	gcc -c pila.c

clean:
	-rm main.o pila.o