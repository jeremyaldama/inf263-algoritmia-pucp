//Técnica aplicada: Divide y Vencerás
#include <stdio.h>
#include <stdlib.h>

int sumarColumna(int**terreno, int filaI, int filaF, int col, int*masAlta){
	int i, suma=0, masAltaAux=-1;
	for (i=filaI; i<=filaF;i++){
		suma += terreno[i][col];
		if (terreno[i][col]>masAltaAux){
			masAltaAux = terreno[i][col];
		}
	}
	*masAlta = masAltaAux;
	return suma;
}

int hallarPotenciaMasAlta(int**terreno, int filaI, int filaF, int colI, int colF, int*potMasAlta){
	if (colI==colF){
		return colI;
	}
	int sumColIzq, sumColDer, sumColMid, colMid = (colI+colF)/2;
	int masAltaIz, masAltaDer, masAltaMid;
	sumColIzq = sumarColumna(terreno, filaI, filaF, colMid-1, &masAltaIz);
	sumColDer = sumarColumna(terreno, filaI, filaF, colMid+1, &masAltaDer);
	sumColMid = sumarColumna(terreno, filaI, filaF, colMid, &masAltaMid);
	
	if (sumColDer>sumColIzq && sumColDer>sumColMid){
		*potMasAlta = masAltaDer;
		return hallarPotenciaMasAlta(terreno, filaI, filaF, colMid+1, colF, potMasAlta);
		
	}
	else if (sumColIzq>sumColDer && sumColIzq>sumColMid){
		*potMasAlta = masAltaIz;
		return hallarPotenciaMasAlta(terreno, filaI, filaF, colI, colMid-1, potMasAlta);
	}
	else{
		*potMasAlta = masAltaMid;
		return hallarPotenciaMasAlta(terreno, filaI, filaF, colMid, colMid, potMasAlta);
	}
}

int main(){
	int **terreno;
	int fila, columna;
	printf("Ingrese columnas y filas: ");
	scanf("%d %d", &columna, &fila);
	terreno = (int**)malloc(sizeof(int*)*fila);
	int i,j;
	for (i=0; i<fila; i++){
		terreno[i] = (int*)malloc(sizeof(int)*columna);
		for (j=0; j<columna; j++){
			scanf("%d", &terreno[i][j]);
		}
	}
	//Copiar y pegar datos
	//1er cuadro: 
	/*7 10
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 1 1 1
	  0 0 0 0 1 2 2
	  0 0 0 0 1 2 8
	  0 0 0 0 1 2 2
	  0 0 0 0 1 1 1
	  0 0 0 0 0 0 0
	*/
	/*7 8
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 1 1 1 0 0 0
	  0 1 2 1 0 0 0
	  0 1 1 1 0 0 0
	  0 0 0 0 0 0 0 	
	*/
	int MasAltaCol, PotenciaMasAlta;
	MasAltaCol = hallarPotenciaMasAlta(terreno, 0, fila-1, 0, columna-1, &PotenciaMasAlta);
	printf("Para este juego de datos la potencia mas alta de bomba es %d, y la columna "
			"donde se ubica es %d", PotenciaMasAlta, MasAltaCol);
	return 0;
}
