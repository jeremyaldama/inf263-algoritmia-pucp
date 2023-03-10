//T�cnica aplicada: Divide y Vencer�s
#include <iostream>
#define MAX_DIAS 30

using namespace std;

void Merge(int*arr, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1], R[n2];
	int i, j, k;
	
	for (i=0; i<n1; i++)	L[i] = arr[p+i];//se llenan los 4 primeros numeros de la izquierda
	
	for (i=0; i<n2; i++)	R[i] = arr[q+i+1];//se llenan los 4 ultimos numeros de la derecha
	
	L[n1] = 9999999;
	R[n2] = 9999999;
	
	i=j=0;
	for (k=p; k<r+1; k++){
		if (R[j]>=L[i]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int*arr, int p, int r){
	if (p==r) return;
	int q = (p+r)/2;
	
	MergeSort(arr, p, q);
	MergeSort(arr, q+1, r);
	
	Merge(arr, p, q, r);
}

int contar_consecutivos(int pesos[], int menor_peso, int inicio, int fin){
	int cantidad = 0;
	for (int i=inicio; i<=fin; i++){
		if (pesos[i] == menor_peso){
			cantidad++;
			if (pesos[i+1] != menor_peso){
				break;
			}
		}
	}
	return cantidad;
}

int encontrar_dias_consecutivos_menor_peso(int pesos[], int menor_peso,
											int inicio, int fin){
	if (fin-inicio <= 1){
		return pesos[fin] == menor_peso ?  1 : 0;
	}
	int med = (fin+inicio)/2;
	int cantidad_der, cantidad_izq, cantidad;

	cantidad_izq = encontrar_dias_consecutivos_menor_peso(pesos, menor_peso,
															inicio, med);
	cantidad_der = encontrar_dias_consecutivos_menor_peso(pesos, menor_peso,
															med+1, fin);

	cantidad = contar_consecutivos(pesos, menor_peso, inicio, fin);
	if (pesos[med-1] == pesos[med] && pesos[med] == menor_peso){
		return cantidad_der + cantidad_izq;
	}
	else if (cantidad>=cantidad_der && cantidad>=cantidad_izq){
		return cantidad;
	}
	else if (cantidad_der>=cantidad && cantidad_der>=cantidad_izq){
		return cantidad_der;
	}
	else if (cantidad_izq>=cantidad && cantidad_izq>=cantidad_der){
		return cantidad_izq;
	}
	else{
		return 0;
	}
}

int main(){
	// Copiar y pegar:
	// 98 95 92 89 91 92 89 89 92 93 94 92 91 90 88 88 88 89 90 91 88 88 90 90 92 89 90 88 90 91
	int pesos[MAX_DIAS], pesos_merge[MAX_DIAS];

	// a)
	cout<<"Ingrese los pesos de los 30 dias: ";
	for (int i=0; i<MAX_DIAS; i++){
		scanf("%d", &pesos[i]);
		pesos_merge[i] = pesos[i];
	}
	
	// b)
	MergeSort(pesos_merge, 0, MAX_DIAS-1);
	for (int i=0; i<MAX_DIAS; i++){
		printf("%d ", pesos_merge[i]);
	}

	// c) determinar la cantidad de días consecutivos que logró su menor peso y el rango de días en que lo logro
	int cantidad_mayores_dias_consecutivos = 
	encontrar_dias_consecutivos_menor_peso(pesos, pesos_merge[0], 0, MAX_DIAS-1);
	
	cout<<endl<<"Cantidad de dias consecutivos que logro su menor peso: "<<
	cantidad_mayores_dias_consecutivos<<endl;
	return 0;
}
