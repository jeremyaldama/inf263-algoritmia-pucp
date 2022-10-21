#include <stdio.h>
#define max 100

// 20180146

int sumaInv(int arr[max][max],int fila, int ini, int fin) {
	int cant1, cant2;
	int m = (ini+fin)/2;
	if (ini == fin) {
		arr[fila][ini] *= (-1);
		//printf("%d ",arr[fila][ini]);
		return arr[fila][ini];
	}	
	cant1 = sumaInv(arr,fila,ini,m);
	cant2 = sumaInv(arr,fila,m+1,fin);
	return cant1 + cant2;
}

void buscarInvertido(int arr[max][max], int n, int k) {
	int i, cant, cantMayor = -9999999, fila;
	for(i = 0; i < n; i++) {
		cant = sumaInv(arr,i,0,k-1);
		//printf("\n");
		if (cant > cantMayor) {
			cantMayor = cant;
			fila = i;
		}
	}
	printf("La cantidad mayor es %d\n",cantMayor);
	for (i = 0; i < k; i++) printf("%d ",(-1)*arr[fila][i]);
}

int main () {
	int n, k, i, j;
	int arr[max][max];
	printf("Ingrese el valor de n y k: ");
	scanf("%d %d",&n,&k);
	for(i = 0; i < n; i++){ 
		for(j = 0; j < k; j++) scanf("%d",&arr[i][j]);
	}
	buscarInvertido(arr,n,k);
	return 0;
}
