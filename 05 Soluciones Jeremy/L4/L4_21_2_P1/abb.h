#ifndef abb_h
#define abb_h

typedef int ElementoArbol;

typedef struct nodoArbol{
    struct nodoArbol *hijo_izq;
    ElementoArbol dato;
    struct nodoArbol *hijo_der;
} NodoArbol;

typedef NodoArbol* ABB;

void ConstruirArbol(ABB*);
NodoArbol *CrearNuevoNodoArbol(ABB, ElementoArbol , ABB );
void InsertarRecursivo(ABB*, ElementoArbol );

#endif