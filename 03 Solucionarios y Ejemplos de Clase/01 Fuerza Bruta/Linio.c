
#include <stdio.h>
#define N 100

int productos[N];
int horas[24];

//Funcion que verifica si los horarios calzan
int esSolucion(int A[][4],int i, int j, int ii, int jj, int k, int m){
    int c;
    for(c = 0; c < 24; c++){
        horas[c] = 0;
    }

    for( c = 0; c < A[i][3]; c++){
        horas[A[i][2]+c] = 1;
    }

    for( c = 0; c < A[j][3]; c++){
        if(horas[A[j][2]+c]==1)
            return 0;
        else 
            horas[A[j][2]+c] = 1;
    }

    for( c = 0; c < A[ii][3]; c++){
        if(horas[A[ii][2]+c]==1)
            return 0;
        else 
            horas[A[ii][2]+c] = 1;
    }

    for( c = 0; c < A[jj][3]; c++){
        if(horas[A[jj][2]+c]==1)
            return 0;
        else 
            horas[A[jj][2]+c] = 1;
    }

    for( c = 0; c < A[k][3]; c++){
        if(horas[A[k][2]+c]==1)
            return 0;
        else 
            horas[A[k][2]+c] = 1;
    }

    for( c = 0; c < A[m][3]; c++){
        if(horas[A[m][2]+c]==1)
            return 0;
        else 
            horas[A[m][2]+c] = 1;
    }

    return 1;
}

void imprimir_solucion(int A[][4],int i, int j, int ii, int jj, int k, int m){
    printf("%d %d %d %d\n", A[i][0],A[i][1],A[i][2],A[i][3]);
    printf("%d %d %d %d\n", A[j][0],A[j][1],A[j][2],A[j][3]);
    printf("%d %d %d %d\n", A[ii][0],A[ii][1],A[ii][2],A[ii][3]);
    printf("%d %d %d %d\n", A[jj][0],A[jj][1],A[jj][2],A[jj][3]);
    printf("%d %d %d %d\n", A[k][0],A[k][1],A[k][2],A[k][3]);
    printf("%d %d %d %d\n", A[m][0],A[m][1],A[m][2],A[m][3]);
}

void reparto(int A[][4], int n){
    int i,ii,j,jj,k,m;
    for(i = 0; i < n; i++){
        if(A[i][1]==1){ //Encontramos un producto de tipo 1
            for(j = 0; j < n; j++){
                if(A[j][1]==1){ //Encontramos otro producto de tipo 1
                    for(ii=0; ii < n; ii++){
                        if(A[ii][1]==2){ //Encontramos un producto de tipo 2
                            for(jj=0; jj < n; jj++){
                                if(A[jj][1]==2){ //Encontramos otro producto de tipo 2
                                    for( k=0; k < n; k++){
                                        if(A[k][1] == 3){ //Encontramos un producto de tipo 3
                                            for( m = 0; m < n; m++){
                                                if(A[m][1]==4){ //Encontramos un producto de tipo 4
                                                    if(esSolucion(A, i, j, ii, jj, k, m)){
                                                        imprimir_solucion(A, i, j, ii, jj, k, m);
                                                        return;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                }
                            }

                        }
                    }
                }
            }
        }
    }
}

int main(void){
    

    int datos[N][4]={{100, 4, 8, 2},
                    {101, 2, 10, 2},
                    {102, 3, 12, 2},
                    {103, 1, 13, 2},
                    {104, 3, 15, 1},
                    {105, 1, 10, 2},
                    {106, 4, 16, 1},
                    {107, 2, 8, 2},
                    {108, 3, 14, 1},
                    {109, 2, 18, 2},
                    {110, 1, 18, 2},
                    {11, 4, 14, 2}};

    reparto(datos, 12);
    return 0;
}
