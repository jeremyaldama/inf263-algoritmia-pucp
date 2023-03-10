/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listas.h
 * Author: cueva
 *
 * Created on 17 de mayo de 2020, 07:35 PM
 */

#ifndef LISTAS_H
#define LISTAS_H


#include <stdio.h>
#include <stdlib.h>

/*informacion que se almacenara en el nodo*/
typedef int TInfo;

/*se define el  tipo de dato TNodo que representa a una estructura autoreferenciada*/
typedef struct Nodo{
    TInfo elem;
    struct Nodo* sig;
} TNodo;

/*se define el tipo de dato para gestionar la lista enlazada*/
typedef TNodo* TLista;

/*prototipos del TAD Lista*/
void crear_lista(TLista *ptrLista);
int esta_vacia(TLista ptrLista);
void insertar_inicio(TLista *ptrLista, TInfo elem);
void insertar_final(TLista *ptrLista, TInfo elem);
void imprimir(TLista ptrLista);
void finalizar_lista(TLista ptrLista);
int tamano(TLista ptrLista);
void invierte(TLista *ptrLista);




#endif /* LISTAS_H */
