#define N 4
#include <stdio.h> 
  
void printSolution(int tablero[N][N]) 
{ int i,j;

    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++) 
            printf(" %d ", tablero[i][j]); 
        printf("\n"); 
    } 
} 
  

int esvalido(int tablero[N][N], int row, int col) 
{ 
    int i, j; 
  
    for (i = 0; i < col; i++) 
        if (tablero[row][i]) 
            return 0; 
  
    /* diagonal */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (tablero[i][j]) 
            return 0; 
  
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (tablero[i][j]) 
            return 0; 
  
    return 1; 
} 
  

int resuelve(int tablero[N][N], int col) 
{ int i;
    if (col >= N) 
        return 1; 
  
    /* revisa cada fila*/
    for (i = 0; i < N; i++) { 

        if (esvalido(tablero, i, col)) { 
            tablero[i][col] = 1; 
  
            /* revisa el resto de posiciones */
            if (resuelve(tablero, col + 1)) 
                return 1; 
  
            tablero[i][col] = 0; // BACK 
        } 
    } 
  
    return 0; 
} 
  
int main() 
{ 
    int tablero[N][N] = { { 0, 0, 0, 0 }, 
                          { 0, 0, 0, 0 }, 
                          { 0, 0, 0, 0 }, 
                          { 0, 0, 0, 0 } }; 
  
    if (!resuelve(tablero, 0)) { 
        printf("No existe solucion"); 
        return 0; 
    } 
  
    printSolution(tablero); 
    return 0; 
} 
