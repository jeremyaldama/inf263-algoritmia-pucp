#include <stdio.h>

void merge(int A[], int ini, int med, int fin)
{	int l1,l2,i;
    int p = 0,q = 0;
    
	l1 = med - ini + 1;
    l2 = fin -med;

    int P[l1 + 1];
    int Q[l2 + 1];

    //Copiar arreglos
    for(i = ini; i <=med; i++)
        P[i-ini] = A[i];

    P[l1] = 1000000;

    for(i = med+1; i <= fin; i++)
        Q[i-med-1] = A[i];

    Q[l2] = 1000000;

    for(i = ini; i <= fin; i++){
        if(P[p] < Q[q])
            A[i] = P[p++];
        else
            A[i] = Q[q++];
    }
}

void mergesort(int A[], int ini, int fin){
    if(ini == fin)
        return;

    int med = (ini + fin)/2;
    mergesort(A, ini, med);
    mergesort(A, med+1, fin);
    merge(A, ini, med, fin);
}

void main(){
    int i,n = 7;
	int A[]= {12, 4, 1, 3, 67, 14, 7};
    
   printf("Original:");
   for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    mergesort(A, 0, n-1);
	
	printf("\nOrdenado:");
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}
