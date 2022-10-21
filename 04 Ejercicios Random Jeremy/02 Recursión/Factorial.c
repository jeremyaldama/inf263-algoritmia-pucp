#include <stdio.h>

int factorial (int n){
	if (n==0) return 1;
	return n*factorial(n-1);
}

int main(){
	int numero;
	printf("Ingrese un numero: ");
	scanf("%d",&numero);
	int resp = factorial(numero);
	printf("El factorial es %d",resp);
}


