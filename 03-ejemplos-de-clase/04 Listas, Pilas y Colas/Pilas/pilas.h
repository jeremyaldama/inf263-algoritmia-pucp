/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilas.h
 * Author: cueva
 *
 * Created on 17 de mayo de 2020, 07:05 PM
 */

#ifndef PILAS_H
#define PILAS_H
typedef struct NodoPila{
    int valor;
    struct NodoPila *ptrSig; /*estructura auto-referenciada*/
}TNodoPila;
typedef TNodoPila* Tpila ;


void crear(Tpila *);
void push(Tpila *, int);
int pila_vacia(Tpila *);
void top(Tpila *);
int pop(Tpila *);
void finalizar(Tpila);
void cambia(Tpila,int );
void imprimir(Tpila );
void imprimepila(Tpila);
int tamanopila(Tpila );

#endif /* PILAS_H */
