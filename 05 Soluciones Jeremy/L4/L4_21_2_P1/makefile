all: sol

sol: main.o abb.o cola.o
	gcc -o sol main.o abb.o cola.o

main.o: main.c 	abb.h cola.h
	gcc -c main.c

cola.o: cola.c cola.h abb.h
	gcc -c cola.c

abb.o: abb.c abb.h
	gcc -c abb.c

clean:
	-rm main.o abb.o cola.o
