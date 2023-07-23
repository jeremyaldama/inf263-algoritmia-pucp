/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilas.c
 * Author: cueva
 * 
 * Created on 10 de septiembre de 2022, 05:51 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"
#include "lse.h"

void construir_pila(Pila *tad){
    construir(&tad->contenido);    
}

int es_pila_vacia(Pila tad){
    return es_lista_vacia(tad.contenido);    
}

ElementoPila top(Pila tad){
    if(es_pila_vacia(tad)) exit(2);
    return (ElementoPila)retorna_cabeza(tad.contenido); 

}


void push(Pila *tad,ElementoPila dato){
    insertar_inicio(&tad->contenido,dato);
}

ElementoPila pop(Pila *tad){
    ElementoPila aux;
    
    if(es_pila_vacia(*tad)) exit(2);
    aux = (ElementoPila)retorna_cabeza(tad->contenido);
    elimina_cabeza(&tad->contenido);
    return  aux;
}

//Recorre la cola solo para imprimir
void imprimepila(Pila tad){
   imprimir(tad.contenido);
    
}

void destruir_pila(Pila *tad){
    ElementoPila aux;
    while(!es_pila_vacia(*tad)){
        aux = pop(tad);
    }
    
}