#include <stdio.h>
int max = -1;

void Backtrack(int*tipo_cambio, int i, int n, int altura, int k, int ganancia,
                int *used){
    if (k==altura){
        if (ganancia>max){
            max = ganancia;
        }
        return;
    }

    for (int x=i; x<n; x++){
        if (used[x]==1) continue;
        if (altura<k/2){
            ganancia -= tipo_cambio[x];
        }
        else{
            ganancia += tipo_cambio[x];
        }
        used[x] = 1;
        Backtrack(tipo_cambio, 0, n, altura+1, k, ganancia, used);

        if (altura<k/2){
            ganancia += tipo_cambio[x];
        }
        else{
            ganancia -= tipo_cambio[x];
        }
        used[x] = 0;
    }
    return;
}

int DP(int *tipo_cambio, int n, int k){
    //
}

int main(){
    int tipo_cambio[] = {315, 322, 200, 385, 375, 365, 380};
    int n = sizeof(tipo_cambio)/sizeof(int);
    int k = 2;
    int used[6] = {};

    Backtrack(tipo_cambio, 0, n, 0, k*2, 0, used);
    DP(tipo_cambio, n, k);

    printf("Ganancia maxima %d\n", max);
    return 0;
}
