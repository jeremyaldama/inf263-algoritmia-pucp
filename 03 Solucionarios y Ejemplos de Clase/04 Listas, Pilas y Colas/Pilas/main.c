/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 17 de mayo de 2020, 06:56 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
/*
 * 
 */

void ordena(Tpila *Pila1) 
{    
    int valor,max,n,aux;
    Tpila Pila2;
    Pila2=NULL;
    
    n=tamanopila(*Pila1);
    while (n>0) { 
   	max= pop(Pila1);	
   	n--;
	while (!pila_vacia(Pila1) &&n >0) { 
            valor=pop(Pila1);
            if(max<valor)
            {
                push(&Pila2,max);
                max=valor;
            }
            else
                push(&Pila2,valor);	
            n--;			
   	}	
   	n=0;
   	push(Pila1,max);
	while (!pila_vacia(&Pila2)) { 
            aux=pop(&Pila2);
            push(Pila1,aux);
            n++;
   	}
    }
}

void ordenarec(Tpila *Pila1,int n) 
{   int valor,max,i=n,aux;
    Tpila Pila2;
    Pila2=NULL;
    
    if(n==0) return;
    max= pop(Pila1);	
    i--;
    while (i >0) { 
        valor=pop(Pila1);
        if(max<valor)
        {
            push(&Pila2,max);
            max=valor;
        }
        else
            push(&Pila2,valor);	
        i--;			
    }	
    push(Pila1,max);
    while (!pila_vacia(&Pila2)) { 
        aux=pop(&Pila2);
        push(Pila1,aux);
    }
    ordenarec(Pila1,n-1);
}



void pasa(Tpila *Pila1,Tpila *Pila2) 
{   int valor,n,aux;
    
    while (!pila_vacia(Pila1)) { 
        valor=pop(Pila1);	
   	n=0;
	while (!pila_vacia(Pila1)) { 
            push(Pila2,valor);
            valor=pop(Pila1);
            n++;
   	}	
  	while (!pila_vacia(Pila2)&&n>0) { 
            aux=pop(Pila2);
            push(Pila1,aux);
            n--;
   	}
	push(Pila2,valor);
    }
}

int main(int argc, char** argv) {
    Tpila ptrPila;

    crear(&ptrPila);
    push(&ptrPila, 19);
    push(&ptrPila, 18);
    push(&ptrPila, 17);
    push(&ptrPila, 20);
    
    imprimepila(ptrPila);
    printf("\nPila Ordena:\n");
    ordenarec(&ptrPila,4);
    //ordena(&ptrPila);
    imprimepila(ptrPila);

    Tpila ptrPila2;
    crear(&ptrPila2);
    pasa(&ptrPila,&ptrPila2);
    printf("\nPila 2:\n");
    imprimepila(ptrPila2);
    
    
    
    return (EXIT_SUCCESS);
}

