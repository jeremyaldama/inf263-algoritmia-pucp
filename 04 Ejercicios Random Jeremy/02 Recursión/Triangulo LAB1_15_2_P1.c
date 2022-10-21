#include <stdio.h>
 
void triangulo(int a,int b);
  
void triangulo(int a,int b){
 	int i;
 	if (a>b) return;
 	for (i=0;i<a;i++) printf("* ");
 	printf("\n");
 	triangulo(a+1,b);
 	for (i=0;i<a;i++) printf("* ");//se va apilando
 	printf("\n");
}

void imprimirFila(int num){
	if (num==0) return;
	printf("* ");
	imprimirFila(num-1);
}

void triangulo2(int a, int b){
	int i;
	if (a>b) return;
	
	imprimirFila(a);
	printf("\n");
	triangulo2(a+1,b);
	imprimirFila(a);
	printf("\n");
}
 
int main(){
 	triangulo2(2,5);
 	return 0;
}
