//Estrategia: recursion
#include <stdio.h>
#define COL 5

int llenarAnaquel(int anaquel[][COL], int fila, int colum, int productos, int iniFila, int colExtr,
				int impresiones, int nFil){
	if (productos==0) return 0;

	int i,j;
	
	if (nFil%2==0){
		for (i=colExtr,j=0; j<impresiones; i++,j++){
			if (productos!=0 && !anaquel[iniFila][i]){
				anaquel[iniFila][i] = 5;
				productos--;	
			}
		}
	}
	else{
		for (i=colExtr,j=0; j<impresiones; i++,j++){
			if (productos!=0 && !anaquel[nFil][i]){
				anaquel[nFil][i] = 5;
				productos--;	
			}
		}
	}
	productos = llenarAnaquel(anaquel, fila, colum, productos, iniFila+1, colExtr-1, impresiones+2, nFil+1);
	
	return productos;
}

int main(){
	int fila=5, colum=5, productos=16;
	
	int anaquel[][5] = {{0,0,0,0,0},
						{0,0,0,0,0},
						{0,0,0,1,0},
						{0,1,0,0,0},
						{0,0,0,0,0}};
							
	int cantProdOrdenadosFin, centroX=colum/2;
	//SI EL CENTROX SALE CON INDICE PAR SON COLUMNAS IMPARES
	//SI EL CENTROX SALE CON INDICE IMPAR SON COLUMNAS PARES
	int impresiones = centroX%2==0? 1:2; 						      //indice
	cantProdOrdenadosFin = llenarAnaquel(anaquel, fila, colum, productos, 0, centroX, impresiones, 0);
	
	int i, j;
	for (i=0; i<5; i++){
	
		for (j=0; j<5; j++) printf("%d ", anaquel[i][j]);
		printf("\n");
	}
	//SI LLEGÓ A 0 ES PORQUE SE COMPLETARON DE LLENAR TODOS LOS PRODUCTOS
	if (cantProdOrdenadosFin==0){
		printf("Si es posible ordenar los productos en el anaquel\n");
	}
	else{
		printf("No es posible utilizar este anaquel para la cantidad de productos solicitados\n");
	}
	return 0;
}
