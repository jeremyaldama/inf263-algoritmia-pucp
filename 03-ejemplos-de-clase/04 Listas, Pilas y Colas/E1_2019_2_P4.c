#include <stdio.h>
#include <stdlib.h>
#include "TAD Cola.c"
#include "TAD Pila.c"

// 20180146

void ordenarCola(TCola *Cola) {
	int i, j, elem, menor;
	int n = tamanioCola(*Cola);
	TPila Aux;
	crearPila(&Aux);	
	for (i = n; i > 0; i--) { 
		menor = desencolar(Cola);
		for (j = 1; j < i; j++) {
			elem = desencolar(Cola);
			if (elem < menor) {
				encolar(Cola,menor);
				menor = elem;
			} else encolar(Cola,elem);
		}
		apilar(&Aux,menor);
	}
	for(i = 0; i < n; i++) {
		elem = desapilar(&Aux);
		encolar(Cola,elem);
	}
}

int main () {
	int N, data, i;
	TCola Banco;
	crearCola(&Banco);
	printf("Ingrese el numero de clientes: ");
	scanf("%d",&N);
	for (i = 0; i < N; i++) {
		scanf("%d",&data);
		encolar(&Banco,data);
	}
	printf("Cola Original:\n");
	imprimirCola(Banco);
	printf("Cola Ordenada:\n");
	ordenarCola(&Banco);
	imprimirCola(Banco);
	return 0;
}
