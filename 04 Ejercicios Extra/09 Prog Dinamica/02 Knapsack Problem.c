#include <stdio.h>

int max(int a, int b){
    return a>b? a:b;
}
//Bottom-Up Dynamic Programming
void KnapsackDP(int*weights, int* values, int max_weight, int n, 
                int table[][max_weight]){
    for (int i=0; i<n; i++){
        for (int w=0; w<max_weight; w++){
            if (w==0 || i==0) table[i][w] = 0;
            else if (w>=weights[i-1]){
                table[i][w] = max(table[i-1][w],
                                  values[i-1] + table[i-1][w-weights[i-1]]);
            }
            else table[i][w] = table[i-1][w];
        }
    }
}

void ShowTable(int n, int m, int table[n][m]){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            printf("%-2d ", table[i][j]);
        printf("\n");
    }
}

int main(){
    int weights[] = {2, 1, 3, 2, 4, 1, 3,1, 3, 5, 5,6,7};
    int values[] = {12, 10, 20, 15, 12,12,11,11,10, 10, 20};
    int max_weight = 6;
    int n = sizeof(weights)/sizeof(int);
    int table[n+1][max_weight+1];//max_weight+1 para la columna de 0's

    KnapsackDP(weights, values, max_weight+1, n+1, table);
    printf("El maximo valor que puede guardar la mochila"
            " de peso maximo %d", max_weight);
    printf(" es %d\n", table[n][max_weight]);
    ShowTable(n+1, max_weight+1, table);
    return 0;
}