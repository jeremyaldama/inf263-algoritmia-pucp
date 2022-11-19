#include <stdio.h>
#define rep(i, n) for(int i=0; i<n; i++)

void ShowTable(int n, int amount, int table[n][amount]){
    rep(i, n){
        rep(j, amount){
            printf("%-3d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int dp(int *coins_value, int n, int amount, int table[n][amount]){
    for (int i=0; i<n; i++){
        for (int j=0; j<amount; j++){
            if (i==0 && j!=0) table[i][j] = 0;
            else if (j==0) table[i][j] = 1;
            //si mi monto es menor al coin, sigue contado con mi estado anterior
            else if (j < coins_value[i-1]){
                table[i][j] = table[i-1][j];
            }
            else{
                int nuevo_monto = j - coins_value[i-1];
                //le sumo a lo que tenia anteriormente con lo que guarde
                //en memoria table lo que hay para un nuevo monto que ya
                //analicé antes, si se resta y queda 0, se suma 1
                table[i][j] = table[i-1][j] + table[i][nuevo_monto];
            }
        }
    }
    return table[n-1][amount-1];
}

int main(){
    int coins_value[] = {1,5,10,25,50};
    int amount;
    int n = sizeof(coins_value)/sizeof(int);

    while (scanf("%d", &amount)==1){

        int table[n+1][amount+1];
        printf("El maximo de combinaciones de monedas para el monto %d es"
            " %d\n", amount, dp(coins_value, n+1, amount+1, table));
        ShowTable(n+1, amount+1, table);

    }
    
    return 0;
}