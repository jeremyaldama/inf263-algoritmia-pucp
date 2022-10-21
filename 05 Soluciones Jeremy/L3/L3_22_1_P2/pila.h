/* 
 * File:   pila.h
 * Author: Danie
 *
 * Created on 13 de octubre de 2022, 21:03
 */

#ifndef PILA_H
#define PILA_H

typedef int ElementoPila;

typedef struct nodoPila{
    ElementoPila peso;
    struct nodoPila *sig;
} NodoPila;

typedef struct{
    NodoPila *cabeza;
} Pila;

NodoPila* crearNuevoNodoPila(ElementoPila elemento, NodoPila*sig);
void construirPila(Pila*);
void push(Pila*, ElementoPila);
ElementoPila pop(Pila*);
void mostrarPila(Pila);

#endif /* PILA_H */

