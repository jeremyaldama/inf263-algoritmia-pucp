//Jeremy Aldama Giraldo (20206228)
//Estrategia utilizada: Backtracking 
#include <stdio.h>
#define n 5
#define m 5

int mov[8][2];
const int c=3;
int tabla[n][m];
int num_rectangulo = 1;
int max_rectangulos = -99999;

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
    return x>=0 && y>=0 && x<n && y<m && tabla[x][y] == 0;
}

void BackTracking(int x, int y){
    int i, j, z;
    
    if (num_rectangulo>max_rectangulos){
            max_rectangulos = num_rectangulo;
            for (i=0; i<n; i++){
                for (j=0; j<m; j++){
                    printf("%d ", tabla[i][j]);
                }
                printf("\n");
            }
            printf("\n");
    }

    if (x<0 || y<0 || x>=n || y>=m){
        return;
    }

    int fin=0;
    for (i=0; i<4; i++){
        //vertical abajo
        if (i==0){
            for (j=x, z=0; z<c; j++, z++){
                if (!EstaLibre(j, y)){
                    fin = 1;
                    break;
                }
                tabla[j][y] = num_rectangulo;
            }
            x += (c-1);
            num_rectangulo++;
        }
        //horizontal derecha
        else if (i==1){
            for (j=y, z=0; z<c; j++, z++){
                if (!EstaLibre(x, j)){
                    fin = 1;
                    break;
                }
                tabla[x][j] = num_rectangulo;
            }
            y += (c-1);
            num_rectangulo++;
        }
        //horizontal izquierda
        else if (i==2){
            for (j=y, z=0; z<c; j--, z++){
                if (!EstaLibre(x, j)){
                    fin = 1;
                    break;
                }
                tabla[x][j] = num_rectangulo;
            }
            y -= (c-1);
            num_rectangulo++;
        }
        //vertical arriba
        else{
            for (j=x, z=0; z<c; j--, z++){
                if (!EstaLibre(j, y)){
                    fin = 1;
                    break;
                }
                tabla[j][y] = num_rectangulo;
            }
            x -= (c-1);
            num_rectangulo++;
        }

        if (!fin){
            for (j=0; j<8; j++){
                int new_x = x + mov[j][0];
                int new_y = y + mov[j][1];
                if (tabla[new_x][new_y] == 0){
                    BackTracking(new_x, new_y);
                }
            }
        }
        
        //vertical abajo
        if (i==0){
            x -= (c-1);
            num_rectangulo--;
            for (j=x, z=0; z<c; j++, z++){
                if (tabla[j][y]==num_rectangulo) tabla[j][y] = 0;
            }
        }
        //horizontal derecha
        else if (i==1){
            y -= (c-1);
            num_rectangulo--;
            for (j=y, z=0; z<c; j++, z++){
                if (tabla[x][j]==num_rectangulo) tabla[x][j] = 0;
            }
        }
        //horizontal izquierda
        else if (i==2){
            y += (c-1);
            num_rectangulo--;
            for (j=y, z=0; z<c; j--, z++){
                if (tabla[x][j]==num_rectangulo) tabla[x][j] = 0;
            }
        }
        //vertical arriba
        else{
            x += (c-1);
            num_rectangulo--;
            for (j=x, z=0; z<c; j--, z++){
                if (tabla[j][y]==num_rectangulo) tabla[j][y] = 0;
            }
        }
        fin = 0;
    }
    return;
}

int main(){
    CargarMovimientos();

    CargarTabla();
    
    BackTracking(0, 0);
    printf("Total de rectangulos = %d\n", max_rectangulos-1);
    return 0;
}
