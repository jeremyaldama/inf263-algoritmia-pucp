#include <stdio.h>

int fibonacci(int n){
	int fibo;
	if (n==1) fibo = 0;
	else if (n==2) fibo = 1;
	else fibo = fibonacci(n-1) + fibonacci(n-2); 
	printf("%d ",fibo);
	return fibo;
}

int main(){
	int numero, respuesta;
	printf("Ingrese numero: ");
	scanf("%d",&numero);
	respuesta = fibonacci(numero);
	printf("La respuesta es: %d",respuesta);
	return 0;
}
