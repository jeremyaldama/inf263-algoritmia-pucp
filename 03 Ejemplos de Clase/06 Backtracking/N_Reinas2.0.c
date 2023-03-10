#include <stdio.h>
#include <stdlib.h>
#define N 6

int cont;

void llenar_tablero (int tablero[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) 
			tablero[i][j] = 0;	
}

void imprimir_tablero (int tablero[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) 
			printf("%d ",tablero[i][j]);
		printf("\n");
	}
}

int es_valido (int tablero[N][N], int col, int fil) {
	int i, j;
	for (i = 0; i < col; i++) {
		if (tablero[fil][i] == 1)
			return 0;
	}
	for (i = col-1, j = fil-1; i >= 0 && j >= 0; i--, j--) {
		if (tablero[j][i] == 1)
			return 0;
	}
	for (i = col-1, j = fil+1; i >= 0 && j < N; i--, j++) {
		if (tablero[j][i] == 1)
			return 0;
	}
	return 1;
}

int resolver_N_reinas (int tablero[N][N], int col) {
	int i;
	if (col == N) {
		cont++;
		printf("Solucion %d:\n",cont);
		imprimir_tablero(tablero);
		return 0;
	}
	for (i = 0; i < N; i++) {
		if (es_valido(tablero,col,i)) {
			tablero[i][col] = 1;
			if (resolver_N_reinas(tablero,col+1))
				return 1;
			else
				tablero[i][col] = 0;	
		}
	}
	return 0;
}

void main () {
	int tablero[N][N];
	llenar_tablero(tablero);
	resolver_N_reinas(tablero,0);
	printf("Hay %d soluciones\n",cont);
}
