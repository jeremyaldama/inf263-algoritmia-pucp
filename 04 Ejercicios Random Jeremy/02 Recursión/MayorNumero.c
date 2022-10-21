#include <stdio.h>

int mayor(int arreglo[],int n){
	int max,resto;
	
	if (n==1) return arreglo[n-1];
	
	max = arreglo[n-1];
	resto = mayor(arreglo,n-1);
	
	if (max<resto) return resto;
	else return max;
}

int buscar(int arreglo[],int n,int numero){
	if (n==0) return -1;
	
	if (arreglo[n-1]==numero) return n;
	return buscar(arreglo,n-1,numero);
}

int main(){
	int arreglo[] = {5,4,2,27,2,1,9};
	int n=7,numero=9;
	
	printf("%d",mayor(arreglo,n));
	printf("El numero buscado es: %d",buscar(arreglo,n,numero));
	return 0;
}
