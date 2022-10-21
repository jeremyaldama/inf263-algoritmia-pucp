//Estrategia: Fuerza Bruta
#include <stdio.h>
#include <math.h>
void cargaCromo(int i,int cromo[]);
int n = 7, MPxH = 23;

int main(){
	int i, k, pago,mphTotal,pagoTotal,pagoMenor = 9999999;
	int cromo[n];
	int rol[] = {2, 1, 3, 1, 3, 2, 3};
	int mph[] = {8, 6, 13, 5, 10, 9, 14};
	int bpm[] = {4, 6, 2, 7, 2, 3, 0};
	int opciones = (int)pow(2, n);
	int rpta[n];
	for (i = 0; i < opciones; i++){
		cargaCromo(i, cromo);
		mphTotal = 0;
		pagoTotal = 0;
		for (k = 0; k < n; k++){
			if (cromo[k]){
				if (rol[k] == 1) pago = 16 + bpm[k]*mph[k];
				else if (rol[k] == 2) pago = 19 + bpm[k]*mph[k];
				else pago =  22 + bpm[k]*mph[k];
				mphTotal += mph[k];
				pagoTotal += pago;
			}
		}
		if (mphTotal >= MPxH && pagoTotal <= pagoMenor){
			pagoMenor = pagoTotal;
			cargaCromo(i, rpta);
		}
	}
	printf("Trabajadores seleccionados: ");
	for (i = 0; i < n; i++) if (rpta[i]) printf("%d ", i+1);
	printf("Costo minimo: %d\n",pagoMenor);
	return 0;
}

void cargaCromo(int i,int cromo[]){
	int k, res;
	for (k = 0; k < n; k++) cromo[k] = 0;
	k = 0;
	while (i > 0){
		res = i % 2;
		i /= 2;
		cromo[k] = res;
		k++;
	}
}
