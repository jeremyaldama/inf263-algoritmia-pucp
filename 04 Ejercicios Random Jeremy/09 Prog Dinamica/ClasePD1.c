#include <stdio.h>

int devuelveMaximo(int*monedas, int n){
    int F[n+1];
    F[0] = 0;
    F[1] = monedas[0];

    int i, temp, nuevo;
    for (i=2; i<=n; i++){
        temp = F[i-1];
        nuevo = monedas[i-1] + F[i-2];

        if (nuevo>temp){
            temp = nuevo;
        }
        
        F[i] = temp;
    }

    return F[n];
}

int main(){

    int monedas[] = {5,1,2,10,6,2};
    int n = sizeof(monedas)/sizeof(int);
    int max = devuelveMaximo(monedas, n);
    printf("El maximo es %d\n", max);

    return 0;
}