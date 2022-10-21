#include <stdio.h>
#include <math.h>

int min(int a, int b)
{
	if(a<b)
		return a;
    else
		return b;		
	
}

int max(int a, int b)
{
	if(a>b)
		return a;
    else
		return b;		
	
}

int verificaalf(int n,int pos,int xp,int yp, int xr, int yr,int pieza[][2
])
{
	int i;
	
	for(i=0;i<n;i++)
	{
		if(i!=pos)
			if((fabs(xp - pieza[i][0]) == fabs(yp - pieza[i][1])) 
                            && ( pieza[i][1] > min(yp,yr) && pieza[i][1]<max(yp,yr)) 
			    && ( pieza[i][0] > min(xp,xr) && pieza[i][0]<max(xp,xr))) 
			
                            return 0;
	}
	return 1;

}


int ataquealfil(int n,int pos,int xp, int yp, int xr, int yr,int pieza[][2]) 
{ 
    if (fabs(xp - xr) == fabs(yp - yr)) 
 		if (verificaalf(n,pos,xp,yp,xr,yr,pieza))
        	return 1; 
  
    return 0; 
} 

int verificath(int n,int pos,int xp,int yp, int xr, int yr,int pieza[][2])
{
	int i;
	
	for(i=0;i<n;i++)
	{
		if(i!=pos)
			if((xp == pieza[i][0]) && ( pieza[i][1] > min(yp,yr) && pieza[i][1]<max(yp,yr))) 
				return 0;
	}
	return 1;

}

int verificatv(int n,int pos,int xp,int yp, int xr, int yr,int pieza[][2])
{
	int i;
	
	for(i=0;i<n;i++)
	{
		if(i!=pos)
			if(yp==pieza[i][1] && ( pieza[i][0]>min(xp,xr) && pieza[i][0]<max(xp,xr))) 
				return 0;
	}
	return 1;

}


int ataquetorre(int n,int pos,int xp, int yp, int xr, int yr,int pieza[][2]) 
{ 
    if (xp == xr) 
    	if (verificath(n,pos,xp,yp,xr,yr,pieza))
        	return 1; 
  
    if (yp == yr) 
    	if(verificatv(n,pos,xp,yp,xr,yr,pieza))
        return 1; 
  	
	return 0; 
} 
  

int ataquecaballo(int n,int pos,int xp, int yp, int xr, int yr,int pieza[][2]) 
{ 
 	int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
    int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
    int i,x,y,count = 0; 
  
        for (i = 0; i < 8; i++) 
		{ 
  	    	x = xp + X[i]; 
    	    y = yp + Y[i]; 
  
        	if (x == xr && y == yr)
				return 1; 
    	}	 
	return 0;
}

int main()
{
	int i,n,suma=0;
	int xr,yr;
	
	printf("Ingrese el numero de piezas negras:");
	scanf("%d",&n);
	
	printf("Ingrese la posicion x y del rey:");
	scanf("%d %d",&xr,&yr);
	
	char cod[n];
    int pieza[n][2];
	
	printf("Piezas y posiciones:\n");
	for(i=0;i<n;i++)
	{
            scanf(" %c", &cod[i]);
            scanf("%d %d",&pieza[i][0],&pieza[i][1]);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////
	for(i=0;i<n;i++)
	{   
		if(cod[i]=='A')
			suma = suma + ataquealfil(n,i,pieza[i][0],pieza[i][1],xr,yr,pieza);
		if(cod[i]=='T')
			suma = suma + ataquetorre(n,i,pieza[i][0],pieza[i][1],xr,yr,pieza);
		if(cod[i]=='C')	
			suma = suma + ataquecaballo(n,i,pieza[i][0],pieza[i][1],xr,yr,pieza);
		
	}
	if(suma>0)
		printf("Se lo come");
	else 
		printf("No se lo come");		
		
}
