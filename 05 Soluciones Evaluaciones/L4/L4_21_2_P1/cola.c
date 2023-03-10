#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void ConstruirCola(Cola *tad){
    tad->cabeza = NULL;
    tad->final = NULL;
}

NodoCola* CrearNuevoNodoCola(ElementoCola dato){
    NodoCola *nuevo = (NodoCola*)malloc(sizeof(NodoCola));
    nuevo->sig = NULL;
    nuevo->elemento = dato;
    return nuevo;
}

void Encolar(Cola* tad, ElementoCola dato){
    NodoCola *nuevo_nodo = CrearNuevoNodoCola(dato);
    //printf("nuevo nodo: %d\n", nuevo_nodo->elemento->dato);
    NodoCola *p_final;
    if (tad->cabeza==NULL){
        tad->cabeza = nuevo_nodo;
    }
    else{
        p_final = tad->final;
        p_final->sig = nuevo_nodo;
    }
    tad->final = nuevo_nodo;
}

ElementoCola Desencolar(Cola*tad){
    ElementoCola elemento;
    NodoCola *p_inicio = tad->cabeza;
    elemento = p_inicio->elemento;
    tad->cabeza = p_inicio->sig;
    if (p_inicio->sig==NULL){
        tad->final = NULL;
    }
    free(p_inicio);
    return elemento;
}

void DestruirCola(Cola *tad){
    NodoCola *nodo_eliminar, *rec = tad->cabeza;
    while(rec){
        nodo_eliminar = rec;
        rec = rec->sig;
        free(nodo_eliminar);
    }
    tad->cabeza = NULL;
    tad->final = NULL;
}