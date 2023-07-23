#include <stdio.h>
int ultima_sol[12] = {};

int BackTrack(int *ganancia, int peso, int pos, int n, int *max,
              int *solucion, int j){
    if (pos>=n){
        if (peso>=*max){
            *max = peso;
            for (int i=0; i<12; i++){
                ultima_sol[i] = solucion[i];
            }
        }
        return 0;
    }

    for (int i=pos; i<n; i++){
        solucion[j] = ganancia[i];
        BackTrack(ganancia, peso+ganancia[i], i+3, n, max, solucion,
                 j+1);
        solucion[j] = 0;
    }
}


int main(){
    int ganancia[] = {3, 6, 1, 2, 4, 5, 18, 10, 13, 7, 15, 2};
    int n = sizeof(ganancia)/sizeof(int);
    //12 meses
    int solucion[12] = {};
    /*BACKTRACKING:
    int max=-1;
    int peso=0;
    BackTrack(ganancia, peso, 0, n, &max, solucion, 0);
    printf("El peso maximo es %d\n", max);
    
    for (int i=0; ultima_sol[i]; i++){
        printf("%d ", ultima_sol[i]);
    }
    printf("\n");*/
    
    return 0;
}