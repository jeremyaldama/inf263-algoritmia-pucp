#include <stdio.h>

int maximo(int arr[],int ini,int fin){
	int medio;
	
	medio = (ini+fin)/2;
	
	if (ini==fin) return arr[ini];
	
	arr[medio] > arr[medio+1];
}

int main(){
	
	int arreglo[]= {8,10,20,100,50,30,6,1};
	int n=8;
	
	printf("%d ",maximo(arreglo,0,n-1));
}
