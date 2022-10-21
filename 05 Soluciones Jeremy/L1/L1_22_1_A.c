#include <stdio.h>
#include <math.h>

int p=50000,n=9;

void cargaBin(int cromo[], int num){
	int i;
	for (i=0; i<n; i++) cromo[i] = 0;
	int res;
	i=0;
	while (num>0){
		res = num%2;
		cromo[i] = res;
		num/=2;
		i++;
	}
}

int main(){
	double inversion, ingreso;
	
	double canal[][3] = {{30000, 1.2, 2000},{14000, 2.8}, {18000, 1.4, 1200},
						 {9000, 2.5, 400}, {15000, 1.3, 700}, {10000, 2, 800},
						 {21000, 1.2, 1300},{15000, 2.5, 1000},{2000, 1.1, 200}},
	int cromo[n], comb = pow(2, n), i;
	int j;
	
	for (i=0; i<comb; i++){
		cargaBin(cromo, i);
		for (j=0; j<n; j++){
			if (cromo[j]){
				
			}
		}	
	}
	
	return 0;
}
