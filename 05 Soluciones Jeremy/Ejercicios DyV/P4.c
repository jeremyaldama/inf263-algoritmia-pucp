#include <stdio.h>

int Sumar(int*arreglo, int left, int mid, int right){
    int i, maxAux=0, max=-1;//maxAux se refiere a que no necesariamente es el máximo, solo está probando

    for (i=left; i<=right; i++){
        maxAux += arreglo[i];
        if (arreglo[i] > maxAux ) maxAux=arreglo[i];
        if (maxAux>max) max = maxAux;
    }

    return max;
}

int calcularSumaMaxCont(int*arreglo, int left, int right){
    if (left==right) return arreglo[right];

    int mid = (right+left)/2;
    int sumLeft, sumRight;
    sumLeft = calcularSumaMaxCont(arreglo, left, mid);
    sumRight = calcularSumaMaxCont(arreglo, mid+1, right);

    int sumBlock;
    sumBlock = Sumar(arreglo, left, mid, right);

    printf("BLOCK: %d\n",sumBlock);
    printf("RIGHT: %d\n",sumRight);
    printf("LEFT: %d\n",sumLeft);
    if (sumLeft>=sumRight && sumLeft>=sumBlock) return sumLeft;
    if (sumRight>sumLeft && sumRight>sumBlock) return sumRight;
    else return sumBlock;
}

int main(){
    int arreglo[] = {-2,5,6,-2,-3,1,5,26};
    int n=8;
    printf("La suma maxima de numeros contiguos es %d\n", 
            calcularSumaMaxCont(arreglo, 0, n-1));
    return 0;
}