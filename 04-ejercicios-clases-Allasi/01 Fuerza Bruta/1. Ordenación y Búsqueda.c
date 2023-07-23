#include <stdio.h>
void ordenamientoPorSeleccion(int*arreglo,int n);
void ordenamientoBurbuja(int*arreglo,int n);
int busquedaSecuencial(int*arr, int n, int dato);

int main(){
	int n=6;
	int arreglo[]={8,9,1,4,5,7};
	
	ordenamientoBurbuja(arreglo,n);
	int i;
	for(i=0 ;i<n; i++)
	printf("%d\n",arreglo[i]);
	
	int indice;
	indice = busquedaSecuencial(arreglo,n,14);
	printf("EL DATO SE ENCUENTRA EN EL INDICE: %d",indice);
	return 0;
}

void ordenamientoPorSeleccion(int*arreglo,int n){
	int i,k,min,aux;
	
	for (i=0; i<n-1; i++){
		min = i;
		for (k=i+1; k<n; k++){
			if (arreglo[min]>arreglo[k]){
				min = k;
			}
		}
		aux = arreglo[min];
		arreglo[min] = arreglo[i];
		arreglo[i] = aux;
	}
}

void ordenamientoBurbuja(int*arreglo,int n){
	int i,k,aux;
	
	for (i=0; i<n-1; i++){
		for (k=0; k<n-1-i; k++){
			if (arreglo[k+1]<arreglo[k]){
				aux = arreglo[k];
				arreglo[k] = arreglo[k+1];
				arreglo[k+1] = aux;
			}
		}
	}
}

int busquedaSecuencial(int*arr, int n, int dato){
	int i;
	i=0;
	while (i<n && arr[i]!=dato ){
		i++;
	}
	if (i<n) return i;
	else return -1;
}
