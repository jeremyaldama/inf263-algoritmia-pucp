#include <stdio.h>

int merge(int*arreglo, int left, int mid, int right){
	if (arreglo[mid]>arreglo[mid+1]) return 1;
	int i;
	
	int consIzq=1;
	for (i=mid; i>=left; i--){
		if (arreglo[i]>arreglo[i-1]){
			consIzq++;
		}
		else break;
	}
	int consDer=1;
	for (i=mid+1; i<=right; i++){
		if (arreglo[i]<arreglo[i+1]){
			consDer++;
		}
		else break;
	}
	return consDer+consIzq;
}

int calcularCantidadDiasConsec(int*dia, int left, int right){
	if (left==right) return 1;
	int mid = (left+right)/2;
	
	int countLeft, countRight, bloque;
	countLeft = calcularCantidadDiasConsec(dia, left, mid);
	countRight = calcularCantidadDiasConsec(dia, mid+1, right);
	
	bloque = merge(dia, left, mid, right);

	if (countLeft>=countRight && countLeft>=bloque) return countLeft;
	else if (countRight>=countLeft && countRight>=bloque) return countRight;
	else return bloque;
}

int main(){
	
	int dias[] = {7,2,9,10,16,10,13,8,2,10,11,13,15,16,17};
	int n=15;
	printf("La cantidad de dias consecutivos es %d\n", 
			calcularCantidadDiasConsec(dias, 0, n-1));
	return 0;
}
