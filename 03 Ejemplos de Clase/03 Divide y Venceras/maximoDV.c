
#include <stdio.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
	
}


int maximo(int arreglo[],int ini,int fin)
{
	int medio;
	
	medio=(fin+ini)/2;

	if(medio==ini){
			if(arreglo[ini]<arreglo[fin])
				return arreglo[fin];
		else
			return arreglo[ini];
	}

			return max(maximo(arreglo,ini,medio-1),maximo(arreglo,medio,fin));			
		
}
int main()
{
	int n=3;
	int arreglo[]={2,-5,-1};
	
	printf("%d",maximo(arreglo,0,n-1));
	
	return 0;
}
