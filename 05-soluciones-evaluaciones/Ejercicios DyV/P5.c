#include <stdio.h>

int hallarMaximo(int*arreglo, int left, int right){
    if (left==right) return arreglo[right];

    int mid = (left+right)/2;
    int greatRight, greatLeft;
    greatLeft = hallarMaximo(arreglo, left, mid);
    greatRight = hallarMaximo(arreglo, mid+1, right);
    
    if (greatLeft>greatRight) return greatLeft;
    else return greatRight;
}

int main(){
    int arreglo[500000];
    int n = 500000, i;
    for (i=0; i<n; i++){
    	arreglo[i] = i+1;
	}
    printf("El valor máxico del rango es %d\n", hallarMaximo(arreglo, 0, n-1));
    return 0;
}
