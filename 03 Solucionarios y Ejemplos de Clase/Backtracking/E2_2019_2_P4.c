#include <stdio.h>

int viaja(int i,int j,int n,int ruta[8][8])
{	int x;
    
     if(n==j+1 && ruta[i][j]==1)
     {
         printf("%d %d %d \n",i,j,ruta[i][j]);
         return 1;
     }
        
    if( ruta[i][j]==1 && i!=j)
    {
        printf("%d %d %d \n",i,j,ruta[i][j]);
	i=j;
	j=0;
    }
    else
    {
        for(x=j;x<n;x++)
            if(ruta[i][x]==1)
            {
                break;
            }
        j=x;    
     }
 
   if(i>=n|| j>=n)
        return 0;

    if(i==j) j++;

//    printf("%d %d \n",i,j);
    if(viaja(i,j,n,ruta))
    {
	 //printf("%d %d %d \n",i,j,ruta[i][j]);
    	return 1;
    }
    else
    {	printf("Back: %d %d\n",i,j+1);
	return(viaja(i,j+1,n,ruta));
    }
	
}

int main()
{
	int ruta[8][8]={{0,1,0,1,1,0,0,0},
					{0,0,1,0,0,1,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}
			};
	int n=8;
	printf("%d",viaja(0,0,n,ruta));


	return 0;
}



