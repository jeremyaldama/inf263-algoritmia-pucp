/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Listas.c
 * Author: cueva
 * 
 * Created on 18 de mayo de 2020, 12:21 PM
 */

#include "Listas.h"
#include <stdio.h>
#include <stdlib.h>



int tamano(TLista ptrLista)
{   TLista ptrrec;
    int cont=0;
    
    ptrrec=ptrLista;
    while(ptrrec)
    {
        ptrrec=ptrrec->sig;
        cont++;
    }
    
    return cont;
}

void crear_lista(TLista *ptrLista){
    *ptrLista = NULL;
}

int esta_vacia(TLista ptrLista){
    return ptrLista==NULL;
}

void insertar_inicio(TLista *ptrLista, TInfo elem){
    TNodo *ptrNuevo;
    ptrNuevo = (TNodo*)malloc(sizeof(TNodo));
    
    ptrNuevo->elem = elem;
    ptrNuevo->sig = *ptrLista;
    *ptrLista = ptrNuevo;
}

void insertar_final(TLista *ptrLista, TInfo elem){
    TNodo *ptrNuevo, *ptrRec, *ptrUltimo;
    ptrNuevo = (TNodo*)malloc(sizeof(TNodo));
    
    ptrNuevo->elem = elem;
    ptrNuevo->sig = NULL;
    ptrRec = *ptrLista;    
    ptrUltimo = NULL;
    while (ptrRec){
        ptrUltimo = ptrRec;
        ptrRec = ptrRec->sig;
    }
    
    if (ptrUltimo)
        ptrUltimo->sig=ptrNuevo;
    else
        *ptrLista = ptrNuevo;
}


void imprimir(TLista ptrLista){
    TNodo *ptrRec;
    ptrRec = ptrLista;
    
    while (ptrRec){
        printf("%d -> ", ptrRec->elem);
        ptrRec = ptrRec->sig;
    }
    printf("NULL\n");
}

void finalizar_lista(TLista ptrLista){
    TNodo *ptrRec, *ptrLiberar;
    ptrRec = ptrLista;
    
    while (ptrRec){
        ptrLiberar = ptrRec;
        ptrRec = ptrRec->sig;
        free(ptrLiberar);
    }
}

int esta_en_lista(TLista ptrLista, TInfo elem){
    TNodo *ptrRec;
    ptrRec = ptrLista;
    
    while (ptrRec){
        if (ptrRec->elem==elem)
            return 1;
        ptrRec = ptrRec->sig;
    }
    return 0;
}

