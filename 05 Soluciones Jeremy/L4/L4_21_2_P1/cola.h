#ifndef cola_h
#define cola_h
#include "abb.h"

typedef ABB ElementoCola;

typedef struct nodoCola{
    ElementoCola elemento;
    struct nodoCola *sig;
} NodoCola;

typedef struct{
    NodoCola *cabeza;
    NodoCola *final;
} Cola;

void ConstruirCola(Cola *);
NodoCola* CrearNuevoNodoCola(ElementoCola );
void Encolar(Cola* , ElementoCola );
ElementoCola Desencolar(Cola*);
void DestruirCola(Cola *);

#endif