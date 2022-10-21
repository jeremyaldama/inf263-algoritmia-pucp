#include <stdio.h>

void intercambia(int i, int j,int lista[])
{   int aux;
    
    aux = lista[i];
    lista[i]=lista[j];
    lista[j]=aux;
}

void bubblesort(int ini,int fin,int lista[])
{   int i;
    if(ini==fin)
        return;

    for(i=0;i<fin;i++)
        if(lista[i]>lista[i+1])
            intercambia(i,i+1,lista);
    bubblesort(ini,fin-1,lista);
}

int main()
{	int i,n=8;
	int lista[]={2,1,7,4,8,6,3,15};
	
	bubblesort(0,n-1,lista);
	for(i=0;i<n;i++)
		printf("%d ",lista[i]);
	
	return 0;
}


