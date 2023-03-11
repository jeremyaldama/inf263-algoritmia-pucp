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
	cout<<"Palabra a buscar: "<<palabra<<endl;
	while (1){
		arch>>letra[i];
		if (arch.eof()) break;
		i++;
	}
	
	int n = i, j, k;
	int cromo[n];
	int comb = pow(2, n);
	char palabra_formada[n];
	
	for (i=0; i<comb; i++){
		carga_bin(cromo, i, n);
		k=0;
		
		for (j=0; j<n; j++) palabra_formada[j] = 0;
		
		for (j=0; j<n; j++){
			if (cromo[j]){
				palabra_formada[k] = letra[j];
				k++;
			}
		}
		
		if (strcmp(palabra_formada, palabra)==0){
			printf("Posible combinacion: ");
			for (j=0; j<n; j++){
				if (cromo[j]){
					cout<<j+1<<" ";
				}
			}
			break;
		}
	}
	
	return 0;
}
