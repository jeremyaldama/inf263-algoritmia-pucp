#include <stdio.h>
#include <stdlib.h>
#define n 4
#define m 4

int HallarMinimaDistancia(int monticulo, int ul_arr,
                          int ul_arr_izq, int ul_izq,
                        int arriba, int arriba_izq,
                        int izquierda, int *mov_x, int *mov_y){
    int dist_arriba = abs(arriba-monticulo);
    int dist_arriba_izq = abs(arriba_izq-monticulo);
    int dist_izquierda = abs(izquierda-monticulo);
    
    if (dist_arriba+ul_arr<=dist_arriba_izq+ul_arr_izq 
        && dist_arriba+ul_arr<=dist_izquierda+ul_izq){
        *mov_x = -1;
        *mov_y = 0;
        return dist_arriba;
    }
    else if (dist_arriba_izq+ul_arr_izq<=dist_arriba+ul_arr && 
            dist_arriba_izq+ul_arr_izq<=dist_izquierda+ul_izq){
        *mov_x = -1;
        *mov_y = -1;
        return dist_arriba_izq;
    }
    else{
        *mov_x = 0;
        *mov_y = -1;
        return dist_izquierda;
    }

    return  dist_arriba<=dist_arriba_izq?
            (dist_izquierda<dist_arriba? dist_izquierda:dist_arriba) :
            dist_arriba_izq;
}

void DistanciasRecorridas(int monticulos[n][m]){
    int distancias[n][m], mov_x, mov_y;
    distancias[0][0] = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i==0 && j==0){
                distancias[i][j] = 0;
            }
            else if (i==0){
                distancias[i][j] = distancias[i][j-1] + 
                                abs(monticulos[i][j-1]-monticulos[i][j]);
            }
            else if (j==0){
                distancias[i][j] = distancias[i-1][j] +
                                abs(monticulos[i-1][j]-monticulos[i][j]);
            }
            else{
                distancias[i][j] = HallarMinimaDistancia
                                (monticulos[i][j], distancias[i-1][j],
                                distancias[i-1][j-1], distancias[i][j-1],
                                monticulos[i-1][j],
                                monticulos[i-1][j-1], monticulos[i][j-1],
                                &mov_x, &mov_y) +
                                distancias[i+mov_x][j+mov_y];
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d ", distancias[i][j]);
        }
        printf("\n");
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