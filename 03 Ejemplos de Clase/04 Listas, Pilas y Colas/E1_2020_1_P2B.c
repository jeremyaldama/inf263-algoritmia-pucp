#include <stdio.h>		
#define max 100


//Solucion para rectangulos o cuadrados n x m
int robot(int x,int y,int n,int m,int tablero[][max],int alt,int *p)
{	int abajo=-999999,derecha=-999999,total=0;
	int pd=0,pa=0,local=0;
	
	if(x==n-1 && y==m-1)
	{	*p=0;
		if(tablero[x][y]>=alt)
		{	*p=x+y;
			return tablero[x][y];
		}
	} 
	if(x<n-1)
	{
		derecha=robot(x+1,y,n,m,tablero,alt,&pd);
		if (derecha>=alt)
			derecha = pd*100+derecha;
		else
			derecha =0;	
	}
	if(y<m-1)	
	{	abajo=robot(x,y+1,n,m,tablero,alt,&pa);
		if (abajo>=alt)
			abajo = pa*100+abajo;
		else
			abajo=0;
	}
	if(derecha<abajo)
		total = abajo;
	else
		total = derecha;
	
	if(tablero[x][y]>=alt)
		local=(x+y)*100+tablero[x][y];
	else
		local=0;	
	
	if(total > local)
	{	*p=total/100;
		total = total%100;
	}
	else
	{	*p=local/100;
		total = local%100;
	}
	return total;
}

int main()
{	int i,j,n,m,pasos=0,alto;
	int tablero[max][max];
	printf("Ingrese n,m y t:");
	scanf("%d %d %d",&n,&m,&alto);
	printf("Ingrese tablero:\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&tablero[i][j]);
		
	printf("Espacio:%d\n",robot(0,0,n,m,tablero,alto,&pasos));
	printf("Pasos:%d",pasos);
	return 0;
}


