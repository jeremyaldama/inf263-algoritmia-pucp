
#include "arbol2.h"
#include <stdio.h>
#include <stdlib.h>

void crea_arbol(TArbol *ptrArbol) {
    *ptrArbol = NULL;
}


void inserta_nodoR(TArbol *ptrArbol, int lote,int cant) {
    TArbol ptraux;
    TNodo *ptrNuevo = (TNodo*) malloc(sizeof (TNodo));
    ptrNuevo->lote = lote;  
    ptrNuevo->cant=cant;   	
    ptrNuevo->izq = ptrNuevo->der = NULL;
    
    if (*ptrArbol == NULL)  
        *ptrArbol = ptrNuevo;
    else 
    {	ptraux=*ptrArbol;
    	if(ptraux->cant > cant)  
            if(ptraux->izq==NULL)
                ptraux->izq=ptrNuevo;
            else
            {	ptraux=ptraux->izq;
                inserta_nodoR(&ptraux,lote,cant);
            }	
        else
            if(ptraux->der==NULL)
	  	ptraux->der=ptrNuevo;
            else
            {	ptraux=ptraux->der;
                inserta_nodoR(&ptraux,lote,cant);
            }	
    }
}

void inserta_nodoD(TArbol *ptrArbol, int lote,int cant) {
    TArbol ptraux;
    TNodo *ptrNuevo = (TNodo*) malloc(sizeof (TNodo));
    ptrNuevo->lote = lote;  
    ptrNuevo->cant=cant;   	
    ptrNuevo->izq = ptrNuevo->der = NULL;
    
    if (*ptrArbol == NULL)  
        *ptrArbol = ptrNuevo;
    else 
    {	ptraux=*ptrArbol;
    	if(ptraux->cant >= cant)  
            if(ptraux->izq==NULL)
                ptraux->izq=ptrNuevo;
            else
            {	ptraux=ptraux->izq;
                inserta_nodoD(&ptraux,lote,cant);
            }	
        else
            if(ptraux->der==NULL)
	  	ptraux->der=ptrNuevo;
            else
            {	ptraux=ptraux->der;
                inserta_nodoD(&ptraux,lote,cant);
            }	
    }
}

TArbol busca(TArbol ptrArbol,int valor)
{
    if (ptrArbol==NULL)
        return NULL;
    else
    {   if(ptrArbol->cant==valor)
            return ptrArbol;
        else
        {
            if(ptrArbol->cant<valor)
                ptrArbol=ptrArbol->der;
            else
                ptrArbol=ptrArbol->izq;
            return(busca(ptrArbol,valor));
        }
    }
}


TArbol buscalote(TArbol ptrArbol,int lote)
{   TArbol ptraux=NULL;

    if (ptrArbol==NULL)
        return NULL;
    else
    {   if(ptrArbol->lote==lote)
            return ptrArbol;
        else
        {
            if(ptrArbol->der!=NULL)
                ptraux=buscalote(ptrArbol->der,lote);
            if(ptraux == NULL)    
                if(ptrArbol->izq!=NULL)
                   ptraux= buscalote(ptrArbol->izq,lote);
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

TArbol buscaX(TArbol ptrArbol)
{
    if (ptrArbol==NULL)
        return NULL;
    else
    {   
	if(ptrArbol->der!=NULL)
            return(buscaX(ptrArbol->der));
    	else
            return (ptrArbol);
	}
}

TArbol borranodo(TArbol ptr_arbol, int valor) 
{   if (ptr_arbol == NULL)
    {    
        printf("Valor no encontrado\n");
        return ptr_arbol; 
    }
    if (valor < ptr_arbol->cant) 
        ptr_arbol->izq = borranodo(ptr_arbol->izq, valor); 
    else 
        if (valor > ptr_arbol->cant) 
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
            ptr_arbol->cant = temp->cant; 
            ptr_arbol->lote = temp->lote;
            ptr_arbol->der = borranodo(ptr_arbol->der, temp->cant); 
        } 
        return ptr_arbol; 
}

TArbol borranodo2(TArbol ptr_arbol,int lote, int valor) 
{   if (ptr_arbol == NULL)
    {    
        printf("Valor no encontrado\n");
        return ptr_arbol; 
    }
    if (valor < ptr_arbol->cant) 
        ptr_arbol->izq = borranodo2(ptr_arbol->izq, lote,valor); 
    else 
        if (valor == ptr_arbol->cant && lote == ptr_arbol->lote){
            if (ptr_arbol->izq == NULL) 
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
                ptr_arbol->cant = temp->cant; 
                ptr_arbol->lote = temp->lote;
                ptr_arbol->der = borranodo2(ptr_arbol->der,temp->lote, temp->cant);    

        } 
        else
        {   
            ptr_arbol->der = borranodo2(ptr_arbol->der,lote, valor); 
        } 
        return ptr_arbol; 
}

void en_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        en_orden(ptrArbol->izq);
        printf("%3d-%3d", ptrArbol->lote,ptrArbol->cant);
        en_orden(ptrArbol->der);
    }
}

void pre_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        printf("%3d-%3d  ", ptrArbol->cant,ptrArbol->lote);
        pre_orden(ptrArbol->izq);
        pre_orden(ptrArbol->der);
    }
}