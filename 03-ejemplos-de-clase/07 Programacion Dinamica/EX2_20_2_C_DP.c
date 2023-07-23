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

/*
 * Metodo: ObtenerBit
 * Uso: int bit = ObtenerBit(mascara, i);
 * ---------------------------------------
 * Retorna el i-esimo bit de una mascara.
 */
int ObtenerBit(int mascara, int bit) {
  return (mascara >> bit) & 1;
}

/*
 * Metodo: PrenderBit
 * Uso: PrenderBit(&mascara, i);
 * -----------------------------
 * Prende el i-esimo bit de una mascara. Es indiferente si ya estaba prendido.
 */
int PrenderBit(int* mascara, int bit) {
  *mascara = ((*mascara) | (1 << bit));
}

/*
 * Metodo: EsCompatible
 * Uso: if (EsCompatible(n, m, bits)) . . .
 * ----------------------------------
 * Retorna 1 si es que n y m no comparten algun bit 1 en sus n bits,
 * retorna 0 en otro caso.
 */
int EsCompatible(int n, int m, int bits) {
  for (int i = 0; i < bits; i++) if (ObtenerBit(n, i) && ObtenerBit(m, i)) return 0;
  return 1;
}

/*
 * Metodo: Imprimir
 * Uso: Imprimir(cliente, mascara, cnt);
 * -------------------------------------
 * Imprime la lista de productos que se le entragara el cliente representados en una mascara.
 */
void Imprimir(int cliente, int mascara, int cantidad) {
  printf("Cliente %d:\n", cliente);
  for (int bit = 0; bit < cantidad; bit++) {
    if (ObtenerBit(mascara, bit)) {
      printf("Producto (%d, %d) con peso %d\n", productos[bit].x, productos[bit].y, productos[bit].peso);
    }
  }
}

int es_calculado[MAX_N * MAX_N];
int dp_conteo[MAX_N * MAX_N];
/*
 * Metodo: Contar
 * Uso: int cnt = Contar(i, n);
 * ----------------------------
 * Retorna la cantidad de maneras en las que puedo generar subconjuntos de longitud
 * uno o dos en el intervalo [i .. n - 1].
 */
int Contar(int pos, int cantidad) {
  if (pos > cantidad) return 0;  /* Cuando he tomado mas elementos de los necesarios, no hay solucion. */
  if (pos == cantidad) return 1;  /* Cuando he tomado todos los elementos, el conjunto vacio es el caso base. */
  if (es_calculado[pos]) return dp_conteo[pos];  /* Si ya fue calculado, retorno dicha respuesta. */
  int restantes = cantidad - 1 - pos;
  /* Tengo dos maneras de formar grupos:
   * Si es un conjunto unitario, simplemente cuento de cuantas maneras puedo resolver lo que falta.
   * Si es un conjunto de dos elementos, analizo con cuantos puedo agruparme y analizo el nuevo restante. */
  dp_conteo[pos] = Contar(pos + 1, cantidad) + restantes * Contar(pos + 2, cantidad);
  es_calculado[pos] = 1;  /* Paso clave de todo DP: memoizacion. */
  return dp_conteo[pos];
}

int main(void) {
  /* Lectura de datos */
  int n;
  printf("Ingrese la longitud de un lado del almacen de n x n: ");
  scanf("%d", &n);
  printf("Al menos un peso ingresado debe ser positivo.\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Ingrese el peso del producto (%d, %d): ", i, j);
      scanf("%d", &almacen[i][j]);
    }
  }

  /* Separo la elementos que tienen peso positivo */
  int cantidad = 0;  /* Cantidad de productos en el almacen con peso positivo */
  int suma_total = 0;  /* Suma de pesos en el almacen */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (almacen[i][j] > 0) {
        productos[cantidad].x = i;
        productos[cantidad].y = j;
        productos[cantidad].peso = almacen[i][j];
        suma_total += productos[cantidad].peso;
        cantidad++;
      }
    }
  }
  /* Utilicemos DP bitmask. Esta estrategia es utilizada para realizar
   * memorizacion sobre la mascara de bits, la cual nos representa un subconjunto
   * de elementos.
   * dp[mascara] representa la suma de pesos de elementos en dicha mascara
   */
  int combinaciones = 1 << cantidad;
  for (int mascara = 0; mascara < combinaciones; mascara++) {
    for (int bit = 0; bit < cantidad; bit++) {
      if (ObtenerBit(mascara, bit)) dp[mascara] += productos[bit].peso;
    }
  }

  /* Iteremos el problema para dos particiones, como la suma es constante,
   * la tercera particion esta perfectamente determinado por los elementos no
   * utilizados por ambas particiones, asi como lo que le falta a sus sumas
   * para ser la suma total.
   */
  int es_posible = 0;
  for (int mascara_1 = 0; mascara_1 < combinaciones; mascara_1++) {
    for (int mascara_2 = 0; mascara_2 < combinaciones; mascara_2++) {
      /* 
       * Si es que la particion 1 y la particion 2 no comparten bits
       * entonces analizo quien debe ser la particion 3.
       */
      if(EsCompatible(mascara_1, mascara_2, cantidad)) {
        int fusion = mascara_1 | mascara_2;
        int mascara_3 = 0;
        for (int bit = 0; bit < cantidad; bit++) {
          if (!ObtenerBit(fusion, bit)) PrenderBit(&mascara_3, bit);
        }
        /* Si es que al menos una particion no tiene elementos, la ignoramos. */
        if (mascara_1 == 0 || mascara_2 == 0 || mascara_3 == 0) continue;
        /* En otro caso, analizo la igualdad de la suma de las particiones.*/
        if (dp[mascara_1] == dp[mascara_2] && dp[mascara_2] == dp[mascara_3]) {
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
  if (!es_posible) {
    printf("No es posible repartir los productos equitativamente entre los tres mejores clientes.\n");
  }

  /* Pregunta 3.b. */
  printf("La cantidad de agrupaciones en elementos unitarios o en parejas es %d.\n", Contar(0, cantidad));
  return 0;
}