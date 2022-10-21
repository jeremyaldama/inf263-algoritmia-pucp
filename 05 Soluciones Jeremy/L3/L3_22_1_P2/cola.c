#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crearCola(Cola*tad){
    tad->cabeza = NULL;
}

NodoCola* crearNuevoNodo(ElementoCola elemento, NodoCola *sig){
    NodoCola *nodo = (NodoCola*)malloc(sizeof(NodoCola));
    nodo->peso = elemento;
    nodo->sig = sig;
    return nodo;
}

NodoCola *obtenerUltimoNodo(Cola*tad){
    NodoCola *ultimo=NULL;
    NodoCola *curr = tad->cabeza;
    
    while (curr){
        ultimo = curr;
        curr = curr->sig;
    }
    return ultimo;
}

void encolar(Cola* tad, ElementoCola elemento){
    NodoCola *nuevoNodo = crearNuevoNodo(elemento, NULL);
    NodoCola *ultimo = obtenerUltimoNodo(tad);
    if (ultimo==NULL) tad->cabeza = nuevoNodo;
    else ultimo->sig = nuevoNodo;
}

ElementoCola desencolar(Cola*tad){
    ElementoCola ele;
    NodoCola *nodoEli = tad->cabeza;
    if (nodoEli){
        ele = nodoEli->peso;
        tad->cabeza = nodoEli->sig;
        free(nodoEli);
        return ele;
    }
}

void mostrarCola(Cola tad){
    NodoCola *rec = tad.cabeza;
    while (rec){
        printf("%d ", rec->peso);
        rec = rec->sig;
    }
    printf("\n");
}
