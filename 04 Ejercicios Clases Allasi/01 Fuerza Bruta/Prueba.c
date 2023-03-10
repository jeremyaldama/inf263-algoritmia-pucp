#include <stdio.h>

int n=6;

void cargaBin(int* arreglo, int numero) {
	int bit;
	for (bit = 0; bit < n; bit++) {
		arreglo[n - 1 - bit] = numero & 1;
		numero >>= 1;
	}
}

int main(){
	int num = 32;
	
	printf("%d\n",num);
	int bw = num<<1;
	printf("NUM: %d\n\n",bw);
	
	int cromo[6];
	cromo[7] = 999;
	printf("**%d\n\n", cromo[7]);
	cargaBin(cromo, 10);
	
	int i=0;
	for (i=0; i<n; i++) printf("%d ",cromo[i]);
	return 0;
}
