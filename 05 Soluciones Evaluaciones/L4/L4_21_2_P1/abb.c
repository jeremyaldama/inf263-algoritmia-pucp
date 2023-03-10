#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void ConstruirArbol(ABB*tad){
    *tad = NULL;
}

NodoArbol *CrearNuevoNodoArbol(ABB hijo_izq, ElementoArbol dato, ABB hijo_der){
    NodoArbol *nuevo_nodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevo_nodo->hijo_izq = hijo_izq;
    nuevo_nodo->dato = dato;
    nuevo_nodo->hijo_der = hijo_der;
    return nuevo_nodo;
}

void InsertarRecursivo(ABB*tad, ElementoArbol dato){
     NodoArbol *nuevo_nodo = CrearNuevoNodoArbol(NULL, dato, NULL);
    if (*tad == NULL){
        *tad = nuevo_nodo;
        return;
    }
    else{
        if (dato>(*tad)->dato){
            InsertarRecursivo(&(*tad)->hijo_der, dato);
        }
        else{
            InsertarRecursivo(&(*tad)->hijo_izq, dato);
        }
    }
}