#include <stdio.h>

int cont=0;

int divide(int i,int n,int k,int prod,int p[])
{	int valor;
	if(i>=n||prod>k)
		return 0;
	if(i<n && prod*p[i]<k) 
	{
		cont++;
		printf("%d ",prod);
	}
	
    if(divide(i+1,n,k,prod*p[i],p))
	{
		return 1;
	}
	else{
		return(divide(i+1,n,k,prod,p));
	}
	
}

int main()
{
	//int lista[]={4,8,7,2};
	int lista[]={1,2,3,4};
	int i,n=4;
	int prod,k=10;
	
	
	divide(0,n,k,1,lista);
	printf("Numero: %d\n",cont);
	

	
	if(cont==0)
		printf("\nNo hay solucion");
	else	
		printf("\nSi hay solucion");

	return 0;
}


