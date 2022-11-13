#include <stdio.h>

int min(int a, int b){
    return a<b? a:b;
}

int dp(int *coin_value, int *memo, int amount, int n){
    //para un monto de 0, no se necesita ninguna moneda
    memo[0] = 0;

    for (int i=1; i<amount; i++){
        memo[i] = 999999;
        for (int j=0; j<n; j++){
            int c = coin_value[j];
            if (i >= c){
                memo[i] = min(memo[i], memo[i-c]+1);
            }
        }
    }
    return memo[amount-1];
}

int main(){
    int amount = 7;
    int coin_value[] = {1,5,10,25,50};
    //We want to find the minimun number of coins that we 
    //must to use to represent amount

    //guardamos el memo para cada monto desde 0...amount
    int memo[amount+1];
    int n = sizeof(coin_value)/sizeof(int);
    printf("El minimo cambio para %d son de %d monedas\n",
            amount, dp(coin_value, memo, amount+1, n));

    for (int i=0; i<amount+1; i++){
        printf("%d ", memo[i]);
    }
    return 0;
}