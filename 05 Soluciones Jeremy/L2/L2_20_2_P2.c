#include <stdio.h>

int calcularCantidadDeUnidadesEncontradas(int unidades[][6], int posIniX, int posIniY, int posX, int posY, int ladoV, int ladoH){
	if (posX>=ladoH || posY>=ladoV) return 0;
	
	int i, suma=0;
	
	if (posX==posIniX && posY==posIniY){
		for (i=0; i<ladoV; i++){
			if (unidades[posIniY][i]){
				suma++;	
			}
		}
	}
	
	for (i=0; i<posIniY; i++){
		if (unidades[i][posX]){
			suma++;
		}
	}
	
	for (i=posIniY+1; i<ladoV; i++){
		if (unidades[i][posX]){
			suma++;
		}
	}
		printf("%d\n", suma);
	
	return suma + calcularCantidadDeUnidadesEncontradas(unidades, posIniX, posIniY, posX+1, posY, ladoV, ladoH);
}

int main(){
	int posX=2, posY=3, ladoV=6, ladoH=6;	
	
	int unidades[][6] = {{0,0,0,1,0,1},
					     {0,0,1,0,0,0},
					     {0,1,0,0,0,1},
					     {1,0,0,0,0,0},
						 {0,1,0,0,0,0},
						 {0,0,0,0,1,0}};
	
	int numUnidadesEncontradas;
	numUnidadesEncontradas = calcularCantidadDeUnidadesEncontradas(unidades,posX, posY, posX, posY, ladoV, ladoH);
	printf("Unidadse encontradas: %d\n", numUnidadesEncontradas);
	return 0;
}
