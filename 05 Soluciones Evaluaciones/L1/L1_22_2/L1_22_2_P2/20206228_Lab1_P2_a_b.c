//FUERZA BRUTA
#include <stdio.h>
#include <math.h>
#include <string.h>

void cargaBin(int* arreglo, int numero, int n) {
	int bit;
	for (bit = 0; bit < n; bit++) {
		arreglo[n - 1 - bit] = numero & 1;//si los dos bits son 1 -> es 1
		numero >>= 1;//muevo 1 bit a la izquierda
	}
}

int main(){
	FILE*arch = fopen("datos_P2.txt","r");
	char letra[10], palabra[10];
	int i=0;
	fscanf(arch,"%s",palabra);
	while (1){
		fscanf(arch," %c",&letra[i]);
		if (feof(arch)) break;
		i++;
	}
	
	int n = i, j, k;
	int cromo[n];
	int comb = pow(2, n);
	char palabraFormada[n];
	
	for (i=0; i<comb; i++){
		cargaBin(cromo, i, n);
		k=0;
		//reinicio el arreglo para que no quede ninguna basurita
		for (j=0; j<n; j++) palabraFormada[j] = 0;
		
		for (j=0; j<n; j++){
			if (cromo[j]){
				//voy asignandole cada letra de acuerdo al cromo 
				//a mi arreglo
				palabraFormada[k] = letra[j];
				k++;
			}
		}
		
		if (strcmp(palabraFormada, palabra)==0){
			printf("Posible combinacion: ");
			for (j=0; j<n; j++){
				if (cromo[j]){
					printf("%d ", j+1);
				}
			}
			break;
		}
	}
	return 0;
}
