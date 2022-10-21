#include <stdio.h>
#include <math.h>
#define max 5

void cargabin(int num,int cromo[])
{	int i=0,j,res;

	for(j=0;j<max;j++)cromo[j]=0;
	while(num>0)
	{	res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}

int main()
{	int art[][2]={{0,1},{1,2},{2,4},{3,12},{4,1}};
	int i,j,parcial;
	int peso=15,mpeso=0,mcomb,tpeso=0;
	int cromo[max];
		
	for(i=0;i<pow(2,max);i++)
	{	parcial=0;
		cargabin(i,cromo);
			
		for(j=0;j<max;j++)
			if(cromo[j]==1)
				parcial=parcial+art[j][1];
		
		if(parcial<=peso && mpeso<=parcial)
		{		mpeso=parcial;
				mcomb=i;
		}
	}
	cargabin(mcomb,cromo);
	for(j=0;j<max;j++)
	{
		printf("%d ",cromo[j]);
		if(cromo[j]==1)
		    tpeso=tpeso+art[j][1];

	}
	printf("\n %d\n Peso: %d  Resto:%d \n ",mcomb,tpeso,peso-tpeso);
	
	return 0;
}
