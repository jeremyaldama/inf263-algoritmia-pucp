#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "cola.h"
                //NodoArbol* *tad
void ConstruirArbol(ABB* tad){
    *tad = NULL;
}


NodoArbol *CrearNuevoNodo(ABB hijo_izq, ElementoArbol dato, ABB hijo_der){
    NodoArbol *nuevo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevo->dato = dato;
    nuevo->hijo_der = hijo_der;
    nuevo->hijo_izq = hijo_izq;
    nuevo->altura = 1;
    return nuevo;
}

void InsertarIterativo(ABB* tad, ElementoArbol dato){
    NodoArbol *padre = NULL;
    NodoArbol *recorrido = *tad;
    NodoArbol *nuevo_nodo = CrearNuevoNodo(NULL, dato, NULL);

    //si es arbol vacio
    if (*tad==NULL){
        *tad = nuevo_nodo;
    }
    else{
        while (recorrido){
            padre = recorrido;
            if (dato>recorrido->dato){
                recorrido = recorrido->hijo_der;
            }
            else{
                recorrido = recorrido->hijo_izq;
            }
        }
        if (dato>padre->dato){
            padre->hijo_der = nuevo_nodo;
        }
        else{
            padre->hijo_izq = nuevo_nodo;
        }
    }
}

void InsertarRecursivo(ABB *tad, ElementoArbol dato){
    NodoArbol *nuevo_nodo = CrearNuevoNodo(NULL, dato, NULL);
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
    (*tad)->altura = AlturaNodo(*tad);
}

void RotacionII(ABB *tad){
    NodoArbol *p = *tad;
    NodoArbol *p_izq = p->hijo_izq;
    NodoArbol *p_izq_der = p_izq->hijo_der;

    p_izq->hijo_der = p;
    p->hijo_izq = p_izq_der;

    p->altura = AlturaNodo(p);
    p_izq->altura = AlturaNodo(p_izq);

    if (*tad==p){
        *tad = p_izq;
    }
}

void RotacionID(ABB *tad){
    NodoArbol *p = *tad;
    NodoArbol *p_izq = p->hijo_izq;
    NodoArbol *p_izq_der = p_izq->hijo_der;

    p_izq->hijo_der = p_izq_der->hijo_izq;
    p->hijo_izq = p_izq_der->hijo_der;

    p_izq_der->hijo_izq = p_izq;
    p_izq_der->hijo_der = p;
    p_izq->altura = AlturaNodo(p_izq);
    p->altura = AlturaNodo(p);
    p_izq_der->altura = AlturaNodo(p_izq_der);

    if (*tad == p){
        *tad = p_izq_der;
    }
}

void RotacionDD(ABB* tad){
    NodoArbol *p = *tad;
    NodoArbol *p_der = p->hijo_der;
    NodoArbol *p_der_izq = p_der->hijo_izq;

    p_der->hijo_izq = p;
    p->hijo_der = p_der_izq;

    p->altura = AlturaNodo(p);
    p_der->altura = AlturaNodo(p_der);

    if (*tad == p){
        *tad = p_der;
    }
}

void RotacionDI(ABB* tad){
    NodoArbol *p = *tad;
    NodoArbol *p_der = p->hijo_der;
    NodoArbol *p_der_izq = p_der->hijo_izq;

    p_der->hijo_izq = p_der_izq->hijo_der;
    p->hijo_der = p_der_izq->hijo_izq;

    p_der_izq->hijo_der = p_der;
    p_der_izq->hijo_izq = p;

    p_der->altura = AlturaNodo(p_der);
    p->altura = AlturaNodo(p);
    p_der_izq->altura = AlturaNodo(p_der_izq);

    if (*tad == p){
        *tad = p_der_izq;
    }
}

int FactorDeBalance(ABB tad){
    int hl, hr;

    hl = (tad && tad->hijo_izq)? tad->hijo_izq->altura : 0;
    hr = (tad && tad->hijo_der)? tad->hijo_der->altura : 0;

    return hl-hr;
}

int AlturaNodo(ABB tad){
    int hl;
    int hr;
 
    hl = (tad && tad->hijo_izq)? tad->hijo_izq->altura : 0;
    hr = (tad && tad->hijo_der)? tad->hijo_der->altura : 0;
 
    return hl > hr ? hl + 1 : hr + 1;
}

void InsertarRecursivoAVL(ABB *tad, ElementoArbol dato){
    
    if (*tad == NULL){
        NodoArbol *nuevo_nodo = CrearNuevoNodo(NULL, dato, NULL);
        *tad = nuevo_nodo;
        return;
    }
    else{
        if (dato>(*tad)->dato){
            InsertarRecursivoAVL(&(*tad)->hijo_der, dato);
        }
        else{
            InsertarRecursivoAVL(&(*tad)->hijo_izq, dato);
        }
    }
    
    (*tad)->altura = AlturaNodo(*tad);

    if (FactorDeBalance(*tad)==2 && FactorDeBalance((*tad)->hijo_izq)==1){
        RotacionII(tad);
    }
    else if (FactorDeBalance(*tad)==2 && FactorDeBalance((*tad)->hijo_izq)==-1){
        RotacionID(tad);
    }
    else if (FactorDeBalance(*tad)==-2 && FactorDeBalance((*tad)->hijo_der)==-1){
        RotacionDD(tad);
    }
    else if (FactorDeBalance(*tad)==-2 && FactorDeBalance((*tad)->hijo_der)==1){
        RotacionDI(tad);
    }
}

void BalancearArbol(ABB*arbol){
    Cola cola;
    construirCola(&cola);
    if (*arbol){
        encolar(&cola, *arbol);
        *arbol = NULL;
        while(!esColaVacia(cola)){
            ABB tad = desencolar(&cola);
            InsertarRecursivoAVL(arbol, tad->dato);
            if (tad->hijo_izq)
                encolar(&cola, tad->hijo_izq);
            if (tad->hijo_der)
                encolar(&cola, tad->hijo_der);
        }
    }
}

