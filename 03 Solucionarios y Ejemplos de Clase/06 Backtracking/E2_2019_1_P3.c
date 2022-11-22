#include <stdio.h>
#include <stdlib.h>

int cuadrilla[] = {0,0,0,0};

int buscar(int i, int n, int m, int p, int arr[]) {
	if (i > m || p < 0)
		return 0;
	if (p >= 0 && n == 0) {
		int k;
		for (k = 0; k < m; k++) {
			if (cuadrilla[k] == 1)
				printf("%d ",arr[k]);
		}
		printf("\n");			
		return 0;
	}
	cuadrilla[i] = 1;
	if (buscar(i+1,n-1,m,p-arr[i],arr))
		return 1;
	else {
		cuadrilla[i] = 0;
		return (buscar(i+1,n,m,p,arr));
	}
}


int main () {
	int plan[] = {7,5,1,2};
	int n = 3;
	int m = 4;
	int p = 10;
	buscar(0,n,m,p,plan);
	return 0;
}
