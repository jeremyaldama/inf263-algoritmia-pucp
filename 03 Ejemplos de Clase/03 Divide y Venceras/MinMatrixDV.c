#include <stdio.h>

int min(int a, int b){
	return (a<b)?a:b;
}

int minMatrix(int matrix[10][10], int i,  int j, int n){
	int d, a1, a2, a3, a4;

	d = n/2 + n%2;

	if (n == 1)
		return matrix[i][j];

	a1 = minMatrix(matrix, i, j, d);
	a2 = minMatrix(matrix, i+d, j, d);
	a3 = minMatrix(matrix, i, j+d, d);
	a4 = minMatrix(matrix, i+d, j+d, d);

	if (min (a1, a2) < min (a3, a4)) return min(a1,a2);
	else return min (a3, a4);
}

int main(){
	int i, j, n=4;
	int matrix[10][10];

	for (i=0; i<10; i++)
		for (j=0; j<10; j++)
			matrix[i][j] = 999999;

	int matrix2[][4]={ 	{3, 8, 2, 5}, 
						{9, 3, 5, 4}, 
						{4, 1, 0, 7}, 
						{6, 4, 2,-2} 
					 };

	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			matrix[i][j] = matrix2[i][j];

	printf("El valor minimo es: %d\n", minMatrix(matrix, 0, 0, n));			

	return 0;
}