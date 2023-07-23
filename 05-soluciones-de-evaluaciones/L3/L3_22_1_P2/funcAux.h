/* 
 * File:   funcAux.h
 * Author: Danie
 *
 * Created on 13 de octubre de 2022, 21:46
 */

#ifndef FUNCAUX_H
#define FUNCAUX_H
#define MAX 100
#include "cola.h"
#include "pila.h"

void apilarConPrioridad(Cola*linea, Pila*pilaPrincipal, Pila*pilaAux1,
                        Pila *pilaAux2);
void HeapSort(int *arreglo, int n);
void MaxHeapRecursivo(int *arreglo, int n);

void MaxHeapifyRecursivo(int *arreglo, int n, int size);
int delete (int *arreglo, int n);
void Hanoi(int mov, Pila *pilaPrincipal, Pila *pilaAux1, Pila *pilaAux2);
void swap(int *arreglo, int i, int j);
#endif /* FUNCAUX_H */

