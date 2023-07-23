#include <stdio.h>

void originalQuickSort(int array[], int left_limit, int right_limit){
	int left, right, pivot, aux;
	left = left_limit;
	right = right_limit;
	pivot = array[(left + right)/2];

	do {
		while (array[left] < pivot && left < right_limit) left++;
		while (pivot < array[right] && right > left_limit) right--;
		if (left <= right){
			aux = array[left];
			array[left] = array[right];
			array[right] = aux;
			left++;
			right--;
		}
	} while ( left <= right );

	if (left_limit < right) originalQuickSort(array, left_limit, right);
	if (left < right_limit) originalQuickSort(array, left, right_limit);
}


void quickSort(int array[], int n){
	originalQuickSort(array, 0, n-1);	
}

int main(){
	int array[] = {30, 54, 23, 80, 14, 8, 1, 2, 0, -15, 666};
	int i, size = sizeof(array) / sizeof(int);

	for (i=0; i<size; i++)
		printf("%d ", array[i]);

	quickSort(array, size);

	for (i=0; i<size; i++)
		printf("%d ", array[i]);

	return 0;
}