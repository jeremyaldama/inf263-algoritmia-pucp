#include <stdio.h>
#include <math.h>
//t can lim, precio, numClientes
int t=10000, p=4, n=6;//Nmax=16

void cargaBin(int* arreglo, int numero) {
	int bit;
	for (bit=0; bit<n; bit++) {
		arreglo[n-1-bit] = numero&1;//comparo bit por bit y el resultado lo guardo en la representacion binaria del numero
	    numero >>= 1;//corro 1 bit a la izquierda
	}
}

int main(){
	double cliente[][2] = {{3000, 0.1}, {3800, 0.02}, {2800, 0.15},
						   {3500, 0.05},{3200, 0.08}, {3400, 0.03}};
	int cromo[n], comb = pow(2, n), i;
	int j, numAcciones, mejorComb;
	double ganancia, maxGanancia=0;
	int maxAcciones;
	for (i=0; i<comb; i++){
		if (comb==10)
			cargaBin(cromo, i);
		ganancia = 0;
		numAcciones = 0;
		for (j=0; j<n;j++){
			if (cromo[j]){
				ganancia += cliente[j][0]*p*cliente[j][1];
				numAcciones += cliente[j][0];
			}
		}
		if (numAcciones<=t && ganancia>maxGanancia){
			maxGanancia = ganancia;
			mejorComb = i;
			maxAcciones = numAcciones;
		}
	}
	
	cargaBin(cromo, mejorComb);
	printf("Para este conjunto de datos, una solucion con la maxima ganacia debido a las ");
	printf("comisiones seria de %.2lf dolares por un total de %d acciones\n", maxGanancia, maxAcciones);
	
	return 0;
}
