#include <stdio.h>
#include <stdlib.h>
int k = 5;

void Merge(int*arr, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1], R[n2];
	int i, j, k;
	
	for (i=0; i<n1; i++)	L[i] = arr[p+i];//se llenan los 4 primeros numeros de la izquierda
	
	for (i=0; i<n2; i++)	R[i] = arr[q+i+1];//se llenan los 4 ultimos numeros de la derecha
	
	L[n1] = -9999999;
	R[n2] = -9999999;
	
	i=j=0;
	for (k=p; k<r+1; k++){
		if (R[j]<=L[i]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int*arr, int p, int r){
	if (p==r) return;
	int q = (p+r)/2;
	
	MergeSort(arr, p, q);
	MergeSort(arr, q+1, r);
	
	Merge(arr, p, q, r);
}

int CalcularPesoMaximo(int *pavos, int n){
    int dp[n];
    int usado[n];

    int i, j;

    for (i=0; i<n; i++){
        dp[i] = 0;
        usado[i] = 0;
    }

    for (i=0; i<n-1; i++){
        for (j=i+1; j<n; j++){
            if (abs(pavos[i]-pavos[j])<k){
                int suma = pavos[i] + pavos[j];
                if (suma > dp[i] && !usado[i]){
                    usado[j] = 1;
                    dp[i] = suma;
                    dp[n-1] += dp[i];
                }
            }
        }
    }

    return dp[n-1];
}

int main(){
    int pavos[] = {3, 25, 18, 15, 4, 12, 6};
    int n = sizeof(pavos)/sizeof(int);
    
    MergeSort(pavos, 0, n-1);

    printf("El peso maximo es: %d\n", CalcularPesoMaximo(pavos, n));

    return 0;
}