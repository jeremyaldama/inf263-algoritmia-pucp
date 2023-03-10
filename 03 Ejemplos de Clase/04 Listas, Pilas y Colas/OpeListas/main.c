/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 18 de mayo de 2020, 12:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"

void divide(TLista ptrlista, TLista *ptrimpar,TLista *ptrpar)
{
    int i=1,n;
    n=tamano(ptrlista);
    while(n>=i){
    
        if(i%2==1)
            insertar_final(ptrimpar,ptrlista->elem);
        else
            insertar_final(ptrpar,ptrlista->elem);
        i++;
        ptrlista=ptrlista->sig;
        
    }
}


int main() {
    TLista ptrLista;
    
    crear_lista(&ptrLista);
    insertar_final(&ptrLista, 19);
    insertar_final(&ptrLista, 20);
    insertar_final(&ptrLista, 16);
    insertar_final(&ptrLista, 14);
    imprimir(ptrLista);
    printf("Tamano:%d\n",tamano(ptrLista));
    imprimir(ptrLista);
    /*Divide tu lista en 2, lista de posiciones pares e impares*/
    TLista ptrpar,ptrimpar;
    crear_lista(&ptrpar);
    crear_lista(&ptrimpar);
    divide(ptrLista,&ptrimpar,&ptrpar);
    imprimir(ptrimpar);
    imprimir(ptrpar);
    
    finalizar_lista(ptrLista);
    return (EXIT_SUCCESS);
}

