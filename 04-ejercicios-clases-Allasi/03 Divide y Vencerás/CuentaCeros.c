#include <stdio.h>

int cuentaCeros(int A[],int ini,int fin,int cont){
	if (ini > fin) return cont;
	int med = (ini + fin)/2;
	
	if (A[med]==0) cuentaCeros(A,ini,med-1,fin-med+cont+1);
	else cuentaCeros(A,med+1,fin,cont);
	
}

int main(){
	int A[] = {1,1,1,1,0,0,0,0};
	int n=8;
	
	printf("%d ",cuentaCeros(A,0,n-1,0));
	return 0;
}


