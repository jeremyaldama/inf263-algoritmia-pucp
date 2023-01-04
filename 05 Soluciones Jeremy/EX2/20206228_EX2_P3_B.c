#include <stdio.h>
#define MAX 100
int m=2, n=3;
int hay_solucion=0;
int usado[MAX]={};
int pilas[MAX];
int solucion[MAX];

void Backtrack(int *pesos, int pos_pila, int pos, int n_pesos){
    int i;
    if (pos_pila==n*m){
        int suma = pilas[0] + pilas[1];
        int es_correcto = 0;
        for (i=0; i<n*m; i+=2){    
            if (pilas[i]+pilas[i+1] == suma) es_correcto=1;
            else{
                es_correcto=0;
                break;
            }
        }
        if (es_correcto){
            for (i=0; i<n*m; i++){
                solucion[i] = pilas[i];
            }
            hay_solucion=1;
        }
        return;
    }

    for (i=pos; i<n_pesos; i++){
        if (!usado[i]){
            pilas[pos_pila] = pesos[i];
            usado[i] = 1;
        }
        else continue;

        Backtrack(pesos, pos_pila+1, 0, n_pesos);

        pilas[pos_pila] = 0;
        usado[i] = 0;
    }
    return;
}

int main(){
    //arreglo donde hay solucion
    int pesos[] = {4, 5, 3, 1, 3, 2};
    
    //arreglo donde no hay solucion
    //int pesos[] = {4, 5, 3, 1, 3, 3};

    int n_pesos = sizeof(pesos)/sizeof(int);
    
    if (n_pesos != n*m){
        printf("La cantidad de pallets debe ser igual a MxN\n");
    }
    else{
        Backtrack(pesos, 0, 0, n_pesos);
        if (hay_solucion){
            int i;
            printf("Pallets formados: ");
            for (i=0; i<6; i+=2){
                printf("(%d %d) ", solucion[i], solucion[i+1]);
            }
            printf("\n");
        }
        else{
            printf("No hay solucion\n");
        }
    }

    return 0;
}