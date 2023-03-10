#include <stdio.h>

int mayor(int A[], int ini, int fin){
    if(ini == fin)
        return A[fin];
    
    int may = mayor(A, ini+1, fin);

    if(may > A[ini])
        return may;

}

int main(){
    int A[100]={134, 1221, 3, 6, 19, -4, 32, 89, 3, 6, 2};
    int n = 11;

    printf("El maximo es %d\n", mayor(A, 0, n-1));

    return 0;
}
