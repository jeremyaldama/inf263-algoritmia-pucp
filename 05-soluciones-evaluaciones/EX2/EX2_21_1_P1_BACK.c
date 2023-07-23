#include <stdio.h>
#include <stdlib.h>
#define NUM_VACUNAS 4

int cont = 0, costo = 0;

typedef struct ciudad{
    int *ciudades_colin;
    int n_ciudades_colin;
    int refrigeracion;
} Ciudad;

void Backtrack(Ciudad *ciudades, int*vacunas, int *solucion, int i, int n){
    if (i==n){
        cont++;
        printf("%d) ", cont);
        for (int j=0; j<n; j++){
            printf("%d ", solucion[j]);
        }
        printf("\nCosto: %d\n", costo);
        return;
    }
    
    int continua;
    for (int j=0; j<NUM_VACUNAS; j++){
        continua=0;
        for (int x=0; x<ciudades[i].n_ciudades_colin; x++){
            int i_colin = ciudades[i].ciudades_colin[x];
            int es_refri = ciudades[i].refrigeracion;
            //si ya tengo una solución igual en las ciudades colindates o
            //si uso la vacuna Fisher y la ciudad no cuenta con refrigeracion,
            //continuo a la siguiente
            if (solucion[i_colin]==j+1 || (j==0 && !es_refri)){
                continua=1;
                break;
            }
        }
        if (continua) continue;

        solucion[i] = j+1;
        costo += vacunas[j];

        Backtrack(ciudades, vacunas, solucion, i+1, n);

        costo -= vacunas[j];
        solucion[i] = 0;
    }
    return;
}

int main(){
    int n;
    FILE *arch = fopen("EX2_21_1_A_DATOS.txt", "r");
    fscanf(arch, "%d", &n);

    Ciudad ciudades[n];

    int n_colin;
    for (int i=0; i<n; i++){

        fscanf(arch, "%d", &n_colin);
        ciudades[i].n_ciudades_colin = n_colin;
        ciudades[i].ciudades_colin = (int *)malloc(sizeof(int)*n_colin);

        for (int j=0; j<n_colin; j++){
            int ciud_col;
            fscanf(arch, "%d", &ciud_col);
            ciudades[i].ciudades_colin[j] = ciud_col; 
        }
        int tiene_refri;
        fscanf(arch, "%d", &tiene_refri);
        ciudades[i].refrigeracion = tiene_refri;
    
    }

    int vacunas[4] = {10, 5, 12, 8};
    int solucion[n];

    Backtrack(ciudades, vacunas, solucion, 0, n);
    return 0;
}