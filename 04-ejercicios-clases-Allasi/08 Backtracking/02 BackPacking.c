#include <stdio.h>
int solucion[6];

int Backtrack(int*paquete, int pos, int n, int peso, int j){
    if (peso==0){
        for (int i=0; solucion[i]; i++){
            printf("%-3d", solucion[i]);
        }
        printf("\n");
        return 0;
    }

    for (int i=pos; i<n; i++){
        if (peso>0){
            solucion[j] = paquete[i];
            if (Backtrack(paquete, i+1, n, peso-paquete[i], j+1)){
                return 1;
            }
            else solucion[j] = 0;
        }
    }
    return 0;
}

int main(){
    int paquete[] = {13, 4, 1, 5, 2, 8};
    int n = sizeof(paquete)/sizeof(int);
    int peso = 13;
    Backtrack(paquete, 0, n, peso, 0);
    return 0;
}