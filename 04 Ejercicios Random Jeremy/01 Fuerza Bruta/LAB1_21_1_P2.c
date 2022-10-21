#include <stdio.h>
#include <math.h>
#define MAX 4

void convertirBinario(int num,int max,int cromo[]){
	int i=0,j,res;

	for(j=0;j<max;j++) cromo[j]=0;
	
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}

int main(){
	int almacen[][MAX] = {{2,5,6,10},
						  {7,8,15,3},
						  {11,9,6,4}};
	int i,j,k,l,n=4,m=5,cap=20,peso,contDiv;
	int opcion = (int)pow(2,n);
	int cromo1[n],cromo2[n],cromo3[n],fin=0;
	
	for (i=0;i<opcion;i++){//1era bahia
		convertirBinario(i,n,cromo1);
		for (j=0;j<opcion;j++){//2da bahia
			convertirBinario(j,n,cromo2);
			for (k=0; k<opcion; k++){ //3ra bahia
				peso = 0;
				contDiv = 0;
				convertirBinario(k,n,cromo3);
				for (l=0; l<n; l++){
					if (cromo1[l]){
						contDiv++;
						peso += almacen[0][l];
					}
					if (cromo2[l]){
						contDiv++;
						peso += almacen[1][l];
					}
					if (cromo3[l]){
						contDiv++;
						peso += almacen[2][l];
					}
				}
				if (peso==cap && contDiv==m){
					printf("BAHIA 1: ");
					for (l=0;l<n;l++)
						if (cromo1[l])
							printf("%d ",almacen[0][l]);
					printf("BAHIA 2: ");
					for (l=0;l<n;l++)
						if (cromo2[l])
							printf("%d ",almacen[1][l]);
					printf("BAHIA 3: ");
					for (l=0;l<n;l++)
						if (cromo3[l])
							printf("%d ",almacen[2][l]);
					fin=1;
					break;
				}
			}
			if (fin) break;
		}
		if (fin) break; 
	}
	if (fin==0) printf("NO HAY SOLUCION");
	return 0;
}
