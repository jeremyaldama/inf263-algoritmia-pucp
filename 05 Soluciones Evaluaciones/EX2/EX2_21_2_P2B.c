#include <stdio.h>
#define n 6
#define m 6

void RecolectarMayorCantidad(int almacen[][m], int p, int q){
    int dp[p][q];
    int i, j;

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            if (i==0 && j==0){
                dp[i][j] = almacen[i][j];
            }
            else if (i==0){
                dp[i][j] = dp[i][j-1] + almacen[i][j];
            }
            else if (j==0){
                dp[i][j] = dp[i-1][j] + almacen[i][j];
            }
            else{
                int arriba = dp[i-1][j] + almacen[i][j];
                int izquierda = dp[i][j-1] + almacen[i][j];
                dp[i][j] = arriba>izquierda? arriba:izquierda;
            }
        }
    }

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int almacen[][m] = {
        {1, 2, 9, 1, 2, 3},
        {5, 1, 7, 1, 2, 1},
        {1, 7, 1, 3, 8, 1},
        {2, 2, 6, 1, 2 ,2},
        {3, 6, 9, 5, 1, 5},
        {1, 1, 4, 1, 9, 1}
    };

    int p = 6, q = 6;

    RecolectarMayorCantidad(almacen, p, q);
    return 0;
}