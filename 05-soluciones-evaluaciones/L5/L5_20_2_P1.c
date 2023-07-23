#include <stdio.h>
#define MAX_N 10
#define MAX_PESO 25

int n, c, existe_solucion, cantidad_actual;

int frecuencia[MAX_PESO + 1];  /* Frecuencia de los pavos del pedido */
int temporal[MAX_PESO + 1];  /* Frecuencias durante el backtracking */

int pesos[MAX_N][MAX_N];
int esta_usado[MAX_N][MAX_N];

void Backtracking(int i, int j) {
  /*
   * Si encuentro un estado en el cual igualo a la cantidad del pedido
   * entonces analizo si es que soy igual en frecuencia.
   * Si igualamos en frecuencia, esto implica que acabo de encontrar una solucion.
   * En otro caso, no tiene sentido seguir iterando.
   */
  if (cantidad_actual == c) {
    for (int peso = 0; peso <= MAX_PESO; peso++) {
      if (temporal[peso] != frecuencia[peso]) return;
    }
    /* En este caso, la postcondicion implica que todas las frecuencias son iguales */
    existe_solucion = 1;
    return;
  }
  /* Si es que ya analice toda la tabla, no hay solucion por ahora */
  if (i == n) return;
  /* Si estoy en una posicion valida, entonces analizo si tomo el pavo actual o no */
  for (int pavo = 0; pavo < 2; pavo++) {
    if (pavo == 1) {
      temporal[pesos[i][j]]++;
      esta_usado[i][j] = 1;
      cantidad_actual++;
    }
    int siguiente_i, siguiente_j;
    if (j == n - 1) {
      siguiente_i = i + 1;
      siguiente_j = 0;
    } else {
      siguiente_i = i;
      siguiente_j = j + 1;
    }
    Backtracking(siguiente_i, siguiente_j);
    /*
     * Si hemos encontrado en una solucion luego de tomar esta decision,
     * no tengo porque seguir analizando otros casos.
     */
    if (existe_solucion) return;
    if (pavo == 1) {
      temporal[pesos[i][j]]--;
      esta_usado[i][j] = 0;
      cantidad_actual--;
    }
  }
}

int main(void) {
  /* Primero leemos los datos del almacen y el pedido */
  printf("Ingrese el lado del almacen: ");
  scanf("%d", &n);
  printf("Ingrese la cantidad de productos a buscar: ");
  scanf("%d", &c);

  for (int i = 0; i <= MAX_PESO; i++) frecuencia[i] = 0;  /* Inicializo las frecuencias */
  int peso_actual;
  for (int i = 0; i < c; i++) {
    printf("Ingrese el peso del %d-esimo pavo del pedido: ", i + 1);
    scanf("%d", &peso_actual);
    frecuencia[peso_actual]++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Ingrese el peso del pavo en la posicion (%d, %d): ", i, j);
      scanf("%d", &pesos[i][j]);
    }
  }

  /* Luego inicializamos los arreglos y variables que utilizaremos en el backtracking */
  existe_solucion = 0;
  cantidad_actual = 0;
  for (int i = 0; i <= MAX_PESO; i++) temporal[i] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      esta_usado[i][j] = 0;
    }
  }

  /* Mando el backtracking para poder encontrar al menos una solucion */
  Backtracking(0, 0);

  /* Finalmente, dependiendo del caso, presentare una respuesta al usuario */
  if (existe_solucion) {
    printf("Si se puede despachar el pedido.\n");
    printf("Las ubicaciones del pedido son las siguientes:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (esta_usado[i][j]) {
          printf("%d ", pesos[i][j]);
        } else {
          printf("0 ");
        }
      }
      printf("\n");
    }
  } else {
    printf("No se puede despachar el pedido.\n");
  }
  return 0;
}