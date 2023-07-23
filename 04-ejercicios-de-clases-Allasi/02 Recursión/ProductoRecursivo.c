#include <stdio.h>

int calcularProductoRecursivo(int a,int b){
	if (b==0) return 0;
	return a + calcularProductoRecursivo(a, --b);
}

int main(){
	int a=5, b=6;
	printf("El producto es %d", calcularProductoRecursivo(a,b));
	
}
