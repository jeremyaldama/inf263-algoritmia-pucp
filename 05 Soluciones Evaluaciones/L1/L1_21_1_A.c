#include <stdio.h>
#include <math.h>
#define MAX_VEHI 32

int p=13;//precio por galon de combustible
int m=13;//cantidad a transportar al menor coste de transporte
int d=7000;//distancia a recorrer
int cargaATrans=13, n=13;

struct tipoVehi{
	int ccT;
	int nT;
	int rkg;//rendimiento en kms por galon de combustible
	int csT;//costo de servicio por mantenimiento cada 5mil kms
};

void cargaBin(int*cromo, int num){
	int bit;
	for (bit=0; bit<n; bit++){
		cromo[n-1-bit] = num&1;
		num >>= 1;//corro 1 bit a la izquierda
	}
}

int main(){
	//costo de transporte por vehiculo = combustible + mantenimiento
	struct tipoVehi vehiculo[n];
	vehiculo[0].ccT = 2;
	vehiculo[0].rkg = 30;
	vehiculo[0].csT = 10000;
	vehiculo[0].nT = 7;
	
	vehiculo[1].ccT = 4; 
	vehiculo[1].rkg = 25;
	vehiculo[1].csT = 17000;
	vehiculo[1].nT = 3;
	
	vehiculo[2].ccT = 6; 
	vehiculo[2].rkg = 22;
	vehiculo[2].csT = 27000;
	vehiculo[2].nT = 2;
	
	vehiculo[3].ccT = 8; 
	vehiculo[3].rkg = 15;
	vehiculo[3].csT = 35000;
	vehiculo[3].nT = 1;
	
	int cromo[n];//{0,0,0,0,0,0,0, 0,0,0, 0,0, 0}
	int i, j, comb;//
	comb = pow(2, n);
	int distTotal, cargaTotal, prim=1;
	double costoServicio, menorCosto;
	int combCorrecta;
	
	for (i=0; i<comb; i++){
		cargaBin(cromo, i);
		cargaTotal = 0;
		distTotal = 0;
		costoServicio = 0;
		for (j=0; j<n; j++){
			if (cromo[j]){
				if (j<vehiculo[0].nT){
					cargaTotal += vehiculo[0].ccT;
					costoServicio += (p*(double)1/vehiculo[0].rkg*d + d/5000.0*vehiculo[0].csT);
				}
				else if (j<vehiculo[0].nT+vehiculo[1].nT){
					cargaTotal += vehiculo[1].ccT;
					costoServicio += (p*(double)1/vehiculo[1].rkg*d + d/5000.0*vehiculo[1].csT);
				}
				else if (j<vehiculo[0].nT+vehiculo[1].nT+vehiculo[2].nT){
					cargaTotal += vehiculo[2].ccT;
					costoServicio += (p*(double)1/vehiculo[2].rkg*d + d/5000.0*vehiculo[2].csT);
				}
				else{
					cargaTotal += vehiculo[3].ccT;
					costoServicio += (p*(double)1/vehiculo[3].rkg*d + d/5000.0*vehiculo[3].csT);
				}
			}
		}
		
		//printf("%d\n",cargaTotal);
		if (cargaTotal>=m && (costoServicio<menorCosto || prim)){
				printf("%lf\n",menorCosto);
				prim = 0;
				menorCosto = costoServicio;
				combCorrecta = i;
			}
	}
	
	printf("%lf\n",menorCosto);
	cargaBin(cromo, combCorrecta);
	int c1,c2,c3,c4;
	c1=c2=c3=c4=0;
	for (i=0; i<n; i++){
		if (cromo[i]){
			if (i<vehiculo[0].nT){
				c1++;	
			}
			else if (i<vehiculo[0].nT+vehiculo[1].nT){
				c2++;
			}
			else if (i<vehiculo[0].nT+vehiculo[1].nT+vehiculo[2].nT){
				c3++;
			}
			else{
				c4++;
			}
		}
	}
	if (c1>0) printf("%d vehiculos del tipo 1\n",c1);
	if (c2>0) printf("%d vehiculos del tipo 2\n",c2);
	if (c3>0) printf("%d vehiculos del tipo 3\n",c3);
	if (c4>0) printf("%d vehiculos del tipo 4\n",c4);			
}
