#include <stdio.h>
#include <math.h>
#define N 100

int productos[N];
int lista[][4]={
			{100,4,8,2},
			{101,2,10,2},	
			{102,3,12,2},
			{103,1,13,2},
			{104,3,15,1},
			{105,1,10,2},
			{106,4,16,1},
			{107,2,8,2},
			{108,3,14,1},
			{109,2,18,2},
			{110,1,18,2},
			{111,4,14,2}
			};

void cargabin(int cromo[],int num,int max)
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
{	int i,j,k,p1,p2,p3,p4,cruce,comb,m=12;
	int cromo[m],horario[24];
	
	comb = pow(2,m);
	for(i=0;i<comb;i++)
	{
		cargabin(cromo,i,m);
		for(k=0;k<24;k++)
			horario[k]=0;
		p1=0;p2=0;p3=0;p4=0;
		cruce=0;
		for(j=0;j<m;j++)
		{
			if(cromo[j]==1)
			{
				switch(lista[j][1]){
					case 1: p1++; break;
					case 2: p2++; break;
					case 3: p3++; break;
					case 4: p4++;
				}
				for(k=lista[j][2];k<lista[j][2]+lista[j][3];k++ )
				{
					if(horario[k]==0)
						horario[k]=1;
					else
					{	cruce=1;
						break;
					}
				}
				if(cruce==1)		
					break;
			}
		}	
		if(p1>=2 && p2>=2 && p3>=1 && p4>=1 && cruce==0)
		{
			printf("\n%d",i);
			for(j=0;j<m;j++)
				if(cromo[j]==1)
					printf("\n%d %d",lista[j][0],lista[j][1]);
		}
	}
	return 0;
}



