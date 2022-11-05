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


/*se define el  tipo de dato TNodo que representa a una estructura autoreferenciada*/
typedef struct NodoArbol
{
    char nombre;
    int precio;
    struct NodoArbol* izq;
    struct NodoArbol* der;
} TNodoArbol;

/*se define el tipo de dato para gestionar la lista enlazada*/
typedef TNodoArbol* TArbol;

TNodoArbol* crea_nodo(char, int );
void inserta_nodo(TArbol *, char , int );

void pre_orden(TArbol );

TNodoArbol* menor(TNodoArbol* );
TNodoArbol* mayor(TNodoArbol* );

TNodoArbol* remover(TNodoArbol* , int );

int arbol_vacio(TArbol);

int altura(TArbol);
int nodos(TArbol);

#endif /* ARBOL_H */
