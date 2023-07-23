#include <stdio.h>
#define max 20

int robot(int x,int y,int n,int m,int tablero[][max]){
	int abajo=-999999,derecha=-99999;
	if (x==n-1 && y==n-1) return tablero[x][y];
	
	if (x+1<n) derecha = robot(x+1,y,n,m,tablero);
	if (y+1<m) abajo = robot(x,y+1,n,m,tablero);
	
	if (derecha<abajo) return abajo + tablero[x][y];
	else return derecha + tablero[x][y];
}

int main(){
	int tablero[][max]={
						{0,3,1},
						{2,7,6},
						{20,5,4}};
	int n=3,m=3,i,j;
	printf("%d ",robot(0,0,n,m,tablero));
	return 0;
}


