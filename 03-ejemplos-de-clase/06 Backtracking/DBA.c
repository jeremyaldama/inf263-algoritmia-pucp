
#include <stdio.h>

int cont=0,soluciones[100][100];
// xyz  = x*100+ y*10+z

int esvalido(int x,int y,int z,int total)
{//valida
	int i;
	if(x==0 ||y==0|| z==0 || x>9 || y>9 || z>9 || x+y+z>total)
		return 0;
	if(x+y+z==total)
		for(i=0;i<=cont;i++)	
			if(soluciones[i][0]==x && soluciones[i][1]==y &&
				soluciones[i][2]==z)
				return 0;
	return 1;	
	
}

int busca(int x,int y,int z,int total)
{
	if(!esvalido(x,y,z,total))
		return 0;
	if(x!=y && x!=z && y!=z && x+y+z==total){
		soluciones[cont][0]=x;
		soluciones[cont][1]=y;
		soluciones[cont][2]=z;
		cont++;   //si sale correcto
		printf("%d %d %d\n",x,y,z);

	}	
		
		
	//back
	if(busca(x,y,z+1,total)){
		return 1;
	}
	else
		if(busca(x,y+1,z,total)){
			return 1;
		}
		else
			if(busca(x+1,y,z,total)){
				return 1;
			}
			
	
	
}


int main(){
	int total = 8;	
	busca(1,1,1,total);
}


