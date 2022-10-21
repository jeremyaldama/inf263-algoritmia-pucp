
#include <stdio.h>

int buscamin(int arreglo[],int ini,int fin)
{
	int medio,izq,der;
	
	medio=(fin+ini)/2;

	if(medio==ini){
			if(arreglo[ini]<arreglo[fin])
				return arreglo[ini];
		else
			return arreglo[fin];
	}
	else{
			
			izq=buscamin(arreglo,ini,medio-1); //0,0
			der=buscamin(arreglo,medio,fin); //2,2
			if(izq<der)
				return izq;
			else
				return der;
	}
	
}




int main()
{
	int n=3;
	int arreglo[]={2,-5,-1};
	
	printf("%d",buscamin(arreglo,0,n-1));
	
	return 0;
}
