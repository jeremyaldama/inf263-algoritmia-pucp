#include <stdio.h>
#include <math.h>
void cargaBin(int num,int n,int*cromo);

int main(){
	int paquete[] = {18,2,4,12,17};//en kg cada uno
	int i, n=5,parcial=0,peso=15,pesoMayor=0;
	//son 5 opciones y podemos generar 2^5
	int opcion = (int)pow(2,n);
	int cromo[n], j, combMayor;
	
	for(i=0; i<opcion; i++){

		cargaBin(i,n,cromo);//toma el número i y lo vuelve binario en cromo
		for (j=0, parcial=0;j<n;j++){
			parcial = parcial + paquete[j]*cromo[j];
		}
		if (parcial<=peso && parcial>=pesoMayor){//toma la 1era mejor solucion
			pesoMayor = parcial;				//>= para que tome la ultima
			combMayor = i;						//mejor solución
		}
	}
	printf("Peso: %d Comb: %d",pesoMayor,combMayor);
	return 0;
}

void cargaBin(int num,int n,int*cromo){
	int k,res;
	for (k=0;k<n;k++) cromo[k]=0;//0 0 0 0 0
	k=0;
	while (num>0){
		res = num%2;
		num = num/2;
		cromo[k] = res;
		k++;
	}
}
