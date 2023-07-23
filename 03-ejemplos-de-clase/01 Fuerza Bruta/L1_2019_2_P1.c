#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 12

// solucion hecha por O.D.D

void leerData (int proy[max][6], int *N, int *P) {
	FILE *arch = fopen("proyectos.txt","r");
	fscanf(arch,"%d",N);
	fscanf(arch,"%d",P);
	int i;
	for (i = 0; i < *N; i++) {
		// proy  costo  ganancia  pred1  pred2  pred3
		fscanf(arch,"%d %d %d %d %d %d",&proy[i][0],&proy[i][1],&proy[i][2],&proy[i][3],
		&proy[i][4],&proy[i][5]);
		if (feof(arch)) break;		
	}
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

void swap (int arr[max][3], int i, int j) { // intercambiar
	int temp;
	int k;
	for (k = 0; k < 3; k++) {
		temp = arr[i][k];
		arr[i][k] = arr[j][k];
		arr[j][k] = temp;
	}
}

void ordenarProyectos (int arr[max][3],int cant) { // bubbleSort
	int i, j;
	for (i = 0; i < cant-1; i++) {
		for (j = i+1; j < cant; j++) {
			if (arr[i][2] < arr[j][2]) swap(arr,i,j);	
		}
	}
}

int main () {
	int proy[max][6]; // matriz principal
	int N, P; // num de proy  y  presupuesto
	leerData(proy,&N,&P);
	int i, j, k;
	int costo, ganancia, cumple;
	int cromo[max];
	int max_ganancia = 0;
	int solu[max];
	for (i = 0; i < pow(2,N); i++) {
		cargaBin(i,cromo,N); // decimal a binario
		costo = 0;
		ganancia = 0;
		cumple = 1;
		for (j = 0; j < N; j++) {
			if (cromo[j] == 1) { // verificamos las posibilidades
			/* en caso una posibilidad tenga predecesores y estos no esten
				seleccionados por el cromo, activamos una bandera para descartarlo luego*/
				if ((proy[j][3] != 0 && cromo[proy[j][3]-1] == 0) ||
					(proy[j][4] != 0 && cromo[proy[j][4]-1] == 0) ||
					(proy[j][5] != 0 && cromo[proy[j][5]-1] == 0)) cumple = 0;
				else {
					// sumamos costos y ganancias
					costo += proy[j][1];
					ganancia += proy[j][2];
				}
			}
		}
		if (costo <= P && ganancia > max_ganancia && cumple) {
			max_ganancia = ganancia; // guardamos la maxima ganancia
			for (k = 0; k < N; k++) solu[k] = cromo[k]; // guardamos los proyectos elegidos
		}
	}
	int elegidos[max][3];
	j = 0;
	printf("Ganancia maxima: %d\n",max_ganancia);
	printf("Porjectos elegidos: ");
	for (i = 0; i < N; i++) {
		if (solu[i] == 1) {
			printf("%d ",proy[i][0]); // guardamos la info de los proy elegidos
			elegidos[j][0] = proy[i][0];
			elegidos[j][1] = proy[i][1];
			elegidos[j][2] = proy[i][2];
			j++;
		}	 
	}
	ordenarProyectos(elegidos,j); // ordenamos forma descendente por la ganancia
	printf("\nProyectos ordenados:\n");
	for (i = 0; i < j ; i++) {
		printf("Proyecto: %d  Costo: %d  Ganancia: %d\n",elegidos[i][0],elegidos[i][1],
		elegidos[i][2]);
	}
	return 0;
}
