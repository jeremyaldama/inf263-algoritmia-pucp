#include <stdio.h>

void buscar(int*arr, int ini, int fin){
	int med = (ini+fin)/2;
	
	if (ini==fin){
		printf("No se repite: %d", arr[ini]);
		return ;	
	}
	if (med%2==0){
		if (arr[med]==arr[med+1])
			buscar(arr, med+2, fin);
		else{
			buscar(arr, ini, med);
		}
	}
	else{
		if (arr[med]==arr[med-1]){
			buscar(arr, med+1, fin);
		}
		else{
			buscar(arr, ini, med-1);
		}
	}
}

int main(){
	int arr[] = {1,1,2,2,3,3,4,4,5,6,6,7,7,8,8};
	int n=15;
	buscar(arr, 0, n-1);
	return 0;
}
