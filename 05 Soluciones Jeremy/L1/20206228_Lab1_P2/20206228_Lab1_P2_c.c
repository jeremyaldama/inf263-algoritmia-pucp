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
	int nPal = strlen(palabra);
	int esCorrecta;
	
	for (i=0; i<comb; i++){
		cargaBin(cromo, i, n);
		k=0;
		for (j=0; j<n; j++) palabraFormada[j] = 0;
		esCorrecta=1;
		
		for (j=0; j<n; j++){
			if (cromo[j]){
				palabraFormada[k] = letra[j];
				k++;
			}
		}
		
		//el siguiente if es para obtener todas las palabras gol, pero que
		//están con las letras desordenadas, no necesariamente G O L tal cual
		//puede ser O G L, etc
		if (k==nPal){
			for (j=0; j<nPal; j++){//recorro cada letra de la palabra GOL
				for (k=0; k<nPal; k++){//recorro cada letra de la palabra que formé
					if (palabra[j] == palabraFormada[k]){
						break;
					}
				}
				//si el k es >= a nPal es porque recorrió todas las letras y no
				//encontró ninguna coincidencia, por lo tanto no hizo break y
				//las letras no coinciden
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
