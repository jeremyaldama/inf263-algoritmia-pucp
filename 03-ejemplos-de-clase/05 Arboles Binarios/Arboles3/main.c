/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 20 de junio de 2020, 11:37 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"

int buscacruce(TArbol ptrArbol,int dia,int ini,int fin)
{
    if (ptrArbol==NULL)
        return 0;
    else
    {   if(ptrArbol->dia == dia && ptrArbol->ini == ini && ptrArbol->fin == fin)
            return 1;
        else
        {   if((ptrArbol->dia == dia && ptrArbol->ini <= ini && ptrArbol->fin >ini ) ||
                (ptrArbol->dia == dia && ptrArbol->ini < fin && ptrArbol->fin >=fin ))
                return 1;
                if(ptrArbol->dia*10000+ptrArbol->ini*100+ptrArbol->fin < dia*10000+ini*100+fin)
                    ptrArbol=ptrArbol->der;
                else
                    ptrArbol=ptrArbol->izq;
                return(buscacruce(ptrArbol,dia,ini,fin));
        }
    }
}

int main(int argc, char** argv) {
    TArbol ptrArbol;
    
    crea_arbol(&ptrArbol);
    
    inserta_nodoR(&ptrArbol, 3,10,12);
    inserta_nodoR(&ptrArbol, 2,11,13);
    inserta_nodoR(&ptrArbol, 1,16,18);
    inserta_nodoR(&ptrArbol, 4,9,11);
    inserta_nodoR(&ptrArbol, 1,10,12);
    inserta_nodoR(&ptrArbol, 3,13,15);

    if(buscacruce(ptrArbol,4,10,13))
        printf("Cruzado");
    else
        printf("No hay cruce");

    printf("\nEn orden:\n");
    en_orden(ptrArbol);
    
    
    return (EXIT_SUCCESS);
}

