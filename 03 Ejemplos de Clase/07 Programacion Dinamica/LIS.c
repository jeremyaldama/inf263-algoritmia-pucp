
/* 
 * File:   main.c
 * Author: Rony
 *
 * Created on 16 de septiembre de 2018, 08:08 PM
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int LIS[MAX];

int solveLIS(int X[]){
    int i, j;
    int maxLIS = 1;
    
    for (i=0; i < MAX; i++){
        LIS[i] = 1;
        for (j = 0; j < i ; j++)
        {
            // Verificar si me puedo anadir
            // y si me conviene
            if (X[i] > X[j] && LIS[j] + 1 > LIS[i])
            {    
                LIS[i] = LIS[j] + 1;
                              
            }    
        }
        if (LIS[i] > maxLIS) maxLIS = LIS[i];
    }
    return maxLIS;
}


int main() {
    int X[MAX] = {-7, 10, 9, 2, -3, 8, 8, 1};
    int w;
    
    int lis = solveLIS(X);
    
    printf("LIS: %d\n", lis);
    
    for(w=0;w<MAX;w++)
        printf("%d ",LIS[w]);
    
    return (0);
}
