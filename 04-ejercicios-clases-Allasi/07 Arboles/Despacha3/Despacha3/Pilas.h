/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilas.h
 * Author: cueva
 *
 * Created on 10 de septiembre de 2022, 05:51 PM
 */

#include "lse.h"
#include "Ab.h"

#ifndef PILAS_H
#define PILAS_H

typedef Elemento ElementoPila; 

typedef struct{
    Lista contenido;    
}Pila;

void construir_pila(Pila *);
ElementoPila pop(Pila *);
void push(Pila *,ElementoPila );
void imprimepila(Pila);
ElementoPila top(Pila );
void destruir_pila(Pila *);
int es_pila_vacia(Pila);
#endif /* PILAS_H */
