#include <stdio.h>
#include <math.h>
void cargaBin(int cromo[],int n);

int n=7, p=20, m=4;//num de obreros <=12, presupuesto en miles
				   //min trabajan m obreros y max n
int main(){
	double minPromRot=999999;
	int obrero[][2] = {{1,10},{5,5},{1,5},{10,3},{5,2},{6,1},{2,8}};
	int cromo[n];
	int solus = (int)pow(2, n);
	int i, j, numObreros, sumaSalario;
	double roturaProm;
	double sol[10][3];
	int nsol=0;
	for (i=0; i<solus; i++){
		cargaBin(cromo,i);
		numObreros = sumaSalario = 0;
		roturaProm = 0.0;
		for (j=0; j<n; j++){
			if (cromo[j]){
				numObreros++;
				roturaProm += obrero[j][0];	
				sumaSalario += obrero[j][1];
			}
		}
		roturaProm = roturaProm/numObreros;
		if (numObreros>=m && numObreros<=n && roturaProm<=minPromRot
			&& sumaSalario<=p){
			sol[nsol][0] = i;
			sol[nsol][1] = roturaProm;
			sol[nsol][2] = numObreros;
			nsol++;
			minPromRot = roturaProm;  
		}
	}
	for (i=0; i<nsol; i++){
		if (fabs(sol[i][1]-minPromRot)<=0.005){
			printf("Obreros: ");
			cargaBin(cromo, (int)sol[i][0]);
			sumaSalario = 0;
			for (j=0; j<n; j++){
				if (cromo[j]){
					printf("%d, ", j+1);
					sumaSalario += obrero[j][1];	
				}
			}
			printf("\nCosto de Salarios de %d y rotura prom de %.2lf\n\n",
			sumaSalario, sol[i][1]);
		}
	}
	return 0;
}

void cargaBin(int cromo[],int m){
	int i;
	for (i=0; i<n; i++) cromo[i]=0;
	int resto;
	i=0;
	while (m>0){
		resto = m%2;
		cromo[i] = resto;
		m/=2;
		i++;
	}
}
