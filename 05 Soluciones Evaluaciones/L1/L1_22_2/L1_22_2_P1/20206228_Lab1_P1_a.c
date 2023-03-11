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
	
	int costoTotal;			//precio, can. renovar
	int herramienta[][2] = {{4, 3},{5,2},{4,1},{2,1},{6,3},{3,3},{4,2},{1,4}};
	int cromo[n];
	int comb = (int)pow(2, n);
	int i, j, canHerr, maxCanHerr=0, mejorSol, canTipos;
	
	for (i=0; i<comb; i++){
		cargaBin(cromo, i);
		costoTotal = 0;
		canHerr = 0;
		canTipos = 0;
		for (j=0; j<n; j++){
			if (cromo[j]){
				costoTotal += herramienta[j][0]*herramienta[j][1];
				canHerr += herramienta[j][1];
				canTipos++;
			}
		}
		//la condicional para escoger la mejor combinacion pedida
		if (canTipos<=M && costoTotal<=P && canHerr>=maxCanHerr){
			maxCanHerr = canHerr;
			mejorSol = i;
		}
	}
	//impresion de la mejor solucion
	cargaBin(cromo, mejorSol);
	costoTotal=canHerr=0;
	for (j=0; j<n; j++){
		if (cromo[j]){
			printf("%d ", j+1);
			canHerr += herramienta[j][1];
			costoTotal += herramienta[j][0]*herramienta[j][1];
		}
	}
	printf("\n\n");
	printf("Monto Total: %d\n\n", costoTotal);
	printf("Cantidad de herramientas: %d\n", canHerr);
	return 0;
}
