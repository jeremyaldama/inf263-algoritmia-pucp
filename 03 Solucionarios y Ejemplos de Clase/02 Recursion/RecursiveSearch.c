#include <stdio.h>


int find(int array[], int n, int num){
	//Búsqueda hacia atrás
	if (n==0) return -1;
	if (num == array[n-1]) return n-1;
	else return find(array, n-1,num);
}

int find2(int array[], int ini, int n, int num){
	//Búsqueda hacia adelante
	if (ini == n) return -1;
	if (array[ini] == num) return ini;
	else return	find2(array, ini+1, n, num);
}


int main(){
	int array[] = {5, 6, 9, 20, 1, 666, 0};
	printf("Busqueda hacia atras: %d ", find(array, 7, 666));
	printf("Busqueda hacia adelante: %d ", find2(array, 0, 7, 666));
	return 0;
}

