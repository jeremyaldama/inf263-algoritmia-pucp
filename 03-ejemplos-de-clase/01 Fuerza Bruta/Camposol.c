#include <stdio.h>
#define N 100

int min(int a, int b){
    return (a<=b)? a : b;
}

int max(int a, int b){
    return (a>=b)? a : b;
}

int contar_rectangulos(int L[][4], int n){

    int cont = 0;

    for(int i = 0; i < n; i++){
        if(L[i][0]==L[i][2]){ //Si la linea es vertical
            for(int j = i+1; j< n; j++){
                if(L[j][0] == L[j][2]){ // Si la linea es vertical
                    for(int k = 0; k < n; k++){  // Para la linea horizontal
                        if(L[k][1]==L[k][3] && 
                            min(L[k][0], L[k][2]) <= min(L[i][0], L[j][0]) && 
                            max(L[k][0], L[k][2]) >= max(L[i][0], L[j][0]) &&
                            max(min(L[i][1], L[i][3]), min(L[j][1], L[j][3])) < L[k][1] &&
                            min(max(L[i][1], L[i][3]), max(L[j][1], L[j][3])) > L[k][1]){ //La linea horizontal intersecta las previas
                            for(int m = k+1; m < n; m++){ // Para la linea horizontal
                                if(L[m][1]==L[m][3] && 
                                    min(L[m][0], L[m][2]) <= min(L[i][0], L[j][0]) && 
                                    max(L[m][0], L[m][2]) >= max(L[i][0], L[j][0]) &&
                                    max(min(L[i][1], L[i][3]), min(L[j][1], L[j][3])) < L[m][1] &&
                                    min(max(L[i][1], L[i][3]), max(L[j][1], L[j][3])) > L[m][1]){
									//Esta linea horizontal tambien intersecta las previas
                                    //Por lo tanto, encontramos un rectangulo
                                    cont++;
                                }
                            }
                        }
                    }
                }
            }

        }
    }

    return cont;
}

int main(void){
    //La data estara almacenada en una matriz en donde el numero de filas
    //representa la cantidad de puntos y el numero de columnas es 4 (por las
    //coordenadas de los puntos)

    int lineas[N][4] = {{1, 2, 10, 2},
                        {1, 3, 10, 3},
                        {3, 0, 3, 10},
                        {1, 7, 10, 7},
                        {2, 0, 2, 10},
                        {7, 0, 7, 10},
                        {8, 0, 8, 10}  };

    int n = 7;

    int num = contar_rectangulos(lineas, n);

    printf("El numero de rectangulos es: %d\n", num);
    return 0;
}
