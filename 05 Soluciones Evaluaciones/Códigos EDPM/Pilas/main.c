/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva.r
 *
 * Created on 26 de septiembre de 2022, 11:35 AM
 */
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>


void pasapila(Pila *pila1,Pila *pila2){
    ElementoPila valor,temp;
    int n;
    while(!es_pila_vacia(*pila1)){
        valor = pop(pila1);
        n=0;
        while(!es_pila_vacia(*pila1)){
            push(pila2,valor);
            valor = pop(pila1);
            n++;
        }
        while(!es_pila_vacia(*pila2) && n>0){
            temp=pop(pila2);
            push(pila1,temp);
            n--;
        }
        push(pila2,valor);
    }
}


int main(int argc, char** argv) {
    Pila pila1,pila2;
    
    construir_pila(&pila1);
    push(&pila1,20);
    push(&pila1,18);
    push(&pila1,16);
    push(&pila1,10);
    construir_pila(&pila2);
    
    imprimepila(pila1);
    pasapila(&pila1,&pila2);
    imprimepila(pila2);
    imprimepila(pila1);
    return 0;
}

