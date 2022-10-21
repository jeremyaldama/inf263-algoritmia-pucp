
/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 25 de mayo de 2020, 09:54 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void pasa(Tpila *Pila1,Tpila *Pila2)
{   int valor,aux,n;

while(!pila_vacia(Pila1)){
    valor=pop(Pila1);
    n=0;
    while(!pila_vacia(Pila1)){
        push(Pila2,valor);
        valor=pop(Pila1);
        n++;
    }
    while(!pila_vacia(Pila2) && n>0)
    {
        aux = pop(Pila2);
        push(Pila1,aux);
        n--;
    }
    push(Pila2,valor);
    
}
}
/*Implementar el ordena pilas*/
int main(int argc, char** argv) {
    Tpila ptrPila,ptrPila2;
    
    crear(&ptrPila);
    push(&ptrPila,3);
    push(&ptrPila,4);
    push(&ptrPila,5);
    push(&ptrPila,6);
    push(&ptrPila,7);
    push(&ptrPila,8);
    crear(&ptrPila2);
    printf("Pila 1:\n");
    imprimepila(ptrPila);
    printf("\nPila 2:\n");
    pasa(&ptrPila,&ptrPila2);
    imprimepila(ptrPila2);
    printf("\nPila 1:\n");
    imprimepila(ptrPila);
    
    return (EXIT_SUCCESS);
}

