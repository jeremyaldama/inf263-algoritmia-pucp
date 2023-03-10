#include <stdio.h>

int contarCeros(int*arr, int ini, int fin, int cont){
	if (ini>fin) return cont;
	int med = (ini+fin)/2;
	if (arr[med]) return contarCeros(arr,ini,med-1,cont); 
	else{
		return contarCeros(arr, med+1,fin,fin-med+1+cont);
	}
}

int main(){
	int arr[9] = {0,0,0,0,0,1,1,1,1};
	int cont, n=9;				 //contParcial
	cont = contarCeros(arr, 0, n-1,0);
	printf("Hay %d ceros",cont);
	return 0;
}
