#include <stdio.h>

int cuenta(int arr[],int ini, int n)
{
	int medio,cont=0;

	medio=(n+ini)/2;	

	if(ini>=n)
    {    
		if(arr[ini]==0)	return 1;
                if(arr[ini]!=0) return 0;
	}
	else 
	{   
		cont=cont+cuenta(arr,ini,medio);
		cont=cont+cuenta(arr,medio+1,n);
		return cont;
	}		
}


int main()
{	int arreglo[]={0,0};
	int n=2;
	
        printf("Resultado: %d",cuenta(arreglo,0,n-1));
	
	return 0;
}
