#include <stdio.h>
#define MAX 100
int cap_sector = 3;
int cap_tribuna = 2;
int cap_preferencial = 1;
int cap_vip = 0;
int todo_sector[MAX];
int usado[MAX]={};
int solucion[MAX];
double mejor_prom_tri=-1;
double mejor_prom_pref=-1;
double mejor_prom_vip=-1;

void BackTrack(int *edades, int pos, int n, int pos_sector){
    int i;
    if (pos_sector==cap_sector*3){
        double prom_tri=0, prom_pref=0, prom_vip=0;
        int can_tri=0, can_pref=0, can_vip=0;
        for (i=0; i<3; i++){
            if (todo_sector[i]>=45) can_tri++;
            prom_tri += todo_sector[i];
        }
        prom_tri /= 3;
        for (i=3; i<6; i++){
            if (todo_sector[i]>=45) can_pref++;
            prom_pref += todo_sector[i];
        }
        prom_pref /= 3;
        for (i=6; i<9; i++){
            if (todo_sector[i]>=45) can_vip++;
            prom_vip += todo_sector[i];
        }
        prom_vip /= 3;
        
        if (can_vip==cap_vip && can_pref==cap_preferencial && can_tri==cap_tribuna){
            if (prom_tri>mejor_prom_tri && 
                prom_pref>mejor_prom_pref &&
                prom_vip>mejor_prom_vip){
                mejor_prom_tri = prom_tri;
                mejor_prom_pref = prom_pref;
                mejor_prom_vip = prom_vip;
                for (i=0; i<9; i++){
                    solucion[i]=todo_sector[i];
                }
            }
        }
        return;
    }

    for (i=pos; i<n; i++){
        if (!usado[i]){
            todo_sector[pos_sector] = edades[i];
            usado[i] = 1;
        }
        else continue;

        BackTrack(edades, 0, n, pos_sector+1);

        //todo_sector[pos_sector] = 0;
        usado[i] = 0;
    }
    return;
}

int main(){
    int edades[] = {25,50,35,28,45,23,24,18,48};
    int n = sizeof(edades)/sizeof(int);
    //mejor promedio de datos = menor promedio en los 3

    BackTrack(edades, 0, n, 0);
    int i;

    printf("Tribuna: ");
    for (i=0; i<3; i++){
        printf("%d ", solucion[i]);
    }
    printf("\nPreferencial: ");
    for (i=3; i<6; i++){
        printf("%d ", solucion[i]);
    }
    printf("\nVip: ");
    for (i=6; i<9; i++){
        printf("%d ", solucion[i]);
    }
    printf("\n\n");

    printf("Promedio de edades Tribuna: %lf anios\n", mejor_prom_tri);
    printf("Promedio de edades Preferencial: %lf anios\n", mejor_prom_pref);
    printf("Promedio de edades Vip: %lf anios\n", mejor_prom_vip);
    
    return 0;
}