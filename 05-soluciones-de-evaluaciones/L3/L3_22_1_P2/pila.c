#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void construirPila(Pila*tad){
    tad->cabeza = NULL;
}

NodoPila* crearNuevoNodoPila(ElementoPila elemento, NodoPila*sig){
    NodoPila *nuevo = (NodoPila*)malloc(sizeof(NodoPila));
    nuevo->peso = elemento;
    nuevo->sig = sig;
}

void push(Pila* tad, ElementoPila elemento){
    NodoPila *nuevoNodo = crearNuevoNodoPila(elemento, tad->cabeza);
    tad->cabeza = nuevoNodo;
}

ElementoPila pop(Pila *tad){
    ElementoPila ele;
    NodoPila *nodoEliminar = tad->cabeza;
    tad->cabeza = nodoEliminar->sig;
    ele = nodoEliminar->peso;
    free(nodoEliminar);
    return ele;
}

void mostrarPila(Pila tad){
    NodoPila *rec = tad.cabeza;
    
    while (rec){
        printf("%d ", rec->peso);
        rec = rec->sig;
    }
    printf("\n");
}