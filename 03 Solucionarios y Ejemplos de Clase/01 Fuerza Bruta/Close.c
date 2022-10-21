#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distancia(int x[],int y[])
{   double dist;

    dist = sqrt(pow(x[0]-y[0],2)+pow(x[1]-y[1],2));
    return dist;
}
  
double brute_force(int punt[4][2],int n,double mindist,int par[])
{
    int i,j,a,b;
    double d;
    
    for(i=0;i< n; i++) 
    {
        for (j = i + 1; j <= n; j++) 
        {
                        d= distancia(punt[i],punt[j]);
                        if (d<=mindist) 
                        {a=i;
                         b=j;
                         mindist=d;
                        }
        }
    }
    par[0]=a;
    par[1]=b;        
    return mindist;
}


#define NP 8

int main()
{
    double dmenor;
    int par[2];
    int puntos[4][2]= {{2,1},{4,2},{12,15},{9,13}};
    
    dmenor= distancia(puntos[0],puntos[1]);
    dmenor =brute_force(puntos,4,dmenor,par); 
    
    printf("Par: %i %i Distancia:%0.2lf \n",par[0],par[1],dmenor);
    
    return 0;
}