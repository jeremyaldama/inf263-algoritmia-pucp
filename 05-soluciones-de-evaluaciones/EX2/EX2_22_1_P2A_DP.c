#include <stdio.h>

int MaximoTiempo(int *tareas_tiempo, int n, int r){
    int dp[r+1][n+1];

    
}

int main(){
    int tareas_tiempo[] = {10, 15, 30, 45, 60};
    int n = sizeof(tareas_tiempo)/sizeof(int);
    int r = 2;
    MaximoTiempo(tareas_tiempo, n, r);
    
    return 0;
}