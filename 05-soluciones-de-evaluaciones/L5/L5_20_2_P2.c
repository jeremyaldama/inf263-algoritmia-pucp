#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100
#define MAX_P 100
int dp[MAX_N + 1][MAX_P + 1];  /* Arreglo que indica si es posible alcanzar un valor de presupuesto o no */

/* Estructura que me servira para almacenar la informacion de un producto */
struct Producto {
  int codigo;
  int precio;
};
struct Producto producto[MAX_N];

/*
 * Funcion booleana que retorna si dos productos son del mismo tipo comparando
 * el primer digito del codigo
 */
int EsMismoTipo(struct Producto p1, struct Producto p2) {
  int tipo_1 = p1.codigo / 100000;
  int tipo_2 = p2.codigo / 100000;
  return (tipo_1 == tipo_2);
}

int max(int a, int b){
    return a>b? a:b;
}

/*
 * Funcion booleana que me ayudara a realizar el ordenamiento de productos
 * Realizare un Merge Sort para poder obtener los productos ordenados por codigo
 * y en caso de igualdad de tipo, ordenado por precio.
 * De esta manera, podre escoger el producto con menor precio de un mismo tipo
 * utilizando simplemente el primerio de su tipo. Para realizar esto tendre que
 * realizar una compresion del arreglo de entrada
 */
int EsMenor(struct Producto p1, struct Producto p2) {
  if (EsMismoTipo(p1, p2)) return (p1.precio < p2.precio);
  return (p1.codigo < p2.codigo);
}

void Merge(int izq, int mid, int der) {
  int n = mid - izq + 1;
  int m = der - mid;
  struct Producto* izquierda = malloc(sizeof(struct Producto) * n);
  struct Producto* derecha = malloc(sizeof(struct Producto) * m);
  for (int i = 0; i < n; i++) izquierda[i] = producto[izq + i];
  for (int i = 0; i < m; i++) derecha[i] = producto[mid + 1 + i];
  int i = 0;
  int j = 0;
  for (int k = izq; k <= der; k++) {
    if (i == n) {
      producto[k] = derecha[j];
      j++;
    } else {
      if (j == m) {
        producto[k] = izquierda[i];
        i++;
      } else {
        if (EsMenor(izquierda[i], derecha[j])) {
          producto[k] = izquierda[i];
          i++;
        } else {
          producto[k] = derecha[j];
          j++;
        }
      }
    }
  }
  free(izquierda);
  free(derecha);
}

void MergeSort(int izq, int der) {
  if (izq < der) {
    int mid = (izq + der) / 2;
    MergeSort(izq, mid);
    MergeSort(mid + 1, der);
    Merge(izq, mid, der);
  }
}
int main(void) {
  /* Lectura de datos */
  int n, presupuesto;
  printf("Ingrese la cantidad de productos: ");
  scanf("%d", &n);
  printf("Ingrese el presupuesto: ");
  scanf("%d", &presupuesto);

  for (int i = 0; i < n; i++) {
    printf("%d-esimo producto\n", i + 1);
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &producto[i].codigo);
    printf("Ingrese el precio del producto: ");
    scanf("%d", &producto[i].precio);
  }
  /* 
   * Ordeno los elementos para poder realizar la compresion del arreglo en un
   * unico producto con el menor precio de este
   */
  MergeSort(0, n - 1);
  struct Producto producto_unico[MAX_N];
  int cantidad_unica = 0;  /* Inicialmente, no tengo productos comprimidos */
  struct Producto actual = producto[0];  /* El primer posible producto es el primero del ordenamiento */
  for (int i = 1; i < n; i++) {
    /*
     * Como estan ordenados por codigo, ni bien encuentre una diferencia
     * esto implica que he terminado de procesar los productos del codigo
     * que ibamos analizando, por lo que lo anado a mi arreglo de productos unicos.
     * Debido a que me quede con la primera aparicion de un producto unico, entonces
     * el precio de dicho producto es el menor posible por consecuencia de la
     * prioridad de ordenamiento en mi funcion Merge.
     */
    if (!EsMismoTipo(producto[i], producto[i - 1])) {
      producto_unico[cantidad_unica] = actual;
      actual = producto[i];
      cantidad_unica++;
    }
  }
  /* El ultimo producto siempre queda pendiente */
  producto_unico[cantidad_unica] = actual;
  cantidad_unica++;

    for (int i=0; i<cantidad_unica; i++){
        printf("%d %d\n", producto_unico[i].codigo,
                producto_unico[i].precio);
    }

  /* 
   * Ahora realizare un algoritmo de programacion dinamica iterativamente para
   * poder resolver el problema.
   * dp[pos][total]: Maximo precio que puedo gasta con los productos
   * desde 0 hasta 'pos', con un maximo de presupuesto 'total'
   */

  /* Primero inicializo mi arreglo y para no lidia con lo casos bases, indexo
   * mis elementos desde 1 */
  for (int pos = 0; pos <= cantidad_unica; pos++) {
    for (int total = 0; total <= presupuesto; total++) {
      dp[pos][total] = 0;
    }
  }

  /* Realizare un knapsack donde el peso y el valor son iguales al precio del producto */
  for (int pos = 1; pos <= cantidad_unica; pos++) {
    int producto_actual = pos - 1;
    int precio_actual = producto_unico[producto_actual].precio;
    for (int total = 1; total <= presupuesto; total++) {
      /*dp[pos][total] = dp[pos - 1][total];
      if (precio_actual <= total &&
          precio_actual + dp[pos - 1][total - precio_actual] > dp[pos][total]) {
        dp[pos][total] = precio_actual + dp[pos - 1][total - precio_actual];
      }*/
      if (total>=precio_actual){
                dp[pos][total] = max(dp[pos-1][total],
                                  precio_actual + dp[pos-1][total - precio_actual]);
            }
            else dp[pos][total] = dp[pos-1][total];
    }
  }

  /* Finalmente, en la posicion final obtenemos el maximo valor al cual podemos alcanzar */
  int maximo = dp[cantidad_unica][presupuesto];
  printf("Se necesita %d soles para la canasta.\n", maximo);
  if (maximo == 0) return 0;
  /* Si es que el maximo no es igual a 0, entonces puedo reconstruir la solucion
   * imprimiendo los productos que colocare en la canasta */
  printf("Productos a colocar en la canasta:\n");
  int i = cantidad_unica;
  int j = presupuesto;
  while (i > 0 && j > 0) {
    /* Si el producto actual no lo utilice, retrocedo un producto */
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      /* Si es que el producto si lo he utilizado, entonces lo imprimo en pantalla
       * y retrocedo tanto en producto como el precio de este producto */
      printf("Producto %d con precio %d\n", producto_unico[i - 1].codigo, producto_unico[i - 1].precio);
      j -= producto_unico[i - 1].precio;
      i--;
    }
  }
  return 0;
}