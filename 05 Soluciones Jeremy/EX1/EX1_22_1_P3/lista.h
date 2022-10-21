/* 
 * File:   lista.h
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 17:36
 */

#ifndef LISTA_H
#define LISTA_H

typedef struct{
    int numeroProceso;
    int duracion;
} ElementoLista;

typedef struct nodoLista{
    ElementoLista proceso;
    struct nodoLista *sig;
} NodoLista;

typedef struct{
    NodoLista *cabeza;
    int cantidad;
} Lista;

void ConstruirLista(Lista*);
void InsertarAlInicio(Lista*, ElementoLista);
void InsertarAlFinal(Lista*, ElementoLista);
ElementoLista desencolar(Lista*);
NodoLista* crearNuevoNodo(ElementoLista, NodoLista *);
void eliminarCabeza(Lista*);

#endif /* LISTA_H */

