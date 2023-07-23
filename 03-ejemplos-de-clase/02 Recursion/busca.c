#include <stdio.h>


int buscanum(int lista[],int ini,int n,int numero)
{
	if(ini==n)
		return -1;	
	if(lista[ini]==numero)
		return ini;
	else
		buscanum(lista,ini+1,n,numero);
}

int main()
{
	int arreglo[]={2,3,5,1};
	
	printf("%d",buscanum(arreglo,0,4,5));
	
}

