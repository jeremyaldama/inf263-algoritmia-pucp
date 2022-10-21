#include <stdio.h>

int N=6, M=6;
int tablero[][6] = {{0,0,0,1,0,1},
					{0,0,1,0,1,0},
					{0,1,0,0,0,1},
					{1,0,0,0,0,0},
					{0,1,0,0,0,0},
					{0,0,1,0,1,0}};

int contar(int x, int y, int dirX, int dirY, int N, int M, int BH, int BV){
	int cont=0;	
	if (x<0 || x>=N || y<0 || y>=M) return 0;
	if (tablero[x][y] && BH==0 && BV==0) return cont++;
	if (BH==0){
		int i;
		//derecha
		for (i=y+1; i<M; i++){
			cont = cont + tablero[x][i];
		}
		//izquierda
		for (i=y-1; i>=0; i--){
			cont += tablero[x][i];
		}
	}
	if (BV==0){
		int i;
		//arriba
		for (i=x-1; i>=0; i--){
			cont += tablero[i][y];
		}
		//abajo
		for (i=x+1; i<N; i++){
			cont = cont + tablero[i][y];
		}
	}
	cont += contar(x+dirX, y+dirY, dirX, dirY, N, M, dirY, dirX);
	return cont;
}

int main(){
	
	int cantidad;
	cantidad = contar(3, 2, 0, 1, N, M, 0, 0);					
	printf("Unidades encontradas: %d", cantidad);
	
	return 0;
}
