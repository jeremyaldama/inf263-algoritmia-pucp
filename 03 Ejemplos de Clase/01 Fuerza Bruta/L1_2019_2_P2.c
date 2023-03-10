#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 100

// solucion hecha por O.D.D

void leerData (int lista[max][4], int *cant) {
	FILE *arch;
	arch = fopen("lista.txt","r");
	int i = 0;
	while (1) {
		// cod  tipo  hora  tiempo
		fscanf(arch,"%d %d %d %d",&lista[i][0],&lista[i][1],&lista[i][2],&lista[i][3]);
		if (feof(arch)) break;	
		i++;	
	}
	(*cant) = i;
	fclose(arch);
}

void cargaBin (int num, int cromo[max], int top) {
	int i = 0, j, res;
	for (j = 0; j < top; j++) cromo[j] = 0;
	while (num > 0) {
		res = num%2;
		num = num/2;
		cromo[i] = res;
		i++;
	}
}

int main () {
	int lista[max][4];
	int cant;
	int cromo[max];	
	leerData(lista,&cant);
	int i, j, k;
	int cont1, cont2, cont3, cont4;
	int solu[max];
	for (i = 0; i < pow(2,cant); i++) {
		cargaBin(i,cromo,cant); // decimal a binario
		cont1 = 0;
		cont2 = 0;
		cont3 = 0;
		cont4 = 0;
		int hora[24] = {0};
		int c, hay_cruce = 0;
		for (j = 0; j < cant; j++) {
			if (cromo[j] == 1) {
				// condiciones del problema
				if (lista[j][1] == 1) cont1++;
				if (lista[j][1] == 2) cont2++;
				if (lista[j][1] == 3) cont3++;
				if (lista[j][1] == 4) cont4++;
				// verificamos que no haya cruce de horarios
				for (c = lista[j][2]; c < lista[j][2] + lista[j][3]; c++) {
					// si hay una hora ya ocupada por otro pedido activamos la bandera 
					if (hora[c] == 1) hay_cruce = 1;
					else hora[c] = 1;
				}
			}
		}
		if (cont1 == 2 && cont2 == 2 && cont3 == 1 && cont4 == 1 && !hay_cruce) {
			// si las cantidades son las solicitadas y no hay cruce de horarios, guardamos
			for (k = 0; k < cant; k++) {
				solu[k] = cromo[k];
				//if (cromo[k] == 1) printf("codPed: %d  prio: %d\n",lista[k][0],lista[k][1]);
			}
			//printf("\n");		
		}
	}
	for (i = 0; i < cant; i++) {
		if (solu[i] == 1) printf("codPed: %d  prio: %d\n",lista[i][0],lista[i][1]);
	}
	return 0;
}
