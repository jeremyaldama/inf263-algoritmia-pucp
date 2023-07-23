#include <stdio.h>
#define max 100
#define INFINITO 100000000
#define hoy 2020

// 20180146

void imprimirArreglo(int arr[max][3], int cant) {
	int i;
	printf("\n");
	for(i = 0; i < cant; i++) {
		printf("%d %d %d",arr[i][0],arr[i][1],arr[i][2]);
		printf("\n");
	}
}

void merge(int arr[max][3], int ini, int medio, int fin) {
	int i, j, k;
	int cant1 = medio - ini + 1;
	int cant2 = fin - medio;
	int arr1[cant1+1][3], arr2[cant2+1][3];
	for(i = 0; i < cant1; i++) {
		arr1[i][0] = arr[ini+i][0];
		arr1[i][1] = arr[ini+i][1];
		arr1[i][2] = arr[ini+i][2];	
	}
	for(j = 0; j < cant2; j++) {
		arr2[j][0] = arr[medio+1+j][0];
		arr2[j][1] = arr[medio+1+j][1];
		arr2[j][2] = arr[medio+1+j][2];	
	}
	arr1[cant1][1] = INFINITO;
	arr2[cant2][1] = INFINITO;
	i = 0;
	j = 0;
	k = ini;
	while (k <= fin) {
		if (arr1[i][1] < arr2[j][1]) {
			arr[k][0] = arr1[i][0];
			arr[k][1] = arr1[i][1];
			arr[k][2] = arr1[i][2];
			i++;
		} else {
			arr[k][0] = arr2[j][0];
			arr[k][1] = arr2[j][1];
			arr[k][2] = arr2[j][2];
			j++;
		}	
		k++;		
	}
}

void ordenarTrab(int arr[max][3], int ini, int fin) { 
	if(ini == fin) return;
	int m = (ini+fin)/2;
	ordenarTrab(arr,ini,m);
	ordenarTrab(arr,m+1,fin);
	merge(arr,ini,m,fin);
}

void despide(int arr[max][3], int ini, int fin, int limite, int faltas) {
	int m = (ini+fin)/2;
	if (ini == fin) {
		if (hoy-arr[ini][1] >= limite) {
			if (arr[ini][2] >= faltas) {
				printf("\n%d %d %d",arr[ini][0],arr[ini][1],arr[ini][2]);
			}
		}
		return;
	}
	if (hoy-arr[ini][1] >= limite) despide(arr,ini,m,limite,faltas);
	if (hoy-arr[m+1][1] >= limite) despide(arr,m+1,fin,limite,faltas);	
}

int main () {
	int i, cant, limite, faltas;
	int trabajadores[max][3];
	printf("Ingrese el numero de trabajadores: ");
	scanf("%d",&cant);
	for(i = 0; i < cant; i++) {
		scanf("%d %d %d",&trabajadores[i][0],&trabajadores[i][1],&trabajadores[i][2]);
	}
	ordenarTrab(trabajadores,0,cant-1);
	imprimirArreglo(trabajadores,cant);
	printf("Ingrese la cant de años maxima para laborar y la cant max de inasistencias injustificadas: ");
	scanf("%d %d",&limite,&faltas);
	printf("Trabajadores a despedir:");
	despide(trabajadores,0,cant-1,limite,faltas);
	return 0;
}
