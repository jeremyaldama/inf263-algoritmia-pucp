
/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 14 de junio de 2020, 09:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void despacha(TArbol *ptrArbol, int cant){
    int falta,lote;
    TArbol ptraux;
    
    if(cant==0)
        return;
    ptraux = *ptrArbol;
    ptraux = buscaM(ptraux);
    if(ptraux->cant<=cant) 
    {
        falta = cant - ptraux->cant;
        lote = ptraux->lote;
        *ptrArbol=borranodo(*ptrArbol,lote);
        despacha(ptrArbol,falta);
    }  
    else
        ptraux->cant = ptraux->cant - cant;
     
}

int main(int argc, char** argv) {
    TArbol ptrArbol;

    crea_arbol(&ptrArbol);
    
    inserta_nodoR(&ptrArbol, 10,20);
    inserta_nodoR(&ptrArbol, 7,20);
    inserta_nodoR(&ptrArbol, 13,20);
    inserta_nodoR(&ptrArbol, 4,20);
    inserta_nodoR(&ptrArbol, 9,20);
    inserta_nodoR(&ptrArbol, 3,20);

    printf("\nEn orden:\n");
    en_orden(ptrArbol);

    printf("\nDespachando:\n");
    despacha(&ptrArbol,65);
    
      printf("\nEn orden:\n");
    en_orden(ptrArbol);
    
    return (EXIT_SUCCESS);
}

