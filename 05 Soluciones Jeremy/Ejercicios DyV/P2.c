#include <stdio.h> 

int encontrarCantidad0s(int*arreglo, int left, int right){
    if (left==right){
        if (arreglo[left]==0) return 1;
        else return 0;
    } 
    int mid = (left+right)/2;
    int quantRight, quantLeft;
    quantLeft = encontrarCantidad0s(arreglo, left, mid);
    quantRight = encontrarCantidad0s(arreglo, mid+1, right);
    return quantLeft+quantRight;
}

int main(){
    int arreglo[] = {1,1,1,0,0};
    int n=5;

    printf("\nEl numero de 0's es %d\n", 
            encontrarCantidad0s(arreglo, 0, n-1));
    return 0;
}