#include <stdio.h>
#include <stdlib.h>
#define n 4

void InicializarTablero(int **tablero){
    for (int i=0; i<n; i++){
        tablero[i] = (int*)malloc(sizeof(int)*n);
        for (int j=0; j<n; j++){
            tablero[i][j] = 0;
        }
    }
}

void ImprimirTablero(int**tablero){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}

int HayCruce(int **tablero, int fila, int col){
    int i, j;
    //Verificamos fila hacia arriba
    for (i=0; i<fila; i++){
        if (tablero[i][col]==1) return 1;
    }
    //Verificamos Diagonal superior derecha
    for (i=fila-1, j=col+1; i>=0 && j<n; i--, j++)
        if (tablero[i][j]==1) return 1;
    //Verificamos Diagonal superior izquierda
    for(i=fila-1, j=col-1; i>=0 && j>=0; i--, j--)
        if (tablero[i][j]==1) return 1;
    return 0;
}

int Backtrack(int**tablero, int fila_ini){

    if (fila_ini==n){
        ImprimirTablero(tablero);
        printf("\n\n");
        return 0;
    }

    for (int i=0; i<n; i++){
        if (!HayCruce(tablero, fila_ini, i)){
            tablero[fila_ini][i] = 1;
            if (Backtrack(tablero, fila_ini+1)){
                return 1;
            }
            else tablero[fila_ini][i] = 0;
        }
    }
    return 0;
}

int main(){
    int **tablero = (int**)malloc(sizeof(int*)*n);
    InicializarTablero(tablero);
    ImprimirTablero(tablero);
    printf("\n");
    Backtrack(tablero, 0);
    return 0;
}