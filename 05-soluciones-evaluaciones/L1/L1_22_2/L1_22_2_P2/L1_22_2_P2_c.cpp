//FUERZA BRUTA
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

using namespace std;

void carga_bin(int* arreglo, int numero, int n) {
	int bit;
	for (bit = 0; bit < n; bit++) {
		arreglo[n - 1 - bit] = numero & 1;
		numero >>= 1;
	}
}

int main(){
	ifstream arch("datos_P2.txt");
	char letra[10], palabra[10];
	int i=0;
	arch>>palabra;
	while (1){
		arch>>letra[i];
		if (arch.eof()) break;
		i++;
	}
	
	int n = i, j, k;
	int cromo[n];
	int comb = pow(2, n);
	char palabraFormada[n];
	int nPal = strlen(palabra);
	int esCorrecta;
	
	for (i=0; i<comb; i++){
		carga_bin(cromo, i, n);
		k=0;
		for (j=0; j<n; j++) palabraFormada[j] = 0;
		esCorrecta=1;
		
		for (j=0; j<n; j++){
			if (cromo[j]){
				palabraFormada[k] = letra[j];
				k++;
			}
		}
		
		if (k==nPal){
			for (j=0; j<nPal; j++){
				for (k=0; k<nPal; k++){
					if (palabra[j] == palabraFormada[k]){
						break;
					}
				}
				if (k>=nPal) esCorrecta=0;
			}
		}
		else esCorrecta=0;
		
		if (esCorrecta){
			printf("Posible combinacion: ");
			for (j=0; j<n; j++){
				if (cromo[j]){
					printf("%d ", j+1);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
