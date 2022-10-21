#include <stdio.h>
#include <math.h>

int n=4, peso=23;

void cargaBin(int cromo[], int num){
	int i; 
	for (i=0; i<n*2; i++) cromo[i] = 0;
	int j=0, res; 
	while (num>0){
		res = num%2;
		cromo[j] = res;
		num /= 2;
		j++;
	}
}

int main(){
	int izq[][4] = {{7, 17, 14, 19},
					{9, 12, 11, 8}};
	int der[][4] = {{8, 6, 10, 12},
					{18, 7, 15, 11}};
	
	int i, j, comb = (int)pow(2, 8);
	int cromoI[8];
	int cromoD[8];
	
	int k, l, pesoParcial;
	for (i=0; i<comb; i++){
		cargaBin(cromoI, i);
		for (j=0; j<comb; j++){
			cargaBin(cromoD, j);
			
			int m;
			pesoParcial = 0;
			
			for (k=0, l=0, m=0; l<2; k++, m++){
				if (cromoI[m]){
					pesoParcial += izq[l][k];
				}
				if (m==3 || m==7){
					l++, k=-1;
				} 	
			}
			
			for (k=0, l=0, m=0; l<2; k++, m++){
				if (cromoD[m]){
					pesoParcial += der[l][k];
				}
				if (m==3 || m==7){
					l++, k=-1;
				} 	
			}
			if (pesoParcial == peso){
				printf("Resultado: ");
				
				for (k=0, l=0, m=0; l<2; k++, m++){
					if (cromoI[m]){
						printf("%dk ", izq[l][k]);
					}
					if (m==3 || m==7){
						l++, k=-1;
					} 	
				}
				
				for (k=0, l=0, m=0; l<2; k++, m++){
					if (cromoD[m]){
						printf("%dk ", der[l][k]);
					}
					if (m==3 || m==7){
						l++, k=-1;
					} 	
				}
				
				printf("Ubicaciones: ");
				
				for (k=0, l=0, m=0; l<2; k++, m++){
					if (cromoI[m]){
						if (l==0){
							printf("IA%d ", k+1);	
						}
						else printf("IB%d ", k+1);
					}
					if (m==3 || m==7){
						l++, k=-1;
					} 	
				}
				
				for (k=0, l=0, m=0; l<2; k++, m++){
					if (cromoD[m]){
						if (l==0){
							printf("DA%d ", k+1);	
						}
						else printf("DB%d ", k+1);
					}
					if (m==3 || m==7){
						l++, k=-1;
					} 		
				}
				printf("\n");
			}
		}	
	}
	
					
	return 0;
}
