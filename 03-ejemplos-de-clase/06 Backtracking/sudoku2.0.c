#include <stdio.h>
#include <stdlib.h>

#define N 9

void leer_tabla (int tabla[N][N]) {
	FILE *arch;
	arch = fopen("sudoku.txt","r");
	int i, j;
	while (1) {
		fscanf(arch,"%d",&i);
		if (feof(arch)) break;
		j = 0;
		while (fgetc(arch) != '\n') {
			fscanf(arch,"%d",&tabla[i][j]);
			j++;
		}
	}
}

void imprimir_tabla (int tabla[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j%3 == 0 && j != 0) printf("| ");
			printf("%d ",tabla[i][j]);
		}
		if ((i+1)%3 == 0 && i != 0 && i!= N-1) printf("\n---------------------");				
		printf("\n");
	}
}

int es_solucion (int tabla[N][N], int *fil, int *col) {
	int i, j;	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			/* si hay huecos en nuestro sudoku tenemos que guardar
			estas posiciones para evaluarlas */
			if (tabla[i][j] == 0) {
				(*fil) = i;
				(*col) = j;
				return 0;
			}
		}
	}
	/* si todo nuestro sudoku esta lleno es solucion*/
	return 1;
}

int es_valido (int tabla[N][N], int fil, int col, int num) {
	int i, j;
	/* buscamos en toda la columna*/
	for (i = 0; i < N; i++) {
		if (tabla[fil][i] == num)
			return 0;
	}
	/* buscamos en toda la fila*/
	for (j = 0; j < N; j++) {
		if (tabla[j][col] == num)
			return 0;
	}
	int b_fil = fil/3;
	int b_col = col/3;
	/* buscamos en el cuadradito 3x3 */
	for (i = 3*b_fil; i <= (3*b_fil+2); i++) {
		for (j = 3*b_col; j <= (3*b_col+2); j++) {
			if (tabla[i][j] == num)
				return 0;
		}
	}
	/* si el numero no se encuentra en ninguna posicion evaluada
	entonces dichas posiciones evaluadas son validas */
	return 1;
}

int sudoku (int tabla[N][N]) {
	int col, fil;
	/* primero verificamos que todas las celdas del sudoku esten llenas */
	if (es_solucion(tabla,&fil,&col)) /* en caso encuentre una casilla vacia (0)
	entonces necesitamos dicha posicion para evaluarla */ 
		return 1; 
	int i;
	for (i = 1; i <= N; i++) {
		/* si el numero i es valido (ver funcion) colocamos 
		en nuestro sudoku dicho numero */
		if (es_valido(tabla,fil,col,i)) {
			tabla[fil][col] = i;
			/* recursivamente verificamos el nuevo sudoku (con el numero
			insertado) */
			if (sudoku(tabla)) 
				return 1;
				/* si el nuevo sudoku no puede forma una posible solucion
				entonces tenemos que volver a colocar 0 en la posicion que
				obtuvimos inicialmente */
			tabla[fil][col] = 0;
		}
	}
	return 0;	
}

void main () {
	int tabla[N][N];
	leer_tabla(tabla);
	imprimir_tabla(tabla);
	printf("\n=====================\n\n");
	sudoku(tabla);
	imprimir_tabla(tabla);
}
