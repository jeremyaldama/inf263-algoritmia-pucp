//FUERZA BRUTA
#include <stdio.h>
#include <math.h>

int n=8;
int M=4;//maximo de tipos de herramientas
int P=19;//presupuesto

void cargaBin(int* arreglo, int numero) {
	int bit;
	for (bit = 0; bit < n; bit++) {
		arreglo[n - 1 - bit] = numero & 1;//si los dos bits son 1 -> es 1
		numero >>= 1;//muevo 1 bit a la izquierda
	}
}

int main(){//si elige un tipo de herr., debe adq. todas las q necesita d ese tipo
	
	int costoTotal, canHerr;			//precio, can. renovar
	int herramienta[][2] = {{4, 3},{5,2},{4,1},{2,1},{6,3},{3,3},{4,2},{1,4}};
	int cromo[n];
	int comb = (int)pow(2, n);
	int i, j, canTipos;
	int nsol=0,soluciones[comb];// no sé cuántas soluciones habrán, pero
								//en el peor caso todas serán correctas y por
								//eso le doy el tamaño de las combinaciones
	
	for (i=0; i<comb; i++){
		cargaBin(cromo, i);
		costoTotal = 0;
		canTipos = 0;
		for (j=0; j<n; j++){
			if (cromo[j]){
				costoTotal += herramienta[j][0]*herramienta[j][1];
				canTipos++;
			}
		}
		//la condicional para escoger las que cumplen las condiciones pedidas
		if (canTipos<=M && costoTotal<=P){
			soluciones[nsol] = i;
			nsol++;
		}
	}
	//impresion de las soluciones que no exceden el presupuesto P y que
	//las sumas de tipos de herramientas no son mayores a M
	for (i=0; i<nsol; i++){
		cargaBin(cromo, soluciones[i]);
		costoTotal=canTipos=0;
		for (j=0; j<n; j++){
			if (cromo[j]){
				printf("%d ", j+1);
				canTipos++;
				costoTotal += herramienta[j][0]*herramienta[j][1];
			}
		}
		printf("\n");
		printf("Monto Total: %d\n", costoTotal);
		printf("Cantidad de tipos de herramientas: %d\n\n\n", canTipos);
	}
	
	return 0;
}
