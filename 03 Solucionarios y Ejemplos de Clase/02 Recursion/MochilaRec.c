#include <stdio.h>
#include <math.h>


void cargabin(int num,int n,int cromo[])
{	int i=0,j,res;

	for(j=0;j<n;j++)cromo[j]=0;
	
	while(num>0)
	{
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}

void evalua(int comb,int n,int peso,int art[][2],int *mvalor,int *mpeso,int *mcomb)
{	int j,parcial,valor;
	int cromo[n];

	if(comb==0)
		return;
	else{
		parcial=0;
		valor=0;
		cargabin(comb,n,cromo);
		for(j=0;j<n;j++)
			if(cromo[j]==1)
			{   
				parcial=parcial+art[j][0];
				valor=valor+art[j][1];
			}
		evalua(comb-1,n,peso,art,mvalor,mpeso,mcomb);
		if(parcial<=peso && *mvalor<valor)
		{
			*mvalor=valor;
			*mcomb=comb;
			*mpeso= parcial;
		}
		
	}
}


int main()
{	int art[][2]={{8,10},{2,20},{1,5},{4,9},{5,8},{5,5},{10,10},{4,6}};
	int i,parcial,valor,mvalor=0;
	int n=8,peso=25,mcomb,comb,tgana=0,tpeso=0;
	int cromo[n];
	comb=pow(2,n);
	evalua(comb,n,peso,art,&tgana,&tpeso,&mcomb);	
	cargabin(mcomb,n,cromo);
	for(i=0;i<n;i++)
		printf("%d ",cromo[i]);
	printf("\n %d\n Peso: %d \n Ganancia: %d\n",mcomb,tpeso,tgana);
	
	return 0;
	
}

