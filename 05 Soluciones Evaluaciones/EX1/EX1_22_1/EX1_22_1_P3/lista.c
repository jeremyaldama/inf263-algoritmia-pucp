#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void ConstruirLista(Lista*tad){
    tad->cabeza = NULL;
    tad->cantidad = 0;
}

NodoLista* crearNuevoNodo(ElementoLista elemento, NodoLista *sig){
    NodoLista *nuevo = (NodoLista*)malloc(sizeof(NodoLista));
    nuevo->proceso = elemento;
    nuevo->sig = sig;
    return nuevo;
}

void InsertarAlInicio(Lista* tad, ElementoLista elemento){
    NodoLista *nuevoNodo = crearNuevoNodo(elemento, tad->cabeza);
    tad->cabeza = nuevoNodo;
    tad->cantidad++;
}

ElementoLista desencolar(Lista *tad){
    ElementoLista aux;
    NodoLista *nodoAElim = tad->cabeza;
    tad->cabeza = nodoAElim->sig;
    aux = nodoAElim->proceso;
    tad->cantidad--;
    return aux;
}

NodoLista* ObtenerUltimoNodo(Lista tad){
    NodoLista *ult = NULL;
    NodoLista *rec = tad.cabeza;
    
    while (rec){
        ult = rec;
        rec = rec->sig;
    }
    return ult;
}

void InsertarAlFinal(Lista* tad, ElementoLista elem){
    NodoLista *nuevoNodo = crearNuevoNodo(elem, NULL);
    NodoLista *ultimo = ObtenerUltimoNodo(*tad);
    if (ultimo==NULL) tad->cabeza = nuevoNodo;
    else{
        ultimo->sig = nuevoNodo;
    }
    tad->cantidad++;
}
