/* 
 * File:   main.c
 * Author: cueva
 * Lab 4 2020-2 
 * Created on 12 de noviembre de 2020, 12:33 PM
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "arbol2.h"

void incrementa(TArbol ptrArbol,int lote,int cant){
    TNodo* ptraux;
    int stock;
    /*Poner validaciones*/ 
    ptraux = buscalote(ptrArbol,lote); 
    if(ptraux!=NULL)
    {   stock = ptraux->cant;
        ptrArbol=borranodo2(ptrArbol,lote,stock);
        cant = cant + stock;
    }
    inserta_nodoR(&ptrArbol, lote,cant);    
}

int cuenta(TArbol ptrArbol){
    int cont=0;
    
    if(ptrArbol)
     cont = cuenta(ptrArbol->izq)+cuenta(ptrArbol->der)+1;
    
    return cont;
}

void equilibra(TArbol ptrArbol){
    int izq,der,cant,lote,tcant,tlote;
    TNodo * ptraux;
    
    if(ptrArbol==NULL)
        return;
    else{
        while(1){
            izq = cuenta(ptrArbol->izq);
            der = cuenta(ptrArbol->der);
            if(fabs(izq-der)<=1)
                break;
            if(izq<der){
                ptraux = buscaM(ptrArbol->der);
            }
            else{
                ptraux = buscaX(ptrArbol->izq);
            }
            cant = ptraux->cant;
            lote = ptraux->lote;
            borranodo2(ptrArbol,lote,cant);
            tcant = ptrArbol->cant;
            tlote = ptrArbol->lote;
            ptrArbol->cant = cant;
            ptrArbol->lote = lote;
            if(izq<der)
                inserta_nodoD(&ptrArbol, tlote,tcant);
            else
                inserta_nodoR(&ptrArbol, tlote,tcant);
        }
        
    }
}
void despacha(TArbol *ptrArbol, int cant){
    int falta,lote;
    TNodo *ptraux;
    
    if(cant==0)
        return;
    ptraux = *ptrArbol;
    ptraux = buscaM(ptraux);
    if(ptraux->cant<=cant) 
    {
        falta = cant - ptraux->cant;
        lote = ptraux->lote;
        printf("\n%d %d", ptraux->cant,ptraux->lote );
        *ptrArbol=borranodo2(*ptrArbol,ptraux->lote,ptraux->cant);
        despacha(ptrArbol,falta);
    }  
    else{
        printf("\n%d %d",cant, ptraux->lote);
        ptraux->cant = ptraux->cant - cant;
    }
}



int main(int argc, char** argv) {

    TArbol ptrArbol,ptraux;

    crea_arbol(&ptrArbol);
    
    inserta_nodoR(&ptrArbol, 1,10);
   // inserta_nodoR(&ptrArbol, 2,9);
    inserta_nodoR(&ptrArbol, 3,15);
    inserta_nodoR(&ptrArbol, 7,14);
    inserta_nodoR(&ptrArbol, 5,3);
    inserta_nodoR(&ptrArbol, 6,8);
   // inserta_nodoR(&ptrArbol, 2,9);
    //inserta_nodoR(&ptrArbol, 4,12);
    inserta_nodoR(&ptrArbol, 4,10);
    //inserta_nodoR(&ptrArbol, 8,20);
    //inserta_nodoR(&ptrArbol, 9,25);
    //inserta_nodoR(&ptrArbol, 10,30);
    //inserta_nodoR(&ptrArbol, 11,35);
    
    printf("\nPre orden:\n");
    pre_orden(ptrArbol);
    despacha(&ptrArbol,12);
    printf("\nPre orden:\n");
    pre_orden(ptrArbol);
    incrementa(ptrArbol,1,6);
    printf("\nPre orden:\n");
    pre_orden(ptrArbol);
    /*
     * printf("\n %d %d",ptraux->lote,ptraux->cant );
    ptrArbol=borranodo2(ptrArbol,ptraux->lote, ptraux->cant);
    
    */ 
    //ptraux = buscaX(ptrArbol);
    //printf("\n %d %d",ptraux->lote,ptraux->cant );
    equilibra(ptrArbol);
    printf("\nPre orden:\n");
    pre_orden(ptrArbol);
    
    return (EXIT_SUCCESS);
}

