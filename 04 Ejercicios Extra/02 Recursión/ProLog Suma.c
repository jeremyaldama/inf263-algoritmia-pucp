#include <stdio.h>

int sumar(int num1,int num2){
	if (num1==0) return num2;
	sumar(num1-1,num2);
}

int main(){
	
	int num1,num2;
	printf("INGRESE DOS NUMEROS: ");
	scanf("%d %d",&num1,&num2);
	printf("LA SUMA ES %d",sumar(num1,num2));
}
