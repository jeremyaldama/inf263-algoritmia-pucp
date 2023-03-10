#include <stdio.h>

int busquedaBinaria(int*arr, int elemento, int ini, int fin){
	int med;
	med = (ini + fin)/2;
	if (arr[med]==elemento) return med;
	
	if (ini>fin) return -1;//casi siempre es el caso base en dyv
	
	if (arr[med]<elemento) return busquedaBinaria(arr, elemento, med+1, fin);
	if (arr[med]>elemento) return busquedaBinaria(arr, elemento, ini, med-1);
}

int main(){
	int n = 7;
	int arr[7] = {1,2,5,8,10,12,15};
	int elemento=20;
	printf("El elemento %d se encuentra en el indice %d del arreglo", elemento, busquedaBinaria(arr, elemento, 0, n-1));
	return 0;
}
