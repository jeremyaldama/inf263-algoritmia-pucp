#include <stdio.h>

int buscar(int lonchera[][4], int nLonch, int ini, int fin){
	if (ini==fin) return lonchera[nLonch][ini];
	int med = (ini+fin)/2;
	
	int derecha, izquierda;
	izquierda = buscar(lonchera, nLonch, ini, med);
	derecha = buscar(lonchera, nLonch, med+1, fin);
	if (derecha<izquierda) return derecha;
	else return izquierda;
	
}

int main(){
	int lonchera[4][4];
	
	int i, j;
	for (i=0; i<4; i++){
		printf("Ingrese calorias de la lonchera %d:\n", i+1);
		for (j=0; j<4; j++){
			scanf("%d", &lonchera[i][j]);
		}
	}
	int saludable[4];
	int menor;
	for (i=0; i<4; i++){
		menor = buscar(lonchera, i, 0, 3);
		printf("Menor caloria: %d\n",menor);
		saludable[i] = menor;
	}
	return 0;
}
