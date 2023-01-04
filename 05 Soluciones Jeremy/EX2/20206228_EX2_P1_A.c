#include <stdio.h>
#define MAX 100
int cap_sector = 3;
int cap_tribuna = 2;
int cap_preferencial = 1;
int cap_vip = 0;
int todo_sector[MAX];
int usado[MAX]={};
int solucion[MAX];

void BackTrack(int *edades, int pos, int n, int pos_sector){
    int i;
    if (pos_sector==cap_sector*3){
        int can_tri=0, can_pref=0, can_vip=0;
        for (i=0; i<3; i++){
            if (todo_sector[i]>=45) can_tri++;
        }
        for (i=3; i<6; i++){
            if (todo_sector[i]>=45) can_pref++;
        }
        for (i=6; i<9; i++){
            if (todo_sector[i]>=45) can_vip++;
        }
        if (can_vip==cap_vip && can_pref==cap_preferencial && can_tri==cap_tribuna){
            for (i=0; i<9; i++){
                solucion[i]=todo_sector[i];
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

        todo_sector[pos_sector] = 0;
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
    
    return 0;
}