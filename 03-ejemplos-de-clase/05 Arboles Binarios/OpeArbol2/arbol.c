/* 
 * File:   arbol.c
 * Author: cueva
 * 
 * Created on 8 de junio de 2020, 01:29 AM
 */

#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* al inicio la pila se inicializa con nulo, lo que indica que estaÂ¡ vacia*/
void crear(Tpila *ptrpila) {
    *ptrpila=NULL;
}

/*Se implementaraÂ¡ usando una lista simplemente enlazada. push insertaraÂ¡ siempre
 un nodo al inicio.*/
void push(Tpila *Pila, int valor) {
    TNodoPila *ptrNuevo;
    
    ptrNuevo = (TNodoPila *) malloc(sizeof (TNodoPila));
    ptrNuevo->valor = valor;
    ptrNuevo->ptrSig = *Pila;
    *Pila = ptrNuevo;
    
}

int pila_vacia(Tpila *ptrPila){
    return *ptrPila==NULL;
}


int top(Tpila *ptrPila)
{   TNodoPila *ptrrec;
    
    ptrrec=*ptrPila;
    if(pila_vacia(ptrPila))
        return(0);
    else
        return(ptrrec->valor);

}

/*Dado que se ha realizado una insercion al inicio, para que la estructura se
 comporte como pila, se debe sacar los dados a partir del inicio de la lista.*/

int pop(Tpila *Pila) {    
    TNodoPila *ptrEliminar;
    int valor;
    
    if (!pila_vacia(Pila)) { 
        ptrEliminar=*Pila;
        valor = ptrEliminar->valor; 
        *Pila = ptrEliminar->ptrSig; 
        free(ptrEliminar);
    }
    return valor;
}

/*Libera toda la memoria reservada para la lista utilizada en la pila.*/
void finalizar(Tpila ptrPila){
    TNodoPila *ptrEliminar;
    
    ptrEliminar = ptrPila;
    
    while (ptrEliminar != NULL){
        
        ptrPila = ptrEliminar->ptrSig;
        free(ptrEliminar);
        ptrEliminar = ptrPila;
    }
}
/////////////////////////////////////////////////////////////////////
void crea_arbol(TArbol *ptrArbol) {
    *ptrArbol = NULL;
}

/*Implementacion iterariva de la insercion de un nodo en un 
 arbol binario de busqueda (ABB)*/
void inserta_nodo(TArbol *ptrArbol, TInfo elem) {
    /*ptrPadre apuntara al padre de la hoja que estoy insertando. Para llegar
     a esto ptrReccorido lo usaremos como estructura auxiliar, al final ptrRecorrido
     se hace NULL. Todo esto solo vale en el caso que el arbol no este vacio.*/
    TNodo *ptrRecorrido, *ptrPadre;

    /*se esta creando una hoja con el valor del elemento informado en el parametro*/
    TNodo *ptrNuevo = (TNodo*) malloc(sizeof (TNodo));
    ptrNuevo->elem = elem;
    ptrNuevo->izq = ptrNuevo->der = NULL;

    if (*ptrArbol == NULL) {
        /*si el arbol esta vacio, la nueva hoja sera la raiz del arbol*/
        *ptrArbol = ptrNuevo;
    } else {
        ptrPadre = NULL;
        ptrRecorrido = *ptrArbol;

        while (ptrRecorrido != NULL) {
            ptrPadre = ptrRecorrido;
            if (ptrRecorrido->elem > elem)
                ptrRecorrido = ptrRecorrido->izq;
            else
                ptrRecorrido = ptrRecorrido->der;
        }

        if (ptrPadre->elem > elem)
            ptrPadre->izq = ptrNuevo;
        else
            ptrPadre->der = ptrNuevo;
    }
}

void en_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        en_orden(ptrArbol->izq);
        printf("%3d", ptrArbol->elem);
        en_orden(ptrArbol->der);
    }
}

void pre_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        printf("%3d", ptrArbol->elem);
        pre_orden(ptrArbol->izq);
        pre_orden(ptrArbol->der);
    }
}

void pos_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        pos_orden(ptrArbol->izq);
        pos_orden(ptrArbol->der);
        printf("%3d", ptrArbol->elem);
    }
}
