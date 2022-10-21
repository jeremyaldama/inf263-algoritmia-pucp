#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void construirPila(Pila*tad){
    tad->cabeza = NULL;
    tad->can = 0;
}

NodoPila *crearNuevoNodoPilaCont(ElementoPila elemento, 
        NodoPila *sig){
    NodoPila *nodo = (NodoPila*)malloc(sizeof(NodoPila));
    nodo->elemento = elemento;
    nodo->sig = sig;
    return nodo;        
}

void apilar(Pila*tad, ElementoPila elemento){
    NodoPila *nuevoNodo = crearNuevoNodoPilaCont(elemento, tad->cabeza);
    tad->cabeza = nuevoNodo;
    tad->can++;
}

ElementoPila desapilar(Pila*tad){
    NodoPila *nodoElim = tad->cabeza;
    ElementoPila prod = nodoElim->elemento;
    tad->cabeza = tad->cabeza->sig;
    tad->can--;
    free(nodoElim);
    return prod;
}

void Mostrar(Pila tad){
    NodoPila *rec;
    rec = tad.cabeza;
    while(rec){
        printf("%d ", rec->elemento.fechaCad);
        rec = rec->sig;
    }
    printf("\n");
}