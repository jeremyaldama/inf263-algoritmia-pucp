#include <stdio.h>
#define MAX_MOV 8
#define n 5
#define m 8

int mov[8][2];//se puede tener 8 movimientos, y cada mov tiene una coordenada
const int c=3;
int tabla[n][m];
int num_rectangulo = 1;

void CargarMovimientos(){
	mov[0][0] = -1 ; mov[0][1] = -1;
	mov[1][0] =  0 ; mov[1][1] = -1;
	mov[2][0] =  1 ; mov[2][1] = -1;
	mov[3][0] =  1 ; mov[3][1] =  0;
	mov[4][0] =  1 ; mov[4][1] =  1;
	mov[5][0] =  0 ; mov[5][1] =  1;
	mov[6][0] = -1 ; mov[6][1] =  1;
	mov[7][0] = -1 ; mov[7][1] =  0;
}

void CargarTabla(){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            tabla[i][j] = 0;
        }
    }
}

int EstaLibre(int x, int y){
    return tabla[x][y]!=0;
}

void BackTracking(int x, int y, int num_mov, int i){
    if (x>=n || y>=m || x<0 || y<0){
        return;
    }

    int j;
    if (num_mov==c){
        num_rectangulo++;
        for (j=0; j<MAX_MOV; j++){
            int x_new = x + mov[j][0];
            int y_new = y + mov[j][1];
            if (EstaLibre(x_new, y_new)){
                BackTracking(x_new, y_new, 0, mov[j][1]);
            }
        }
    }

    //son 2 direcciones: para abajo y derecha
    //0 = abajo
    //1 = derecha
    if (i==0){
        num_mov++;
        tabla[x][y] = num_rectangulo;
        BackTracking(x+1, y, num_mov, 0);
        num_mov = 0;
        tabla[x][y] = 0;
    }

    else{
        num_mov++;
        tabla[x][y] = num_rectangulo;
        BackTracking(x, y+1, num_mov, 1);
        num_mov = 0;
        tabla[x][y] = 0;
    }
    
    return;
}

int main(){
    CargarMovimientos();
    CargarTabla();
    BackTracking(0, 0, 0, 0);
    printf("Total de rectangulos = %d\n", num_rectangulo);
    return 0;
}