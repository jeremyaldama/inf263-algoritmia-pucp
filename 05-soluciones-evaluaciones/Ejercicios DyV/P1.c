#include <stdio.h>

int encontrarNoRepetido(int*arreglo,int left,int right, int*noRep){
    if (left==right) return 1;
    int mid = (left+right)/2;
    int leftBlock, rightBlock;

    leftBlock = encontrarNoRepetido(arreglo, left, mid, noRep);
    rightBlock = encontrarNoRepetido(arreglo, mid+1, right, noRep);

    if (mid%2==0){
        if (arreglo[mid]!=arreglo[mid+1]){
            *noRep = arreglo[mid];
        } 
    }
    else{
        if (arreglo[mid]!=arreglo[mid-1]){
            *noRep = arreglo[mid-1];
        }
    }
}

int main(){
    int arreglo[] = {1,1,2,2,3,3,4,5,5,6,6};
    int n = 11, noRep;
    int aea = encontrarNoRepetido(arreglo,0,n-1,&noRep);
    printf("El elemento que no se repite es %d\n",noRep);
    return 0;
}