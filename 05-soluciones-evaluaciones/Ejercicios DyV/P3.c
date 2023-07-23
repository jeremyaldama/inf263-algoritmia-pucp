#include <stdio.h>

int hallarElementoMinimo(int*arreglo, int left, int right){
    if (left==right){
        return arreglo[left];
    }
    int minLeft, minRight;
    int mid = (left+right)/2;
    minLeft = hallarElementoMinimo(arreglo, left, mid);
    minRight = hallarElementoMinimo(arreglo, mid+1, right);

    if (minLeft<minRight) return minLeft;
    else return minRight;

}

int main(){
    int arreglo[] = {5,6,1,2,3,4,0};
    int n=7;
    printf("El elemento minimo es %d\n",hallarElementoMinimo(arreglo, 0, n-1));
    return 0;
}