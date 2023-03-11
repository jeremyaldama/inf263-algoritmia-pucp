all: solucion

solucion: main.o lse.o
	g++ main.o lse.o -o solucion

main.o: main.cpp
	g++ -c main.cpp

lse.o: lse.cpp
	g++ -c lse.cpp

clean:
	-rm main.o lse.o