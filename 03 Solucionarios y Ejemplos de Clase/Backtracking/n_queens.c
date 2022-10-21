#include <stdio.h>
#include <stdlib.h>

#define N 4

int cont = 0;

void print_board(int board[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

void fill_board(int board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            board[i][j] = 0;
    }
}

int is_valid(int board[N][N], int col, int fila){
    int i,j;
    // Verificar el lado izquierdo de la misma fila
    for (i = 0; i < col; i++)
        if (board[fila][i] == 1)
            return 0;
    
    // Verificar la diagonal super izquierda
    for (i=col-1,j=fila-1; i>=0 && j>=0;i--, j--){
        if (board[j][i] == 1)
            return 0;
    }
    
    // Verificar la diagonal inferior izquierda
    for (i=col-1,j=fila+1; i>=0 && j< N; i--, j++){
        if (board[j][i] == 1)
            return 0;
    }
    
    return 1;
}


int solve_NQ(int n, int board[][n], int col){  //columna estatica para el movimiento
    int i;
    if (col == n){
        (cont)++;
        //printf("Solucion %d:\n", cont);
        //print_board(board);
        return 1;
    }

    for (i = 0; i < n; i++){
        if (is_valid(board, col, i))   //verifica si la fila es valida 
        {
            board[i][col] = 1;   // se busca cada fila y coloca la reina
            /*
            if (!solve_NQ(n, board, col+1))
                board[i][col] = 0;
            */
            
            if (solve_NQ(n, board, col+1))    // avanza a la siguiente 
            {
                return 1;
            }
            else
                board[i][col] = 0;        // si no puede colocar la siguiente falso  
            
        }
    }
    return 0;           // inicia el proceso de retroceso con falso
}

int main() {
    int board[N][N];
    fill_board(board);

    solve_NQ(N, board, 0);
    printf("Hay %d soluciones\n", cont);
    print_board(board);
    

    return (0);
}

