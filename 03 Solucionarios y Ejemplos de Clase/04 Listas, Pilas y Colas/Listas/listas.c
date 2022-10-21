
/* 
 * File:   listas.c
 * Author: cueva
 * 
 * Created on 17 de mayo de 2020, 07:35 PM
 */

#include "listas.h"


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
    //printf("%d %d %d\n",ptrLista,*ptrLista,ptrNuevo);
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
   // printf("%d %d %d\n",ptrLista,*ptrLista,ptrNuevo);        
        
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



