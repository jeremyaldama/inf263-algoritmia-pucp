/* 
 * File:   arbol.c
 * Author: cueva
 * 
 * Created on 8 de junio de 2020, 01:29 AM
 */

#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////

TNodoArbol* crea_nodo(char nombre, int precio)
{
    TNodoArbol *nuevo = (TNodoArbol*)malloc(sizeof(TNodoArbol));
    nuevo->nombre = nombre;
    nuevo->precio = precio;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}
/*Si el valor se encuentra, no lo inserta*/
void inserta_nodo(TArbol *arbol, char nombre, int precio)
{
    if (*arbol == NULL)
        *arbol = crea_nodo(nombre, precio);
    else
    {
       TNodoArbol* ptrPadre = NULL;
       TNodoArbol* ptrRecorrido = *arbol;

       while (ptrRecorrido != NULL)
       {
           ptrPadre = ptrRecorrido;
           if (ptrRecorrido->precio > precio)
               ptrRecorrido = ptrRecorrido->izq;
           else if (ptrRecorrido->precio < precio)
               ptrRecorrido = ptrRecorrido->der;
           else
               return;
       }

       if (ptrPadre->precio > precio)
           ptrPadre->izq = crea_nodo(nombre, precio);
       else
           ptrPadre->der = crea_nodo(nombre, precio);
   }
}

void pre_orden(TArbol ptrArbol)
{
    if (ptrArbol)
    {
        printf("(%c - %d)  ", ptrArbol->nombre, ptrArbol->precio);
        pre_orden(ptrArbol->izq);
        pre_orden(ptrArbol->der);
    }
}


TNodoArbol* menor(TNodoArbol* nodo)
{
    if (nodo == NULL || nodo->izq == NULL)
        return nodo;
    return menor(nodo->izq);
}
TNodoArbol* mayor(TNodoArbol* nodo)
{
    if (nodo == NULL || nodo->der == NULL)
        return nodo;
    return mayor(nodo->der);
}

TNodoArbol* remover(TNodoArbol* nodo, int precio)
{
    if (nodo == NULL)
        return NULL;
    
    if (precio < nodo->precio)
        nodo->izq = remover(nodo->izq, precio);
    else if (precio > nodo->precio)
        nodo->der = remover(nodo->der, precio);
    else
    {
        if (nodo->izq == NULL)
        {
            TNodoArbol *aux = nodo->der;
            free(nodo);
            return aux;
        }
        if (nodo->der == NULL)
        {
            TNodoArbol *aux = nodo->izq;
            free(nodo);
            return aux;
        }

        TNodoArbol* m = menor(nodo->der);
        nodo->nombre = m->nombre;
        nodo->precio = m->precio;
        nodo->der = remover(nodo->der, m->precio);
    }
   
    return nodo;
}

int arbol_vacio(TArbol arbol)
{
    return arbol == NULL;
}


int altura(TArbol arbol)
{
    if (arbol_vacio(arbol))
        return 0;
    
    int izq = altura(arbol->izq);
    int der = altura(arbol->der);
    
    return 1 + ((izq > der) ? izq : der);
}

int nodos(TArbol arbol)
{
    if (arbol_vacio(arbol))
        return 0;
    return 1 + nodos(arbol->izq) + nodos(arbol->der);
}
