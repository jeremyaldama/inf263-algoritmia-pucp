/* 
 * File:   cola.h
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 23:13
 */

#ifndef COLA_H
#define COLA_H

typedef int ElementoCola;

typedef struct nodoCola
{
    ElementoCola elemento;
    struct nodoCola *sig;
} NodoCola;

typedef struct
{
    NodoCola *cabeza;
    NodoCola *final;
    int longitud;
} Cola;

void construirCola( Cola *);
int esColaVacia( Cola );
NodoCola* crearNuevoNodoCola(ElementoCola);
void encolar( Cola *,ElementoCola);
void mostrarCola( Cola);
ElementoCola desencolar( Cola *);

#endif /* COLA_H */

