#include <bits/stdc++.h>
using namespace std;
#define INF 1e5

/* Tenemos una soga de tamanio N y los precios por cada tamaño de soga i es
   prices[i], 1 <= i <= N, la soga la podemos cortar en pedazos y queremos
   maximizar la ganancia segun los cortes.

   1. g = max (p[i] + g(n-i)), 1<=i<=n
*/

int CutRodRecursivo(int *prices, int n){
    if (n == 0) return 0;

    int q = -INF;

    for (int i=0; i<n; i++){
        q = max(q, prices[i] + CutRodRecursivo(prices, n-i-1));
    }
    return q;
}

// DP with memoization

int Helper(int *prices, int n, int *memo){
    if (memo[n]>=0) return memo[n];

    int q;
    if (n==0) q = 0;
    else{
        q = -INF;
        for (int i=1; i<=n; i++){
            q = max(q, prices[i-1] + Helper(prices, n-i, memo));
        }
    }
    memo[n] = q;
    return memo[n];
}

int TopDownCutRod(int *prices, int n){
    int memo[n+1];
    for (int i=0; i<n+1; i++){
        memo[i] = -INF;
    }

    return Helper(prices, n, memo);
}

// DP bottom-up
int BottomUpCutRod(int *prices, int n){
    int dp[n+1];
    /* Una soga de tamanio 0 no da ninguna ganancia.
     */
    dp[0] = 0;

    for (int i=1; i<n+1; i++){
        int q = -INF;
        for (int j=0; j<i; j++){
            q = max(q, prices[j] + dp[i-j-1]);
        }
        dp[i] = q;
    }

    return dp[n];
}

int main(){
    int prices[] = {1, 5, 8, 9};//, 10, 17, 17, 20, 24, 30};
    int n = sizeof(prices)/sizeof(int);

    /*cout<<"La maxima ganancia por cortarlo en pedazos y venderlos es "<<
        CutRodRecursivo(prices, 4);*/
    
    /* cout<<"La maxima ganancia por cortarlo en pedazos y venderlos es "<<
        TopDownCutRod(prices, 4); */

    cout<<"La maxima ganancia por cortarlo en pedazos y venderlos es "<<
        BottomUpCutRod(prices, 4)<<endl;
    return 0;
}