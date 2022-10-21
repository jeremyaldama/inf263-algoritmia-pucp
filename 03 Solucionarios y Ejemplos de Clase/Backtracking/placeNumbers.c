#include <stdio.h>

#define N 100


void imprimir_solucion(int A[], int n){
    int i;
    for(i = 0; i < 2*n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");
}

int ponerNumeros(int A[], int numero, int n){
    int i;
    if(numero > n)
        return 1;

    for(i = 0; i < 2*n; i++){
        //Validar la colocacion del numero en i y (i + numero + 1)
        if((i + numero + 1) < 2*n){
            if(A[i] == 0 && A[i + numero + 1]==0){
                A[i] = A[i + numero + 1] = numero;
                //imprimir_solucion(A, n);
                if(ponerNumeros(A, numero + 1, n))
                    return 1;
                A[i] = A[i + numero + 1] = 0;
            }
        }
    }
    return 0;
}

void main(){
    int n;
    int A[N];
    int i;

    scanf("%d", &n);

    for(i = 0; i < 2*n; i++)
        A[i] = 0;

    if(ponerNumeros(A, 1, n))
        imprimir_solucion(A,n);
    else
        printf("No hay solucion\n");
}
