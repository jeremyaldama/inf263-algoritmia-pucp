#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void construirCola( Cola *pC )
{
    pC->cabeza = NULL;
    pC->final = NULL;
    pC->longitud = 0;
}

int esColaVacia( Cola C )
{
    return C.cabeza == NULL;
    // return C.longitud == 0;
}

NodoCola* crearNuevoNodo( ElementoCola elemento )
{
    NodoCola *pNuevoNodo;
    pNuevoNodo = (NodoCola*)malloc(sizeof(NodoCola));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = NULL;
    return pNuevoNodo;
}

void encolar( Cola *pC, ElementoCola elemento )
{
    NodoCola *pNuevoNodo, *pFinal;
    pNuevoNodo = crearNuevoNodo( elemento);
    if ( esColaVacia(*pC) )
        pC->cabeza = pNuevoNodo;
    else
    {
        pFinal = pC->final;
        pFinal->sig = pNuevoNodo;
    }
    pC->final = pNuevoNodo;
    pC->longitud++;
}

ElementoCola desencolar( Cola *pC )
{
    NodoCola *pNodo;
    ElementoCola elemento;
    pNodo = pC->cabeza;
    elemento = pNodo->elemento;
    pC->cabeza = pNodo->sig;
    if ( pNodo->sig == NULL )
        pC->final = NULL;
    free(pNodo);
    pC->longitud--;
    return elemento;
}
