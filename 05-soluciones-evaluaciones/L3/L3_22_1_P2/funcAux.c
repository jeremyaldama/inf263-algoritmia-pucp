#include <stdio.h>
#include <stdlib.h>
#include "funcAux.h"

void Hanoi(int mov, Pila *pilaPrincipal, Pila *pilaAux1, Pila *pilaAux2){
    if (mov==0) return;
    
    Hanoi(mov-1, pilaPrincipal, pilaAux2, pilaAux1);
    int peso = pop(pilaPrincipal);
    push(pilaAux2, peso);
    Hanoi(mov-1, pilaAux1, pilaPrincipal, pilaAux2);
}

void apilarConPrioridad(Cola*linea, Pila*pilaPrincipal, Pila*pilaAux1,
                        Pila *pilaAux2){
    int pesosPilaPrincipal[MAX], numPesos=0, i, cont;
    while (linea->cabeza){
        int peso = desencolar(linea);
        for (i=0; i<numPesos; i++){
            if (peso<pesosPilaPrincipal[i]){
                break;
            }
        }
        Hanoi(i, pilaPrincipal, pilaAux1, pilaAux2);
        push(pilaPrincipal, peso);
        Hanoi(i, pilaAux2, pilaAux1, pilaPrincipal);
        
        pesosPilaPrincipal[numPesos] = peso;
        HeapSort(pesosPilaPrincipal, numPesos);
        numPesos++;
    }
}

void HeapSort(int *arreglo, int n){
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

void swap(int *arreglo, int i, int j)
{
    int aux;
    aux = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = aux;
}

int delete(int *arreglo, int n)
{
    int i, j, val;
    // guardo el valor que eliminaré, el máximo
    val = arreglo[0];
    // intercambio al 1er valor por el último y al
    //último le pongo el primero
    swap(arreglo, 0, n);
    // padre e hijo
    i = 0;
    j = i * 2 + 1;
    // el ultimo ya no tomo en cuenta, porque ahí
    // puse el maximo
    while (j < n)
    {
        if (j < n - 1 && arreglo[j + 1] > arreglo[j])
            j++;
        // si el padre es menor->lo intercambio
        if (arreglo[i] < arreglo[j])
        {
            swap(arreglo, i, j);
            // ahora el nuevo padre es j, por el intercambio
            // y el nuevo hijo es j*2
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    return val;
}