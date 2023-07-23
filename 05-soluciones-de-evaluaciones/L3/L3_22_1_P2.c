#include <stdio.h>

int sumaPeso(int meteorito[2][3][4], int altI, int altF, int anchoI,
			 int anchoF,int largoI, int largoF){
	int i,j,k,sum=0;
	for (i=altI; i<=altF; i++){
		for (j=anchoI; j<=anchoF; j++){
			for (k=largoI; k<=largoF; k++){
				sum += meteorito[i][j][k];
			}
		}
	}					  	
	return sum;
}

void encontrarCubo(int meteorito[2][3][4], int*posicion, 
				  int altI, int altF, int anchoI, int anchoF,
				  int largoI, int largoF){
	if (altI==altF && anchoI==anchoF && largoI==largoF){
		posicion[0] = largoI;
		posicion[1] = anchoI;
		posicion[2] = altI;
		return;
	}
	int alt1, alt2, altMid = (altI+altF)/2;
	if (altI!=altF){
		alt1 = sumaPeso(meteorito, altI, altMid, anchoI, anchoF,
						  largoI, largoF);
		alt2 = sumaPeso(meteorito, altMid+1, altF, anchoI, anchoF,
						  largoI, largoF);
		if (alt1>alt2){
			encontrarCubo(meteorito, posicion, altI, altMid, anchoI,
						  anchoF, largoI, largoF);
		}
		else{
			encontrarCubo(meteorito, posicion, altMid+1, altF,
						  anchoI,anchoF, largoI, largoF);
		}
	}
	
	int ancho1, ancho2, anchoMid = (anchoI+anchoF)/2;
	if (anchoI!=anchoF){
		ancho1 = sumaPeso(meteorito, altI, altF, anchoI, anchoMid,
						  largoI, largoF);
		ancho2 = sumaPeso(meteorito, altI, altF, anchoMid+1, anchoF,
						  largoI, largoF);
		if (ancho1>ancho2){
			encontrarCubo(meteorito, posicion, altI, altF, anchoI,
						  anchoMid, largoI, largoF);
		}
		else{
			encontrarCubo(meteorito, posicion, altI, altF,
						  anchoMid+1,anchoF, largoI, largoF);
		}
	}
	
	int largo1, largo2, largoMid = (largoI+largoF)/2;
	if (largoI!=largoF){
		largo1 = sumaPeso(meteorito, altI, altF, anchoI, anchoF,
						  largoI, largoMid);
		largo2 = sumaPeso(meteorito, altI, altF, anchoI, anchoF,
						  largoMid+1, largoF);
		if (largo1>largo2){
			encontrarCubo(meteorito, posicion, altI, altF, anchoI,
						  anchoF, largoI, largoMid);
		}
		else{
			encontrarCubo(meteorito, posicion, altI, altF,
						  anchoI,anchoF, largoMid+1, largoF);
		}
	}
}

int main(){
	int largo=4, ancho=3, alt=2;
	int meteorito[][3][4] = {
									 {
									  {0,0,0,0},
									  {0,0,0,0},
									  {0,0,0,0}},
									  
									 {{0,0,0,0},
									  {0,0,1,0},
									  {0,0,0,0}}
									    };
	int posicion[3];
	encontrarCubo(meteorito, posicion, 0, alt-1, 0, ancho-1, 0, largo-1);
	printf("Posicion del cubo de vibranio: %d %d %d\n",
			posicion[0]+1, posicion[1]+1, posicion[2]+1);
	return 0;
}
