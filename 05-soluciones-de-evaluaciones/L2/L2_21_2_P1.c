#include <stdio.h>
#include <math.h>

typedef struct{
	int percentage;
	int costConsult[7];
	int areEconom;
	int quantConsult;
} Fase;

int elegirConsultoras(Fase, int ,int, int *, int*, int*, int);
void calcularMontoYCantidadDeConsultoras(Fase, int*, int, int*, int*);

int numFases=7, numConsultoras=7, presupuesto=200000;

void cargaBin(int*arr, int num, int indice){
	if (indice==numConsultoras) return;
	arr[numConsultoras-1-indice] = num&1;
	cargaBin(arr, num>>=1, indice+1);
}

int main(){
	FILE*arch = fopen("Datos_L2_20_1_P2.txt","r");
	
	Fase fases[7];
	int n=0;
	while (1){
		fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
			   &fases[n].percentage, &fases[n].costConsult[0],
			   &fases[n].costConsult[1],&fases[n].costConsult[2],
			   &fases[n].costConsult[3],&fases[n].costConsult[4],
			   &fases[n].costConsult[5],&fases[n].costConsult[6],
			   &fases[n].areEconom, &fases[n].quantConsult);
		if (feof(arch)) break;
		n++;
	}
	int ahorro=0;
	int combinaciones = (int)pow(2, numConsultoras);
	int cromo[numConsultoras];
	int i;
	int masBarato, masCaro;
	for (i=0; i<numConsultoras; i++){
		masBarato=99999999, masCaro=0;
		ahorro = elegirConsultoras(fases[i], 0,combinaciones, cromo,
								   &masBarato, &masCaro, ahorro);
		
		if (fases[i].areEconom){
			printf("%-20d ", masBarato);
		}
		else{
			printf("%-20d ", masCaro);
		}
		printf("AHORRO: %d\n", ahorro);
	}
	return 0;
}


int elegirConsultoras(Fase fases,int combinacionActual, int combinaciones,
					  int *cromo, int*masBarato, int*masCaro, int ahorroAct){
					  	
	if (combinacionActual==combinaciones) return 0;
	int i;
	cargaBin(cromo, combinacionActual, 0);
	int cantConsultoras=0, montoConsultoras=0;
	
	calcularMontoYCantidadDeConsultoras(fases, cromo, numConsultoras,&montoConsultoras,
										&cantConsultoras);
	
	int ahorro;
	ahorro = elegirConsultoras(fases, combinacionActual+1, combinaciones, cromo, 
					  masBarato, masCaro, ahorroAct);
					  
	int maximaInversion = fases.percentage*presupuesto/100 + ahorroAct;
	
	if (cantConsultoras==fases.quantConsult && maximaInversion>=montoConsultoras){
		if (fases.areEconom){
			if (montoConsultoras<*masBarato){
				*masBarato = montoConsultoras;
				return maximaInversion-montoConsultoras;
			}
		}
		else{
			if (montoConsultoras>*masCaro){
				*masCaro = montoConsultoras;
				return maximaInversion-montoConsultoras;
			}
		}
	}
	return ahorro;
}

void calcularMontoYCantidadDeConsultoras(Fase fases, int*cromo, int canConsultoras,
										 int*montoConsultoras,
										 int*cantConsultoras){
	if (canConsultoras==-1) return;
	
	if (cromo[canConsultoras]){
		(*montoConsultoras) += fases.costConsult[canConsultoras];
		(*cantConsultoras)++;
	}
	calcularMontoYCantidadDeConsultoras(fases, cromo, canConsultoras-1,
										montoConsultoras, cantConsultoras);									
}
