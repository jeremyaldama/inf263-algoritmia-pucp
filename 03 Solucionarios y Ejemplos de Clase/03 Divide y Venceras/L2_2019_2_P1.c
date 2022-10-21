#include <stdio.h>
#include <math.h>
#define max 100
#define INFINITO 10000000

// 20180146

int buscarMC(int N, int M) {
	int prod = N*M;
	int i = 1;
	while (1) {
		if (prod <= (int)pow(4,i)) return (int)(pow(4,i)/pow(2,i));
		i++;
	}
}

void imprimirArreglo(int arr[max][2], int cant) {
	int i;
	printf("\n");
	for(i = 0; i < cant; i++) {
		printf("%06d %d",arr[i][0],arr[i][1]);
		printf("\n");
	}
}

void merge(int arr[max][2], int ini, int medio, int fin) {
	int i, j, k;
	int cant1 = medio - ini + 1;
	int cant2 = fin - medio;
	int arr1[cant1+1][2], arr2[cant2+1][2];
	for(i = 0; i < cant1; i++) {
		arr1[i][0] = arr[ini+i][0];
		arr1[i][1] = arr[ini+i][1];	
	}
	for(j = 0; j < cant2; j++) {
		arr2[j][0] = arr[medio+1+j][0];
		arr2[j][1] = arr[medio+1+j][1];	
	}
	arr1[cant1][0] = INFINITO;
	arr2[cant2][0] = INFINITO;
	i = 0;
	j = 0;
	k = ini;
	while (k <= fin) {
		if (arr1[i][0] < arr2[j][0]) {
			arr[k][0] = arr1[i][0];
			arr[k][1] = arr1[i][1];
			i++;
		} else {
			arr[k][0] = arr2[j][0];
			arr[k][1] = arr2[j][1];
			j++;
		}	
		k++;		
	}
}

void ordenarPalets(int arr[max][2], int ini, int fin) { 
	if(ini == fin) return;
	int m = (ini+fin)/2;
	ordenarPalets(arr,ini,m);
	ordenarPalets(arr,m+1,fin);
	merge(arr,ini,m,fin);
}

int buscar(int cod, int matriz[max][max], int i, int j, int K, int palets[max][2], int value, int N, int M) {
	int d = K/2, cant1, cant2, cant3, cant4;
	if (K == 1) {	
		if (matriz[i][j] == cod) {
			printf("(%d , %d)\n",j,i);	
			return buscarCant(matriz,i,j,palets,value,N,M);
		}	
		return 0;
	}
	cant1 = buscar(cod,matriz,i,j,d,palets,value,N,M);
	cant2 = buscar(cod,matriz,i+d,j,d,palets,value,N,M);
	cant3 = buscar(cod,matriz,i,j+d,d,palets,value,N,M);
	cant4 = buscar(cod,matriz,i+d,j+d,d,palets,value,N,M);
	return cant1+cant2+cant3+cant4;	
}

int buscarCant(int matriz[max][max],int i,int j,int palets[max][2], int value, int N, int M) {
	int k;
	int pos = ((M*N)-((N-(i+1))*M)-(M-(j+1))-1); // formula de mrd
	for(k = 0; k < value; k++) {
		if (matriz[i][j] == palets[k][0] && k == pos) return palets[k][1];
	}
}

int main () {
	int cant, i, j, k = 0, N, M, centinela = 0, codigo, cantidad;
	int palets[max][2];
	// ingresar palets
	printf("Ingrese el numero de palets: ");
	scanf("%d",&cant);
	for(i = 0; i < cant; i++) {
		scanf("%d %d",&palets[i][0],&palets[i][1]);
	}
	ordenarPalets(palets,0,cant-1); // ordenamos asc los palets
	imprimirArreglo(palets,cant);
	// crear y llenar almacen NxM
	printf("\nIngrese las dimensiones del almacen: ");
	scanf("%d %d",&N,&M);
	int almacen[N][M];
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++){ 
			if (k == cant) centinela = 1;
			else {
				almacen[i][j] = palets[k][0];
				k++;
			}
		}
		if (centinela == 1) break;
	}
	// crear matriz cuadrada
	int L = buscarMC(N,M);
	int matriz[max][max];
	for(i = 0; i < L; i ++) {
		for(j = 0; j < L; j++) matriz[i][j] = 999999;
	}
	// agregar almacen a matriz cuadrada
	k = 0;
	centinela = 0;
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			if (k == cant) centinela = 1;
			else {
				matriz[i][j] = almacen[i][j];
				k++;
			}	
		}
		if (centinela == 1) break;
	} 
	// verificar que todo se creo correctamente
	printf("\n");
	for(i = 0; i < L; i ++) {
		for(j = 0; j < L; j++) printf("%06d ",matriz[i][j]);
		printf("\n");
	}	
	// buscar producto
	printf("\nIngrese el codigo del producto: ");
	scanf("%d",&codigo);
	printf("\nLas coordenadas son:\n");
	cantidad = buscar(codigo,matriz,0,0,L,palets,cant,N,M);
	printf("Cantidad en almacen: %d",cantidad);	
	return 0;
}
