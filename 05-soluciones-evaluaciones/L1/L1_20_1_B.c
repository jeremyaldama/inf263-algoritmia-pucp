#include <stdio.h>
#include <math.h>

int main(){
	FILE *arch = fopen("L1_20_1_B_Datos.txt","r");
	int numPerEst, radio;
	
	fscanf(arch,"%d %d",&numPerEst,&radio);
	//			     est coord
	int perEst[numPerEst][3]; 
	int i = 0;
	while (i < numPerEst){//    		  est	  X				 Y
		fscanf(arch, "%d %d %d",&perEst[i][0],&perEst[i][1],&perEst[i][2]);
		i++;
	}
	int numPos;
	fscanf(arch, "%d",&numPos);
	i = 0;
	int movPer[numPos][2];
	while (i < numPos){
		fscanf(arch,"%d %d", &movPer[i][0], &movPer[i][1]);
		i++;
	}
	int k = 0;
	double distancia;
	i = 0;
	double contagio[numPos][numPerEst][2];
	while (i < numPos){
		k = 0;
		while (k < numPerEst){// (y2 - y1)^2
			if (perEst[k][0]){//solo si esta contagiada
				distancia = sqrt(pow(perEst[k][2] - movPer[i][1], 2) + 
								 pow(perEst[k][1] - movPer[i][0], 2));
				if (distancia <= radio){
					contagio[i][k][0] = 1;
					contagio[i][k][1] = distancia;
				}
			}
			k++;
		}
		i++;
	}
	for (i = 0; i < numPos; i++)
		for (k = 0; k <numPerEst; k++)
			if ((int)contagio[i][k][0])
				printf("Persona podria haberse contagiado en su movimiento %d por la persona %d con nivel de cercania %lf\n", i+1,k+1, contagio[i][k][1]);		
	return 0;
}
