#include <stdio.h>

int searchMin(int array[], int ini, int n){

	int medio, left_min, right_min;
	medio = (ini+n+1)/2;

	if (medio==0 || medio == ini){
		if (array[ini] < array[n]) return array[ini];
		else return array[n];
	} else {
		left_min = searchMin(array, ini, medio-1);
		right_min = searchMin(array, medio, n);
		if (left_min < right_min) return left_min;
		else return right_min;
	}
}

int main(){
	int array[] = {8, 5, -96, 666, 78, 98, 96, 24};
	int n = 8;

	int minVal = searchMin(array, 0, n-1);
	printf ("El menor valor es %d.\n", minVal);
	
	return 0;
}