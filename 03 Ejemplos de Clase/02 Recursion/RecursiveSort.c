#include <stdio.h>

int minIndex(int array[], int ini, int end){
	int val, min;

	if (ini == end) return ini;
	min = ini;
	val = minIndex(array, ini+1, end);

	if (array[min]> array[val]) return val;
	else return min;
}


void sort(int array[], int ini, int end){
	int min_index, aux;

	if (ini >= end) return;

	min_index = minIndex(array, ini, end);
	aux = array[ini];
	array[ini] = array[min_index];
	array[min_index] = aux;

	sort (array, ini+1, end);
}

int main(){
	int i;
	int array[] = {4, 5, 8, 1, 3, 10, 7, 2, 0, 9};

	sort(array, 0, 9);

	for (i=0; i< 10; i++){
		printf("%d ", array[i]);
	}

	return 0;
}