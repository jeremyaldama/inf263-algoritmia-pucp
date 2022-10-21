#include <stdio.h>
#define max 100

// 20180146

int buscar(int arr[max][max], int K, int i, int j, int n) {
	int x, y, z, w;
	int d = n/2 + n%2;
	if (n == 1) {
		if (arr[i][j] == K) {
			printf("\n%d %d",i,j);
			return 1;
		}
		return 0;
	}
	x = buscar(arr,K,i,j,d);
	y = buscar(arr,K,i+d,j,d);
	z = buscar(arr,K,i,j+d,d);
	w = buscar(arr,K,i+d,j+d,d);
	if (x == 1 || y == 1 || z == 1 || w == 1) return 1;
	return 0;
}

int main () {
	int N, K, i, j, p;
	int arr[max][max];
	printf("Ingrese el valor de N y K: ");
	scanf("%d %d",&N,&K);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) scanf("%d",&arr[i][j]);
	}
	p = buscar(arr,K,0,0,N);
	if (p == 0) printf("\nEl elemento no se encuentra");
	return 0;
}
