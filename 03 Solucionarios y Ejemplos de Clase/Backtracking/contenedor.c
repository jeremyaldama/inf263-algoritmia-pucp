#include <stdio.h>
int elem=0;

int empaca(int i,int n,int m,int peso,int p[])
{	int valor;
	if(i>=n ||peso<0)
		return 0;
	elem++;
	if(elem==m && peso-p[i]>=0)
	{
		printf("%d ",p[i]);
		return 1;
	}
    
	//printf("%d %d %d %d\n",i,p[i],elem,peso-p[i]);
   
	if(empaca(i+1,n,m,peso-p[i],p))
	{
		printf("%d ",p[i]);
		return 1;
	}
	else{
		elem--;
		return(empaca(i+1,n,m,peso,p));
	}
	
}

int main()
{
	int paq[]={8,2,1,4,5,5,10,4,3,1};
	int m=8,n=10;
	int peso=25;
	if(empaca(0,n,m,peso,paq))
		printf("\nHay solucion");
	else	
		printf("\nNo hay solucion");

	return 0;
}


