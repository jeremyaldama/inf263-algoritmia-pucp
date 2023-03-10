/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbol.h
 * Author: cueva
 *
 * Created on 8 de junio de 2020, 01:29 AM
 */

#ifndef ARBOL_H
#define ARBOL_H
/*informacion que se almacenara en el nodo*/
typedef int TInfo;

/*se define el  tipo de dato TNodo que representa a una estructura autoreferenciada*/
typedef struct Nodo {
    TInfo elem;
    struct Nodo* izq;
    struct Nodo* der;
} TNodo;

/*se define el tipo de dato para gestionar la lista enlazada*/
typedef TNodo* TArbol;


typedef struct NodoPila{
    int valor;
    struct NodoPila *ptrSig; /*estructura auto-referenciada*/
}TNodoPila;

typedef TNodoPila* Tpila ;
void crear(Tpila *);
void push(Tpila *, int);
int pila_vacia(Tpila *);
int top(Tpila *);
int pop(Tpila *);
void finalizar(Tpila);


void crea_arbol(TArbol *ptrArbol);
void inserta_nodo(TArbol *ptrArbol, TInfo elem);
void en_orden(TArbol ptrArbol);
void pre_orden(TArbol ptrArbol);
void pos_orden(TArbol ptrArbol);

#endif /* ARBOL_H */
