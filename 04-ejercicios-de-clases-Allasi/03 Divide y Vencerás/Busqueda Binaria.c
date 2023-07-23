#include <stdio.h>

int busquedaBinaria(int A[],int k,int ini,int fin){
	if (ini > fin) return -1;
	int med = (ini + fin)/2;
	
	if (A[med]==k) return med;
	
	if (A[med]>k) busquedaBinaria(A,k,ini,med-1);//el if-else delimita el espacio y
	else busquedaBinaria(A,k,med+1,fin);		 //lo diferencia de la recursión
}//funciona porque el lenguaje C devuelve el ultimo return que resuelve

int main(){
	int A[] = {2,4,5,7,8,10,12,16};
	int n=8,k=2;
	
	printf("%d ",busquedaBinaria(A,k,0,n-1));
	return 0;
}


