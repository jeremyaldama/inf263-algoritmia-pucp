/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbol.c
 * Author: cueva
 * 
 * Created on 20 de junio de 2020, 11:38 AM
 */

#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"



void crea_arbol(TArbol *ptrArbol) {
    *ptrArbol = NULL;
}


void inserta_nodoR(TArbol *ptrArbol, int dia,int ini,int fin) {
    TArbol ptraux;
    TNodo *ptrNuevo = (TNodo*) malloc(sizeof (TNodo));
    ptrNuevo->dia = dia;  
    ptrNuevo->ini = ini;
    ptrNuevo->fin = fin;
    ptrNuevo->izq = ptrNuevo->der = NULL;
    
    if (*ptrArbol == NULL)  
        *ptrArbol = ptrNuevo;
    else 
    {	ptraux=*ptrArbol;
    	if(ptraux->dia*10000+ptraux->ini*100+ptraux->fin > dia*10000+ini*100+fin)  
            if(ptraux->izq==NULL)
                ptraux->izq=ptrNuevo;
            else
            {	ptraux=ptraux->izq;
                inserta_nodoR(&ptraux,dia,ini,fin);
            }	
        else
            if(ptraux->der==NULL)
	  	ptraux->der=ptrNuevo;
            else
            {	ptraux=ptraux->der;
                inserta_nodoR(&ptraux,dia, ini,fin);
            }	
    }
}

TArbol buscaM(TArbol ptrArbol)
{
    if (ptrArbol==NULL)
        return NULL;
    else
    {   
	if(ptrArbol->izq!=NULL)
            return(buscaM(ptrArbol->izq));
    	else
            return (ptrArbol);
	}
}
/*
TArbol borranodo(TArbol ptr_arbol, int valor) 
{   if (ptr_arbol == NULL)
    {    
        printf("Valor no encontrado\n");
        return ptr_arbol; 
    }
    if (valor < ptr_arbol->lote) 
        ptr_arbol->izq = borranodo(ptr_arbol->izq, valor); 
    else 
        if (valor > ptr_arbol->lote) 
            ptr_arbol->der = borranodo(ptr_arbol->der, valor); 
        else
        {   if (ptr_arbol->izq == NULL) 
            { 
                TArbol temp = ptr_arbol->der; 
                free(ptr_arbol); 
                return temp; 
            }    
            else if (ptr_arbol->der == NULL) 
            { 
                TArbol temp = ptr_arbol->izq; 
                free(ptr_arbol); 
                return temp; 
            } 
            TArbol temp = buscaM(ptr_arbol->der); 
            ptr_arbol->lote = temp->lote; 
            ptr_arbol->der = borranodo(ptr_arbol->der, temp->lote); 
        } 
        return ptr_arbol; 
}
*/
void en_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        en_orden(ptrArbol->izq);
        printf("%02d-%02d:%02d\n", ptrArbol->dia,ptrArbol->ini,ptrArbol->fin);
        en_orden(ptrArbol->der);
    }
}
