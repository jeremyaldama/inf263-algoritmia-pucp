#include <stdio.h>

void despide(int A[],int B[],int C[],int ini,int fin,int act,int tiempo,int tard)
{	int med;
	
	if(ini==fin)
	{
		if(act-A[ini]>=tiempo)
			if(B[ini]>=tard)
				printf("\n%d %d",C[ini],A[ini]);
		return;
	
	}
	med=(fin+ini)/2;
	/*La complejidad sigue siendo n en el peor de los casos en el mejor es log(n) */
	/* 2000 2008 2010 2014 2016 2019, antiguedad de 21*/
	/* 2020-2000= 20  20>=21 No falso 2020-2010= 10 >=21   */
	if(act-A[ini]>=tiempo)
		despide(A,B,C,ini,med,act,tiempo,tard);
	if(act-A[med+1]>=tiempo)
		despide(A,B,C,med+1,fin,act,tiempo,tard);
}


int main()
{	int n=3,actual=2020,ant=10,tard=6;
	int anho[]={2000,2008,2015};
	int falta[]={1,8,6};
	int codigo[]={1000,1021,1317};
	
	despide(anho,falta,codigo,0,n-1,actual,ant,tard);
	return 0;
}
