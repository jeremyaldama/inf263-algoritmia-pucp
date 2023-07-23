/*SE UTILIZA LA ESTRATEGIA DEL CROMOSOMO PARA EVALUAR TODOS LOS
  POSIBLES CASOS DE LLENAR LA MOCHILA Y LUEGO FILTRAR LOS PESOS Y GANANCIAS
  QUE SON POSIBLES
|				*/
#include <stdio.h>
#include <math.h>
void convertirBinario(int num,int cromo[]);

int main(){
	int paquete[][2] = {{8,15},{2,20},{10,5},{10,10},{5,8},{5,5}};
	int n=6,opciones,i;
	opciones = (int)pow(2,n);
	int valor,mejorValor=0,pesoDef=25,pesoParcial,gananciaParcial;
	int cromo[n],cromoMax[n];
	int k,gananciaMax=0;
	
	for (i=0;i<opciones;i++){
		convertirBinario(i,cromo);
		pesoParcial = 0;
		gananciaParcial = 0;
		for (k=0; k<n; k++){
			if (cromo[k]==1){
				pesoParcial += paquete[k][0];
				gananciaParcial += paquete[k][1];
			}
		}
		if (pesoParcial<=pesoDef && gananciaParcial>gananciaMax){
			for (k=0; k<n; k++){
				cromoMax[k] = cromo[k];
			}
			gananciaMax = gananciaParcial;
		}
	}
	for (k=0; k<n; k++) if (cromoMax[k]==1) printf("%d ",k+1);
	printf("GANANCIA MAX: %d",gananciaMax);
	return 0;
}

void convertirBinario(int num,int cromo[]){
	int resto,i=5;
	
	while (num>0){
		resto = num%2;
		num /= 2;
		cromo[i] = resto;
		i--;
	}
}
