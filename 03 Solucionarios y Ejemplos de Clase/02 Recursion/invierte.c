#include <stdio.h>

void invierte(int ini,int fin,int lista[])
{	int aux;

	if(ini>fin)
		return;
	else
	{
		aux=lista[ini];
		lista[ini]=lista[fin];
		lista[fin]=aux;
		invierte(ini+1,fin-1,lista);
	}	
}

int main()
{	int i,n=8;
	int lista[]={1,2,3,4,5,6,7,8};
	
	for(i=0;i<n;i++)
		printf("%d ",lista[i]);
	
	invierte(0,n-1,lista);	
	printf("\n");	
	for(i=0;i<n;i++)
		printf("%d ",lista[i]);
}
