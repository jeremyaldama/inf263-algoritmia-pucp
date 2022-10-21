#include <stdio.h>

void recopilarMonticulos(int monticulo[][5], int numF, int numC, int filaInicio, int colInicio){
	if (filaInicio>=numF || colInicio>=numC){
		printf("%d ", monticulo[numF][numC]);
		return;	
	}
	
	int i;
	for (i=colInicio; i<numC-1; i++) printf("%d ",monticulo[filaInicio][i]);
	
	for (i=filaInicio; i<numF-1; i++) printf("%d ",monticulo[i][numC-1]);
	
	for (i=numC-1; i>colInicio; i--) printf("%d ",monticulo[numF-1][i]);
	
	for (i=numF-1; i>filaInicio; i--) printf("%d ",monticulo[i][colInicio]);
	
	recopilarMonticulos(monticulo, numF-1, numC-1, filaInicio+1, colInicio+1);
}

int main(){
	int numF, numC;
	printf("Ingrese dimensiones de la matriz: ");
	scanf("%d %d",&numF,&numC);
	int i, j, cont=1;
	int monticulo[numF][numC];
	for (i=0; i<numF; i++)
		for (j=0; j<numC; j++){
			monticulo[i][j] = cont++;
		}
	
	recopilarMonticulos(monticulo, numF, numC, 0, 0);
}
