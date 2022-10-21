#include <stdio.h>
#include <math.h>
#define max 8

void cargabin(int num,int cromo[])
{	int i=0,j,res;

	for(j=0;j<max;j++)cromo[j]=0;
	
	while(num>0)
	{
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}

int main()
{	int art[][2]={{8,10},{2,20},{1,5},{4,9},{5,8},{5,5},{10,10},{4,6}};
	int i,j,parcial,valor,mvalor=0;
	int n=8,peso=25,mcomb,comb,tgana=0,tpeso=0;
	int cromo[max];
	comb=pow(2,n);
		
	for(i=0;i<comb;i++)
	{	parcial=0;
		valor=0;
		cargabin(i,cromo);
			
		for(j=0;j<max;j++)
		{
			if(cromo[j]==1)
			{   
				parcial=parcial+art[j][0];
				valor=valor+art[j][1];
			}
		
		}
		if(parcial<=peso && mvalor<valor)
		{
			mvalor=valor;
			mcomb=i;
		}	
	}
	cargabin(mcomb,cromo);
	for(j=0;j<max;j++)
	{
		printf("%d ",cromo[j]);
		if(cromo[j]==1)
		{   tgana=tgana+art[j][1];
		    tpeso=tpeso+art[j][0];
		}
	}
		
	printf("\n %d\n Peso: %d \n Ganancia: %d\n",mcomb,tpeso,tgana);
	
	return 0;
	
}
