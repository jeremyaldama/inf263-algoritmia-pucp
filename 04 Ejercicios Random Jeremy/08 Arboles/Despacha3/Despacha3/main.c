/* 
 * File:   main.c
 * Author: cueva.r
 *
 * Created on 31 de octubre de 2022, 09:27 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Abb.h"
#include "Pilas.h"


void retorna(ArbolBB *ptr_arbol,Pila *pila){
    int cant,lote;
    ElementoArbol dato;
    
    while(!es_pila_vacia(*pila)){
        dato = pop(pila);
        insertar_abb(ptr_arbol,dato);
        
    }
}

void posOrdenIterativa(ArbolBB ptr_arbol,Pila *pila,int n)
{   ArbolBB ptrrec;
    Pila stack;
    int cont=0;
    ElementoArbol temp,alto,ultimo; 
    
    ptrrec=ptr_arbol;
    if (ptr_arbol == NULL) 
        return; 
      
    construir_pila(&stack); 
    ultimo.lote = 0;
    do
    { 
        while (ptrrec) 
        {   temp.lote = ptrrec->elemento.lote;
            temp.cantidad = ptrrec->elemento.cantidad;
            push(&stack,temp);
            ptrrec=ptrrec->hijo_izq;
        }
        alto=top(stack);
        ptrrec=buscaarbol(ptr_arbol,alto);
        
        if (ptrrec->hijo_der && ultimo.lote!=(ptrrec->hijo_der)->elemento.lote)
            ptrrec=ptrrec->hijo_der;
        else
        {   ultimo=pop(&stack);
            ptrrec=NULL;
            push(pila,ultimo);
            ptr_arbol=borranodo(ptr_arbol,ultimo);
            cont++;
            if(cont==n)
                break;
        }
    } while (!es_pila_vacia(stack)); 
} 




int main(int argc, char** argv) {
    ArbolBB ptrArbol;
    Pila ptrpila;
    ElementoArbol temp;
    
    construir_ab(&ptrArbol);
    construir_pila(&ptrpila);

    temp.lote = 10;
    temp.cantidad = 8;
    insertar_abb(&ptrArbol,temp);
    temp.lote = 9;
    temp.cantidad = 10;
    insertar_abb(&ptrArbol,temp);
    temp.lote = 15;
    temp.cantidad = 20;
    insertar_abb(&ptrArbol,temp);
    temp.lote = 6;
    temp.cantidad = 20;
    insertar_abb(&ptrArbol,temp);
    temp.lote = 12;
    temp.cantidad = 10;
    insertar_abb(&ptrArbol,temp);
    temp.lote = 18;
    temp.cantidad = 10;
    insertar_abb(&ptrArbol,temp);
    temp.lote = 5;
    temp.cantidad = 20;    
    insertar_abb(&ptrArbol,temp);
    temp.lote = 8;
    temp.cantidad = 20;  
    insertar_abb(&ptrArbol,temp);

    pre_orden(ptrArbol);
    printf("\n");
    posOrdenIterativa(ptrArbol,&ptrpila,2);
    printf("\n");;
    pre_orden(ptrArbol);
    printf("\n");
    imprimepila(ptrpila);
    retorna(&ptrArbol,&ptrpila);
    printf("\n");
    pre_orden(ptrArbol);
    
    return 0;
}

