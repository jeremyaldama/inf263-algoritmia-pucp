#include <stdio.h>
#include <stdlib.h>

int cant = 0;
int soluciones[3];

void buscar_maneras(int i, int j, int d, int n, int A[10]) {
	if (j == 2) {
		if ((soluciones[1] - soluciones[0]) > d)
			return;
	} else if (j == 3) {
		if ((soluciones[2] - soluciones[0]) > d)
			return;
		else {
			cant++;
			printf("%d %d %d\n",soluciones[0],soluciones[1],soluciones[2]);
			return;
		}
	}
	int k;
	for (k = i; k < n; k++) {
		soluciones[j] = A[k];
		buscar_maneras(k+1,j+1,d,n,A);
	}
}

int main () {
	int n = 10;
	int A[10] = {1,4,2,27,65,79,82,83,99,100};
	int d = 50;
	buscar_maneras(0,0,d,n,A);
	printf("Total: %d",cant);
	return 0;
}
