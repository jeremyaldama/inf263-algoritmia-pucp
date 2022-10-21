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
    int arreglo[] = {8,10,20,80,100,200,400,500,3,2,1};
    int n = 11;
    printf("El valor máxico del rango es %d\n", hallarMaximo(arreglo, 0, n-1));
    return 0;
}