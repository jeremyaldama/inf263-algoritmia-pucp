#ifndef _pila_h_
#define _pila_h_

typedef struct{
    int id;
    int fechaCad;
} ElementoPila;

typedef struct nodoPila{
    ElementoPila elemento;
    struct nodoPila *sig;
} NodoPila;

typedef struct{
    NodoPila *cabeza;
    int can;
} Pila;

void construirPila(Pila*);
NodoPila *crearNuevoNodoPilaCont(ElementoPila, NodoPila *);
void apilar(Pila*, ElementoPila );
ElementoPila desapilar(Pila*);
void Mostrar(Pila);

#endif