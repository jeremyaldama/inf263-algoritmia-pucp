#include <stdio.h>

#define N 4

void imprimir_solucion(int laberinto[N][N])
{
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%d ", laberinto[i][j]);
        printf("\n");
    }
}

int ratMaze(int laberinto[N][N], int x, int y){

    if(x == (N-1) && y == (N-1))
        return 1;

    //Movimiento hacia abajo
    if((x+1) < N){
        if(laberinto[x+1][y]==0){
            laberinto[x+1][y] = 2;
            if(ratMaze(laberinto, x+1, y))
                return 1;
            laberinto[x+1][y] = 0;
        }
    }

    //Movimiento adelante
    if((y + 1) < N){
        if(laberinto[x][y + 1] == 0){
            laberinto[x][y + 1] = 2;
            if(ratMaze(laberinto, x, y+1))
                return 1;
            laberinto[x][y+1] = 0;
        }
    }

    return 0;
}

void main(void){
    int laberinto[N][N];
    int i,j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &laberinto[i][j]);

    laberinto[0][0] = 2;
    if(ratMaze(laberinto, 0, 0))
        imprimir_solucion(laberinto);
    else
        printf("No hay solucion");

}
