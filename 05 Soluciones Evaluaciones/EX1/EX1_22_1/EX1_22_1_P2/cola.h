/* 
 * File:   cola.h
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 1:44
 */

#ifndef COLA_H
#define COLA_H

typedef struct{
    char tipo;
    int orden;
} ElementoCola;

typedef struct nodoCola{
    ElementoCola elemento;
    struct nodoCola *sig;
} NodoCola;

typedef struct{
    NodoCola *cabeza;
    NodoCola *CabVip;
    NodoCola *CabCli;
    NodoCola *CabNoCli;
    NodoCola *ultimoVip;
    NodoCola *ultimoCli;
    NodoCola *ultimoNoCli;
} Cola;

void ConstruirCola(Cola *tad);
void Encolar(Cola*, ElementoCola);
ElementoCola Desencolar(Cola*tad);
void MostrarCola(Cola);

#endif /* COLA_H */

