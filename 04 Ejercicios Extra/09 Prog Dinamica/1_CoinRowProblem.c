#include <stdio.h>

int FoundMaxAmount(int*coin_values, int n){
    int max[n+1];
    max[0] = 0, max[1]=coin_values[0];

    int temp;
    for (int i=2; i<=n; i++){
        temp = coin_values[i-1] + max[i-2];

        if (temp>max[i-1]){
            max[i] = temp;
        }
        else{
            max[i] = max[i-1];
        }
    }
    return max[n];
}

int main(){
    int coin_values[] = {5, 1, 2, 10, 6, 2};
    int n = sizeof(coin_values)/sizeof(int);

    printf("El máximo monto que se puede obtener sin tomar 2 monedas"
            " adyacentes es %d\n", FoundMaxAmount(coin_values, n)); 
    return 0;
}