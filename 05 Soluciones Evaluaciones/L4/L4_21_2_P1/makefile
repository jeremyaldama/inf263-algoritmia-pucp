all: sol

sol: main.o abb.o cola.o
	gcc main.o abb.o cola.o -o sol

main.o: main.c
	gcc -c main.c

cola.o: cola.c
	gcc -c cola.c

abb.o: abb.c
	gcc -c abb.c

clean:
	-rm main.o abb.o cola.o
