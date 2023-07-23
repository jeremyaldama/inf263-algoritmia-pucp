
#include <stdio.h>
#define max 20

int robot(int x,int y,int n,int m,int tablero[][max]){
	int abajo,derecha;
	if (x==n-1 && y==n-1) return tablero[x][y];
	
	derecha = robot(x+1,y,n,m,tablero);
	abajo = robot(x,y+1,n,m,tablero);
	
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


