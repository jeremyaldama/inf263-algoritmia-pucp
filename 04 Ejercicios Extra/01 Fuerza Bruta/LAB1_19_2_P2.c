#include <stdio.h>
#include <math.h>

void convertirBin(int num,int max,int cromo[]){
	int i=0,j,res;

	for(j=0;j<max;j++) cromo[j]=0;
	
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}

int main(){
	int horas[24];
	int datos[][4]={
					{100,4,8,2},
					{101,2,10,2},	
					{102,3,12,2},
					{103,1,13,2},
					{104,3,15,1},
					{105,1,10,2},
					{106,4,16,1},
					{107,2,8,2},
					{108,3,14,1},
					{109,2,18,2},
					{110,1,18,2},
					{111,4,14,2}
								};
	int n=12;
	int opciones = (int)pow(2,n);
	printf("%d\n",opciones);
	int cromo[n];
	int i,j,k,p1,p2,p3,p4,cruce;
	
	for (i=0;i<opciones;i++){
		p1=p2=p3=p4=0;
		convertirBin(i,n,cromo);
		cruce=0;
		for(k=0;k<24;k++) horas[k]=0;
		for (j=0; j<n; j++){
			if (cromo[j]==1){
				//revisando cruces
				for (k=datos[j][2];k<datos[j][2]+datos[j][3]; k++){
					if (horas[k]==0) horas[k]=1;
					else{
						cruce = 1;
						break;
					} 
				}
				if (cruce==1) break;
				//sumando prioridades
				switch (datos[j][1]){
					case 1: p1++; break;
					case 2: p2++; break;
					case 3: p3++; break;
					case 4: p4++;
				}	
			}
		}
		if (p1>=2 && p2>=2 && p3>=1 && p4>=1 && cruce==0){
			printf("%d\n",i);
			for (j=0; j<n; j++)
				if (cromo[j]==1)
					printf("%d %d\n",datos[j][0],datos[j][1]);
			break;
		}
	}
	return 0;
}
