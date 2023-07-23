#include <stdio.h>

void merge(int*arr, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1], R[n2];
	int i, j, k;
	
	for (i=0; i<n1; i++)	L[i] = arr[p+i];//se llenan los 4 primeros numeros de la izquierda
	
	for (i=0; i<n2; i++)	R[i] = arr[q+i+1];//se llenan los 4 ultimos numeros de la derecha
	
	L[n1] = 9999999;
	R[n2] = 9999999;
	
	i=j=0;
	for (k=p; k<r+1; k++){
		if (R[j]>=L[i]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int*arr, int p, int r){
	if (p==r) return;
	int q = (p+r)/2;
	
	mergeSort(arr, p, q);
	mergeSort(arr, q+1, r);
	
	merge(arr, p, q, r);
}

int main(){
	int arr[7] = {20,4,1,9,10,5,7};
	mergeSort(arr, 0, 6);
	//int orde[8] = {2,4,5,6,1,2,3,7};
	//merge(orde, 0, 3, 7);
	int i;
	//for(i=0; i<8; i++) printf("%d ", orde[i]);
	printf("\n");
	for(i=0; i<7; i++) printf("%d ", arr[i]);
	return 0;
}
