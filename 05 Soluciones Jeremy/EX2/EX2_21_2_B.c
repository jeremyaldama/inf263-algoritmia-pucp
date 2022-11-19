#include <stdio.h>
#include <math.h>
#define n 4
#define m 4

void DistanciasRecorridas(int *monticulos){
    int distancias[n][m];
    distancias[0][0] = 0;

    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            int derecha = abs(monticulos[i-1][j-1]-monticulos[i][j]);
            
        }
    }
}

int main(){
    int monticulos[n][m] = {{4, 2, 2, 4},
                            {1, 4, 6, 8},
                            {2, 5, 9, 1},
                            {1, 3, 11, 12}};

    
    DistanciasRecorridas(monticulos);
    return 0;
}