
#include <stdio.h>
#define MAX 10

int lista[MAX];
int x=0,y=0;

int empaca(int i,int n,int peso,int p[])
{	int valor;
	if(i>=n||peso<0)
		return 0;
	if(p[i]==peso)
	{
		printf("F: %d ",p[i]);
		lista[y]=p[i];
		int k;
		printf("Resultado:");
		for(k=0;k<=y;k++)
			printf("%d ",lista[k]);
			
		x++;

		printf("\n");
		if(x!=1) return 0;

	}
    //printf("%d %d %d %d\n",i,p[i],peso,peso-p[i]);
	lista[y++]=p[i];
	printf("%d \n ",p[i]);
	if(empaca(i+1,n,peso-p[i],p))
	{
		printf("%d ",p[i]);
		return 1;
	}
	else{
		y--;  //back aqui retrocede
		printf("Back:%d \n",p[i]);
		return(empaca(i+1,n,peso,p));
	
	}
}

int main()
{
	int paq[]={7,1,3,2,4,5};
	int n=6;
	int peso=7;
	empaca(0,n,peso,paq);
	if(x)
		printf("\nHay solucion");
	else	
		printf("\nNo hay solucion");

	return 0;
}


