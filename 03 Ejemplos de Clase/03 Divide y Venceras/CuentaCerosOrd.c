#include <stdio.h>
/* 0000111 contar la cantidad 0's en la lista */
/* Ahora en una lista ordenada debe tener complejidad log(n) */

int cuenta(int arreglo[],int ini,int fin,int cont)
{
	int medio;
	medio = (ini+fin)/2;
	
	if(ini>fin)
		return cont; //1
		
	if(arreglo[medio]==0)
		return cuenta(arreglo,medio+1,fin,cont+medio-ini+1);
	else	
		return cuenta(arreglo,ini,medio-1,cont);
}



int main()
{
	int  n=7;
	int arreglo[]={0,0,0,0,1,1,1};
	
	printf("%d",cuenta(arreglo,0,n-1,0));
	
}
