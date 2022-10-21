/* 
 * File:   cola.h
 * Author: Danie
 *
 * Created on 13 de octubre de 2022, 20:18
 */

#ifndef COLA_H
#define COLA_H

typedef int ElementoCola;

typedef struct nodoCola{
    ElementoCola peso;
    struct nodoCola *sig;
} NodoCola;

typedef struct{
    NodoCola *cabeza;
} Cola;

void crearCola(Cola*);
NodoCola* crearNuevoNodo(ElementoCola elemento, NodoCola *sig);
NodoCola *obtenerUltimoNodo(Cola*tad);
void encolar(Cola* tad, ElementoCola elemento);
ElementoCola desencolar(Cola*tad);
void mostrarCola(Cola tad);

#endif /* COLA_H */

