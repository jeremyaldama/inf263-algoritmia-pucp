#include <stdio.h>
#define MAX_N 10
#define MAX_POW 1024

int almacen[MAX_N][MAX_N];
int dp[MAX_POW];

struct Producto {
  int x;
  int y;
  int peso;
};
struct Producto productos[MAX_N * MAX_N];

int ObtenerBit(int mascara, int bit){
    return (mascara >> bit) & 1;
}

int EsCompatible(int n, int m, int bits){
    for (int i=0; i<bits; i++) if (ObtenerBit(n, i) && ObtenerBit(m, i)) 
                                return 0;
    return 1;
}

int PrenderBit(int *mascara, int bit){
    *mascara = ((*mascara) | (1 << bit));
}

void Imprimir(int cliente, int mascara, int cantidad){
    printf("Cliente %d:\n", cliente);
    for (int bit=0; bit<cantidad; bit++){
        if (ObtenerBit(mascara, bit)){
            printf("Producto (%d, %d) con peso %d\n", productos[bit].x,
            productos[bit].y, productos[bit].peso);
        }
    }
}

int Contar(int pos, int cantidad){
    
}

int main(){
    int n = 5;
    int almacen[][5] = {
        {0,0,6,0,0},
        {0,0,0,0,0},
        {0,0,4,0,0},
        {0,0,0,0,0},
        {3,2,0,0,3}
    };

    int cantidad = 0;
    int suma_total = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (almacen[i][j]>0){
                productos[cantidad].x = i;
                productos[cantidad].y = j;
                productos[cantidad].peso = almacen[i][j];
                suma_total += productos[cantidad].peso;
                cantidad++;
            }
        }
    }

    /* DP bitmask
     * dp[mascara] guarda la suma de las 32 posibles combinaciones de suma de
     * pesos de productos 
     */
    int combinaciones = 1<<cantidad;
    for (int mascara = 0; mascara < combinaciones; mascara++){
        for (int bit = 0; bit<cantidad; bit++){
            if (ObtenerBit(mascara, bit)){
                dp[mascara] += productos[bit].peso;
            }
        }
        printf("%d\n", dp[mascara]);
    }

    int es_posible = 0;
    for (int mascara_1 = 0; mascara_1 < combinaciones; mascara_1++){
        for (int mascara_2 = 0; mascara_2 < combinaciones; mascara_2++){
            /* Si la particion 1 y la particion 2 no comparten bits,
             * Se analiza la partición 3
             */
            if (EsCompatible(mascara_1, mascara_2, cantidad)){
                int fusion = mascara_1 | mascara_2;
                int mascara_3 = 0;
                for (int bit = 0; bit < cantidad; bit++){
                    if (!ObtenerBit(fusion, bit)) PrenderBit(&mascara_3, bit);
                }
                /* Si almenos una partición no tiene elementos, se ignora.*/
                if (mascara_1==0 || mascara_2==0 || mascara_3==0) continue;
                /* En otro caso, se analiza la igualidad de la suma de las particiones.*/
                if (dp[mascara_1] == dp[mascara_2] && dp[mascara_2]==dp[mascara_3]){
                    printf("Particion encontrada:\n");
                    Imprimir(1, mascara_1, cantidad);
                    Imprimir(2, mascara_2, cantidad);
                    Imprimir(3, mascara_3, cantidad);
                    es_posible = 1;
                }
            }
            if (es_posible) break;
        }
        if (es_posible) break;
    }

    printf("Cantidad de agrupaciones en elementos unitarios o en parejas es 
            %d.\n", Contar(0, cantidad));
    return 0;
}