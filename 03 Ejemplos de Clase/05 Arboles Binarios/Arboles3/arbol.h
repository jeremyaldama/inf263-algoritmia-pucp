/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbol.h
 * Author: cueva
 *
 * Created on 20 de junio de 2020, 11:38 AM
 */

#ifndef ARBOL_H
#define ARBOL_H

typedef struct Nodo {
    int dia;
    int ini;
    int fin;
    struct Nodo* izq;
    struct Nodo* der;
} TNodo;

typedef TNodo* TArbol;

void crea_arbol(TArbol *);
void inserta_nodoR(TArbol *, int ,int,int );
void en_orden(TArbol);
TArbol borranodo(TArbol ptr_arbol, int valor);
TArbol buscaM(TArbol ptrArbol);


#endif /* ARBOL_H */
