#include <stdio.h>
#include <stdlib.h>
int k = 5;

void swap(int *arreglo, int i, int j){
    int aux;
    aux = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = aux;
}

int delete(int *arreglo, int n){
    int i, j, val;
    // guardo el valor que eliminará, el máximo
    val = arreglo[0];
    // intercambio al 1er valor por el Ãºltimo y al
    //último le pongo el primero
    swap(arreglo, 0, n);
    // padre e hijo
    i = 0;
    j = i * 2 + 1;
    // el ultimo ya no tomo en cuenta, porque ahí
    // puse el maximo
    while (j < n){
        //j<n-1 para confirmar que tiene un elemento más a su lado
        if (j < n-1 && arreglo[j + 1] > arreglo[j]) j++;
        // si el padre es menor->lo intercambio
        if (arreglo[i] < arreglo[j]){
            swap(arreglo, i, j);
            // ahora el nuevo padre es j, por el intercambio
            // y el nuevo hijo es j*2
            i = j;
            j = 2 * i;
        }
        else break;
    }
    return val;
}

void MaxHeapifyRecursivo(int *arreglo, int n, int size){
    int hIzq=n*2, hDer=hIzq+1;
    //suponemos que el elemento q nos dan es el maximo
    int max = n;
    if (hDer<=size && arreglo[hDer]>arreglo[max]){
        max = hDer;
    }
    if (hIzq<=size && arreglo[hIzq]>arreglo[max]){
        max = hIzq;
    }
    //si el maximo es el mismo padre ya acabó
    if (n!=max){
        swap(arreglo, n, max);
        //max es el indice de donde ahora esta el nuevo elemento minimo
        MaxHeapifyRecursivo(arreglo, max, size);
    }
}

void MaxHeapRecursivo(int *arreglo, int n){
    int i, j;
    // los del último nivel no tomamos en cuenta,
    // ya que igual se irán maxheapeando
    for (i = (n / 2); i >= 0; i--){
        MaxHeapifyRecursivo(arreglo, i, n);
    }
}

void HeapSortRecursivo(int *arreglo, int n){
    //obtenemos el maxheap
    MaxHeapRecursivo(arreglo, n);
    /*for (int i = 0; i <= n; i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");*/
    int i;
    for (i = n; i >= 0; i--)
        delete(arreglo, i);
}

int CalcularPesoMaximo(int*pavos, int n){
    int dp[n+1];


    dp[0] = 0;
    dp[1] = 0;

    for (int i=2; i<n+1; i++){
        if (abs(pavos[i-1]-pavos[i-2])<k){
            dp[i] = pavos[i-1]+pavos[i-2]+dp[i-2];
        }
        else dp[i] = dp[i-1];
    }

    return dp[n];
}

int main(){
    int pavos[] = {3, 25, 18, 15, 4, 12, 6};
    
    int n = sizeof(pavos)/sizeof(int);
    HeapSortRecursivo(pavos, n-1);

    printf("El peso maximo es: %d\n", CalcularPesoMaximo(pavos, n));
    return 0;
}