#include <stdio.h>

void ordenacion_seleccion(int A[], int N){
    int i, j;

    for(i = 0; i <= (N-2); i++){
        int min = i;
        for(j = i + 1; j <=(N-1); j++){
            if(A[j] < A[min])
                min = j;
        }
        int aux = A[i];
        A[i] = A[min];
        A[min] = aux;
    }
}

void ordenacion_burbuja(int A[], int N){
    int i, j;

    for(i = 0; i <= (N-2); i++){
        for(j = 0; j <= (N-2-i); j++)
            if(A[j+1] < A[j]){
                int aux = A[j+1];
                A[j+1] = A[j];
                A[j] = aux;
            }
    }
}

void print_array(int A[], int N){
    int i;
    for(i = 0; i< N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void main(void){
    int A[20];
    int N;

    //printf("Ordenacion Seleccion\n");
    //printf("Ingrese numero de elementos:");
    
    scanf("%d", &N);

    int i;
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);

    //ordenacion_seleccion(A, N);
    ordenacion_burbuja(A, N);
    print_array(A, N);



}
