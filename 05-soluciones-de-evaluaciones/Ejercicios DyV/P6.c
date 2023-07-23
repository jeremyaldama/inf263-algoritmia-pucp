#include <stdio.h>

int hallarInversionesBlock(int*arreglo, int left, int mid, int right){
    int i, j;
    int count=0;
    for (i=left; i<=mid; i++){
        for (j=mid+1; j<=right; j++){
            if (i<j && arreglo[i]>arreglo[j]){
                count++;
            }
        }
    }
    return count;
}

int hallarNumInversiones(int*arreglo, int left, int right){
    if (left==right) return 0;

    int mid = (left+right)/2;

    int numInverRight, numInverLeft;
    numInverLeft = hallarNumInversiones(arreglo, left, mid);
    numInverRight = hallarNumInversiones(arreglo, mid+1, right);
    int numInverBlock;
    numInverBlock = hallarInversionesBlock(arreglo, left, mid, right);
    return numInverBlock+numInverLeft+numInverRight;
}

int main(){
    int arreglo[] = {20,30,3,2};
    int n = 4;

    printf("El numero de inversiones es %d\n", hallarNumInversiones(arreglo, 0, n-1));
    return 0;
}