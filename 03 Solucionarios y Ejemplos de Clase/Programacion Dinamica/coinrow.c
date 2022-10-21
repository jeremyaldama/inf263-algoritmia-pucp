#include <stdio.h>

int coinrow(int A[], int n){
    int F[n+1];

    F[0] = 0;
    F[1] = A[0];

    int i;
    for(i = 2; i <=n; i++){
        int max = F[i-1];
        int aux = A[i - 1] + F[i-2];
        if(aux > max)
            max = aux;
        F[i] = max;
    }

    return F[n];
}

void main(){
    int A[6]={5, 1, 2, 10, 6, 2};
    int n = 6;

    int val = coinrow(A, n);
    printf("El maximo valor es %d", val);
}
