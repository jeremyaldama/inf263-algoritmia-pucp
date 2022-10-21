/*
	Desarrollado por Johan Baldeón	
*/

#include <stdio.h>
#include <string.h>
#define MAX 20
const char * max_word = "zzzzzzzzzzzzz"; 

void merge(char array[][MAX], int ini, int med, int fin){
	int l1, l2, i;
	int p=0, q=0;

	l1 = med - ini + 1;
	l2 = fin - med;

	char leftArray[l1+1][MAX];
	char rightArray[l2+1][MAX];

	for (i = ini; i<=med; i++)
		strcpy(leftArray[i-ini], array[i]);
	strcpy(leftArray[l1], max_word);

	for (i=med+1; i<=fin; i++)
		strcpy(rightArray[i-med-1], array[i]);
	strcpy(rightArray[l2], max_word);

	for (i=ini; i<=fin; i++){
		if (strcmp(leftArray[p],rightArray[q]) < 0 ){
			strcpy(array[i], leftArray[p++]);
		}
		else {
			strcpy(array[i], rightArray[q++]);
		}
	}
}

void mergeSort(char array[][MAX], int ini, int fin){
	int med;
	if (ini == fin) return;
	med = (ini + fin) /2;
	mergeSort(array, ini, med);
	mergeSort(array, med+1, fin);
	merge(array, ini, med, fin);
}

int main(){
	int i, len=5;
	char words[][MAX]= {"atreverse", "atrevido", "atrevimiento", "atrevida", "atreve"};
	mergeSort(words, 0, len-1);
	for (i=0; i<len; i++)
		printf("%s\n", words[i]);
}
