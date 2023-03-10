#include <stdio.h>

int MaximizarGanancia(int*ganancia, int n){
    // 

    int dp[n+1];
    dp[0] = 0;
    dp[1] = ganancia[0];
    dp[2] = (ganancia[1]>ganancia[0])? ganancia[1]:ganancia[0];

    for (int i=3; i<n+1; i++){
        int suma = ganancia[i-1] + dp[i-3];
        if (suma>dp[i-1]){
            dp[i] = suma;
        }
        else dp[i] = dp[i-1];
    }
    return dp[n];
}

int main(){
    int ganancia[] = {3, 6, 1, 2, 4, 5, 18, 10, 13, 7, 15, 2};
    int n = sizeof(ganancia)/sizeof(int);
    //12 meses
    int solucion[12] = {};
    //piden maximizar ganancia;
    printf("La ganancia maxima es: %d\n", MaximizarGanancia(ganancia, n));
    return 0;
}