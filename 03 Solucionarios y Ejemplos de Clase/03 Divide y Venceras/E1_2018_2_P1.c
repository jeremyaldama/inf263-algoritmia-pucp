#include <stdio.h>
#define max 50

// 20180146

double factorial(int n) {
	if (n <= 1) return 1.0;
	else return n*factorial(n-1);
} 

int contarCeros(int num) {
	int n = 0;
	while (num > 0) {
		num = num/5;
		n += num;
	}
	return n;
}

void numCeros(int n) {
	int m, p, i;
	int ini = 0;
	int fin = 1000000;
	int resultado[max];
	while (ini < fin) {
		m = (ini+fin)/2;
		p = contarCeros(m);
		if (p < n) ini = m + 1;
		else fin = m;
	}
	int k = 0;
	while (contarCeros(ini) == n) {
		resultado[k] = ini;
		k++;
		ini++;
	}
	for(i = 0; i < k; i++) {
		printf("%d ",resultado[i]);
	}
}

int main () {
	int n, num;
	printf("Ingrese el valor de n: ");
	scanf("%d",&n);
	numCeros(n);
	return 0;
}
