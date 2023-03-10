#include <stdio.h>
#include <stdlib.h>


void swap(int *arr, int ini, int end){
	int temp = arr[ini];
	//*(arr + ini) = *(arr+end);
	arr[ini] = arr[end];
	arr[end] = temp;	
}

void swap_by_pointers(int *p1, int *p2){
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;		
}

int sequential_search(int arr[], int size, int value){
	int i=0;
	while (i < size && arr[i] != value){
		i++;
	}
	if (i<size) return i;
	else return -1;
}

void bubble_sort (int arr[], int size) {
//void bubble_sort (int *arr, int size) {
	int i, j, temp;
	for (i=0; i <= size-2; i++){
		for (j=0; j<= size-2-i; j++){
			if (arr[j+1] < arr[j]){
				//swap(arr, j, j+1);
				//swap_by_pointers( &(arr[j]), &(arr[j+1]));
				swap_by_pointers( arr+j, arr+j+1 );
				//temp = arr[j];
				//*(arr + j) = *(arr+j+1);
				//arr[j] = arr[j+1];
				//arr[j+1] = temp;
			}
		}
	}
	size = 666;
}

int main(){

	int array[] = {5, 10, 15, 2, 6, 3, 666, 699, 13};	
	int i, n = 9;

	int pos = sequential_search(array, n, 666);
	printf("La posicion del valor 666 es %d\n", pos);
	bubble_sort(array, n);
	for (i=0; i<n; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("El valor de n es %d \n", n);
}