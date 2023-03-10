/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbol2.h
 * Author: cueva
 *
 * Created on 12 de noviembre de 2020, 12:35 PM
 */

#ifndef ARBOL2_H
#define ARBOL2_H

typedef struct Nodo {
    int lote;
    int cant;
    struct Nodo* izq;
    struct Nodo* der;
} TNodo;

typedef TNodo* TArbol;

void crea_arbol(TArbol *);
void inserta_nodoR(TArbol *, int ,int );
void inserta_nodoD(TArbol *, int ,int );
void en_orden(TArbol);
void pre_orden(TArbol);
TArbol borranodo2(TArbol ,int,  int );
TArbol borranodo(TArbol , int);
TArbol buscaM(TArbol ptrArbol);
TArbol busca(TArbol ,int );
TArbol buscalote(TArbol ,int );
TArbol buscaX(TArbol );
#endif /* ARBOL2_H */
