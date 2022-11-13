#include <stdio.h>


int CalculateLongestIncreasingSub(int*LIS, int*sequence, int n){
    //LIS[0] = 1; //el primer numero siempre cuenta como 1
    //recorro sequence uno por uno
    int max = 1;
    for (int i=0; i<n; i++){
        LIS[i] = 1;
        //recorro sus números anteriores al del arreglo con indice i
        for (int j=0; j<i; j++){
            if (sequence[i]>sequence[j] && LIS[j]+1>LIS[i] ){
                LIS[i] = LIS[j] + 1;
            }
            if (LIS[i]>max) max=LIS[i];
        }
    }
    return max;
}

int main(){
    int sequence[] = {-7, 10, 9, 2, 3, 8, 8, 1};
    int n = sizeof(sequence)/sizeof(int);
    int LIS[n];

    printf("La secuencia mas larga que se puede calcular es %d", 
                CalculateLongestIncreasingSub(LIS, sequence, n));

    return 0;
}