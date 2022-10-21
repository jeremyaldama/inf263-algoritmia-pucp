#include <stdio.h>
#include <math.h>

const int L=20;
int dia[6][24]={{},{},{},{},{},{}};
int n=15;

void cargaCromo(int*cromo, int bit){
	int i;
	for (i=0; i<n; i++){
		cromo[n-1-i] = bit&1;
		bit >>= 1;
	}
}

void reiniciarHoras(int arr[][24]){
	int i,j;
	for (i=0; i<6; i++){
		for (j=0; j<24; j++){
			arr[i][j] = 0;
		}
	}
}

int main(){
	FILE*arch = fopen("20221_Lab1_2.txt","r");
	int curso[n][10];
	int i=0;
	while (1){
		fscanf(arch,"%d",&curso[i][0]); 
		if (feof(arch)) break;
		fscanf(arch, "%d %d %d %d %d %d %d %d %d",
				&curso[i][2],&curso[i][1],&curso[i][3],&curso[i][4],
				&curso[i][5],&curso[i][6],&curso[i][7],&curso[i][8],
				&curso[i][9],&curso[i][10]);
		i++;
	}
	int comb = (int)pow(2, n);
	int cromo[n], j;
	int canCred, dd,hh, k, cruce;
	
	for (i=0; i<comb; i++){
		cargaCromo(cromo, i);
		canCred = 0;
		cruce = 0;
		reiniciarHoras(dia);
		
		for (j=0; j<n; j++){
			if (cromo[j]){
				canCred += curso[j][1];
				dd = curso[j][3];
				hh = curso[j][4];
				for (k=hh; k<curso[j][5]; k++){
					if (dia[dd][k]==0) dia[dd][k]=1;
					else{
						cruce=1;
						break;
					}
				}
				if (cruce==1) break;
				dd = curso[j][6];
				hh = curso[j][7];
				for (k=hh; k<curso[j][8]; k++){
					if (dia[dd][k]==0) dia[dd][k]=1;
					else{
						cruce=1;
						break;
					}
				}
				if (cruce==1) break;
			}
		}
		
		if (canCred==L ){
			printf("%d\n ",canCred);
			for (j=0; j<n; j++){
				if (cromo[j]){
					printf("%06d   %04d\n",curso[j][0], curso[j][2]);
				}
			}
			break;
		}
	}
	return 0;
}
