#ifndef COLAS_H
#define COLAS_H
#include "abb.h"

typedef ABB ElementoCola;

typedef struct nodoCola{
	ElementoCola elemento;
    struct nodoCola *sig;    
} NodoCola;

typedef struct{
    NodoCola *cabeza;
    NodoCola *final;
    int longitud;
} Cola;

void construirCola( Cola *pC );
int esColaVacia( Cola C );
NodoCola* crearNuevoNodo( ElementoCola elemento );
void encolar( Cola *pC, ElementoCola elemento );
ElementoCola desencolar( Cola *pC );

#endif