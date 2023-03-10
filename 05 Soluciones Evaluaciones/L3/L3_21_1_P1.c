#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int **acciones;
	int canDias = 6;
	int canAcci = 7;
	acciones = (int**)malloc(sizeof(int*)*canDias);
	printf("Ingrese datos:\n");
	int i=0, j=0;
	for (i=0; i<canDias; i++){
		acciones[i] = (int*)malloc(sizeof(int)*canAcci);
		for (j=0; j<canAcci; j++){
			scanf("%d", &acciones[i][j]);
		}
	}
	
	return 0;
}
