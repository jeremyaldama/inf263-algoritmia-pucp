#include <stdio.h>

int mochila(int n, int W, int V[], int w[]){
    int T[n+1][W+1];
    int i,j;

    //Primera columna en ceros
    for(i = 0; i <= n; i++)
        T[i][0] = 0;

    //Primera fila en ceros
    for(i = 0; i <= W; i++)
        T[0][i] = 0;

    for(j = 1; j <= W; j++){
        for(i = 1; i <= n; i++){
            if((j - w[i-1])>=0){
                int max = T[i-1][j];
                if((V[i-1] + T[i-1][j-w[i-1]]) > max)
                    max = V[i-1] + T[i-1][j-w[i-1]];
                T[i][j] = max;
            }else{
                T[i][j] = T[i-1][j];
            }
        }
    }
    return T[n][W];
}
void main(void){
    int V[] = {12,10,20,15};
    int w[] = {2, 1, 3, 2};

    int W = 5;
    int n = 4;

    int maximo = mochila(n, W, V, w);
    printf("El maximo valor es:%d\n", maximo);
}
