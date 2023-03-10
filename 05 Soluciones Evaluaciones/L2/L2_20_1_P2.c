#include <stdio.h>

int ubicarProductos(int tablero[][5], int prod, int n, int m, 
					 int max, int min, int nFI, int nFF){
	if (nFI>nFF || min>max) return 0;
	
	int i, can=0, minCol=max;
	//columnas de la primera fila
	for (i=0; i<minCol; i++){
		if (tablero[nFI][i]==0){
			tablero[nFI][i] = 5;
			can++;
		}
		if (tablero[nFF][i]==0){
			tablero[nFF][i] = 5;
			can++;
		}
	}
	return can+ubicarProductos(tablero, prod, n, m, max-1, min, 
							  nFI+1, nFF-1);
}

int main(){
	int m=6, n=5, max=5, min=3, prod=20;
	int tablero[6][5] = {{0,0,0,1,0},
						{0,0,0,0,0},
						{1,0,0,0,0},
						{0,1,0,0,0},
						{0,0,0,0,0},
						{0,1,0,0,0}};
	int ubiDis;
	ubiDis = ubicarProductos(tablero, prod, n, m, max, min, 0, m-1);
	int i, j;
	for (i=0; i<m; i++){
		for (j=0;j<n; j++)
			printf("%d ", tablero[i][j]);
		printf("\n");
	}
	return 0;
}
