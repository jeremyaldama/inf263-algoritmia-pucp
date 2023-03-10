#include <stdio.h>

int count (int array[], int ini, int n){
	int medio, cont=0;
	medio = (ini + n + 1) / 2;

	if (medio == 0 || medio == ini){
		if (array[ini] == 1) return 1;
		else return 0;
	} else {
		cont += count(array, ini, medio-1);
		cont += count(array, medio, n); 
		return cont;		
	}
}

int main(){
	int array[]={1, 1, 1, 0, 0, 0, 1, 1};
	int n = 8;

	printf("Cantidad de unos en el arreglo: %d\n.", count(array, 0, n-1));

	return 0;
}