#include <stdio.h>
#define max 100

int robot(int x,int y,int n, int m,int tablero[][max])
{	int abajo=-999999, derecha=-999999,total;
	if(x==n-1 && y==m-1)   //0,0
		return tablero[x][y];
	
	if(x<n-1)	  //
		derecha=robot(x+1,y,n,m,tablero); //1,0
	if(y<m-1)  //
		abajo=robot(x,y+1,n,m,tablero);   //0,1
	
	if(derecha<abajo)	
		total = tablero[x][y]+abajo;
	else
		total = tablero[x][y]+derecha;
	return total;	
			
}

int main()
{	int i,j,n,m;
	int tablero[max][max];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&tablero[i][j]);
	
	
	
	printf("%d",robot(0,0,n,m,tablero));
	
}
