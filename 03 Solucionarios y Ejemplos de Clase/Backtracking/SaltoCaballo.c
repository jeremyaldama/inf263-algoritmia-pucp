
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOV 8
#define N 100

int m[MAX_MOV][2];

void generateMoves(){
    m[0][0] =  2; m[0][1] =  1;
    m[1][0] =  1; m[1][1] =  2;
    m[2][0] = -1; m[2][1] =  2;
    m[3][0] = -2; m[3][1] =  1;
    m[4][0] = -2; m[4][1] = -1;
    m[5][0] = -1; m[5][1] = -2;
    m[6][0] =  1; m[6][1] = -2;
    m[7][0] =  2; m[7][1] = -1;
}

void generateTable(int a[N][N], int n) {
    int i, j;
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            a[i][j] = 0;
}

void print(int a[N][N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

int is_valid(int a[N][N], int x, int y, int n) {
    if ( x < n && y < n && x >= 0 && y >= 0 && a[x][y] == 0)   //valida que no se salga del tablero y que este libre
        return 1;
    return 0;
}

int solve_caballero(int a[N][N], int n, int x, int y, int nMov) 
{
     int i,new_x,new_y;

   //  printf("Movimiento : %d\n", nMov);
      if(nMov == n*n + 1)
        return 1;
      for ( i = 0; i < MAX_MOV; i++ ) 
      {
        new_x = x + m[i][0];
        new_y =  y + m[i][1];
        if ( is_valid(a, new_x, new_y, n) )    //valida que la posición sea valida
        {
            a[new_x][new_y] = nMov;
            if (solve_caballero(a, n, new_x, new_y, nMov+1 ))   //recursión y nuevo casillero
                return 1;
            
            a[new_x][new_y] = 0;                        // si no es valida la deja habilitada
        }             
       }
    
    return 0;
}
int main() {
    
    int n;
    //printf("Ingrese el tamanho de la tabla: ");
    //scanf("%d",&n);
    //printf("Ingrese las coordenadas iniciales: ");
    int x,y;
    //scanf("%d %d", &x, &y);
    n = 5;
    x = 0;
    y = 0;
    int table[N][N];
    generateMoves();   // posibles movimientos del caballo
    generateTable(table, n);    // limpia el tablero con 0
    table[x][y] = 1;
    int res = solve_caballero(table, n, x, y, 2);
    printf("Consiguio?? %d \n", res);
    print(table ,n);
    

    return (EXIT_SUCCESS);
}
