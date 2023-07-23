/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 8 de junio de 2020, 10:37 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbol.h"
#define MAX 100
/*
 * 
 */

int cuenta(TArbol ptrArbol){
    int cont=0;
    if(ptrArbol)
        cont = cuenta(ptrArbol->izq)+cuenta(ptrArbol->der)+1;
    return cont;            
}

TArbol busca(TArbol ptrArbol,int valor)
{
    if(ptrArbol==NULL)
        return NULL;
    else{
    
        if(ptrArbol->elem==valor)
            return ptrArbol;
        else{
            if(ptrArbol->elem<valor)
                ptrArbol=ptrArbol->der;
            else
                ptrArbol=ptrArbol->izq;
            return(busca(ptrArbol,valor));
        }
}

}



int main(int argc, char** argv) {
    TArbol ptrArbol;

    crea_arbol(&ptrArbol);
    inserta_nodo(&ptrArbol, 10);
    inserta_nodo(&ptrArbol, 8);
    inserta_nodo(&ptrArbol, 6);
    inserta_nodo(&ptrArbol, 4);
    inserta_nodo(&ptrArbol, 9);
    inserta_nodo(&ptrArbol, 15);
    inserta_nodo(&ptrArbol, 20);
    //inserta_nodo(&ptrArbol, 15);
    
    en_orden(ptrArbol);
    printf("\nTiene %d nodos",cuenta(ptrArbol));
    if(busca(ptrArbol,9)) printf("\nEncontro");
    else printf("No encontro");
    return (0);

}
