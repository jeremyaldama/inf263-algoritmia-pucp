
#include <stdio.h>
#define MAX 10

int lista[MAX];
int x=0,y=0;

int valida(int n,int pre[],int pro[]){
	int i;
	if (pre[n]==-1)
		return 1;
	for(i=0;i<=n;i++)
		if(pre[n]!=lista[i])
			return 0;
	return 1;
}


int empaca(int i,int n,int peso,int p[],int pre[],int proy[])
{	int valor;
	if(i>=n||peso<0)
		return 0;
	if(p[i]==peso && valida(i,pre,proy) )
	{
	//	printf("F: %d ",p[i]);
		lista[y]=proy[i];
		int k;
		printf("Resultado:");
		for(k=0;k<=y;k++)
			printf("P%d ",lista[k]);
			
		x++;

		printf("\n");
		if(x!=1) return 0;

	}
    //printf("%d %d %d %d\n",i,p[i],peso,peso-p[i]);
	lista[y++]=proy[i];
	//printf("%d \n ",p[i]);
	if(empaca(i+1,n,peso-p[i],p,pre,proy) && valida(i,pre,proy))
	{
		//printf("%d ",p[i]);
		return 1;
	}
	else{
		y--;  //back aqui retrocede
		//printf("Back:%d \n",p[i]);
		return(empaca(i+1,n,peso,p,pre,proy));
	
	}
}

int main()
{	int proye[]={ 0, 1, 2, 3, 4, 5, 6, 7};
	int costo[]={ 7, 1, 3, 2, 4, 5, 1, 5};
	int prede[]={-1,-1, 1,-1, 2, 4,-1, 6};
	int n=8;
	int presupuesto=6;
	empaca(0,n,presupuesto,costo,prede,proye);
	if(x)
		printf("\nHay solucion");
	else	
		printf("\nNo hay solucion");

	return 0;
}


