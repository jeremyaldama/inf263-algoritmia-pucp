#ifndef ABB_H
#define ABB_H
#include <stdio.h>

typedef int ElementoArbol;

typedef struct nodoArbol{
    struct nodoArbol *hijo_izq;
    ElementoArbol dato;
    struct nodoArbol *hijo_der;
    int altura;
} NodoArbol;

typedef NodoArbol* ABB;

void ConstruirArbol(ABB*);
void InsertarIterativo(ABB*, ElementoArbol);
void InsertarRecursivo(ABB *tad, ElementoArbol dato);
void InsertarRecursivoAVL(ABB *tad, ElementoArbol dato);
void RotacionII(ABB *tad);
void RotacionID(ABB *tad);
void RotacionDD(ABB* tad);
void RotacionDI(ABB* tad);
void BalancearArbol(ABB*arbol);
int FactorDeBalance(ABB tad);
int AlturaNodo(ABB tad);
NodoArbol *CrearNuevoNodo(ABB hijo_izq, ElementoArbol dato, ABB hijo_der);

#endif