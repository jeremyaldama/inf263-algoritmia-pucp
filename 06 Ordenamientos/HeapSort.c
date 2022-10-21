#include <stdio.h>
void swap(int *, int , int);
//Forma normal del HeapSort
void insert(int *, int);
int delete(int *, int);

//HeapSort con heapify iterativo
void HeapSortIterativo(int *, int);
void MaxHeapIterativo(int *, int);

void HeapSortRecursivo(int *, int);
void MaxHeapRecursivo(int *, int );
void MaxHeapifyRecursivo(int *, int , int );

int main()
{
    int arreglo[] = {3,1,2,0,7,10,0,1,100,50,30,2000};
    int i, n = sizeof(arreglo) / sizeof(int);

    /*for (i = 1; i < n; i++)
        insert(arreglo, i);*/

    //HeapSortIterativo(arreglo, n-1);
    HeapSortRecursivo(arreglo, n-1);

    for (i = 0; i < n; i++)
        printf("%d ", arreglo[i]);

    return 0;
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

void MaxHeapRecursivo(int *arreglo, int n){
    int i, j;
    // los del último nivel no tomamos en cuenta,
    // ya que igual se irán maxheapeando
    for (i = (n / 2); i >= 0; i--){
        MaxHeapifyRecursivo(arreglo, i, n);
    }
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


void HeapSortIterativo(int *arreglo, int n){
    MaxHeapIterativo(arreglo, n);
    /*for (int i = 0; i <= n; i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");*/
    int i;
    for (i = n; i >= 0; i--){
        //mueve el maxdato a la derecha y se va ordenando,
        //los i elementos 
        int a = delete(arreglo, i);
    }
}

// O(n)
void MaxHeapIterativo(int *arreglo, int n){
    int i, j;
    // los del último nivel no tomamos en cuenta,
    // ya que igual se irán maxheapeando
    for (i = n / 2; i >= 0; i--)
    {
        j = 2 * i; // hijo izquierdo
        while (j < n)
        {
            if (arreglo[j] < arreglo[j + 1])
                j++;

            if (arreglo[j] > arreglo[i])
            {
                swap(arreglo, i, j);
                i = j;
                j = i * 2;
            }
            else
                break;
        }
    }
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

// O(nlogn)
void insert(int *arreglo, int n){
    int i = n, temp;
    temp = arreglo[i];
    // guardo el dato de la posicion n
    // Mientras exista un padre y el dato sea mayor que
    // el padre, lo voy intercambiando
    while (i > 0 && temp > arreglo[i / 2])
    {
        arreglo[i] = arreglo[i / 2];
        i /= 2;
    }
    arreglo[i] = temp;
}



void swap(int *arreglo, int i, int j){
    int aux;
    aux = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = aux;
}