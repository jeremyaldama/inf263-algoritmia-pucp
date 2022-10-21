#include <stdio.h>
#include <limits.h>

void merge(int array[], int ini, int med, int fin){
	int l1, l2, i;
	int p=0, q=0;

	l1 = med - ini + 1;
	l2 = fin - med;

	int leftArray[l1+1];
	int rightArray[l2+1];

	for (i = ini; i<=med; i++)
		leftArray[i-ini] = array[i];
	leftArray[l1] = INT_MAX;

	for (i=med+1; i<=fin; i++)
		rightArray[i-med-1] = array[i];
	rightArray[l2] = INT_MAX;

	for (i=ini; i<=fin; i++){
		if (leftArray[p] < rightArray[q])
			array[i] =leftArray[p++];
		else 
			array[i] = rightArray[q++];
	}
}

void mergeSort(int array[], int ini, int fin){
	int med;
	if (ini == fin) return;
	med = (ini + fin) /2;
	mergeSort(array, ini, med);
	mergeSort(array, med+1, fin);
	merge(array, ini, med, fin);
}

int main(){
	int array[] = {12, 5, 1, 3, 2, 7, 8};
	int n=7, i;

	mergeSort(array, 0, n-1);

	for (i=0; i<n; i++)
		printf("%d ", array[i]);
}