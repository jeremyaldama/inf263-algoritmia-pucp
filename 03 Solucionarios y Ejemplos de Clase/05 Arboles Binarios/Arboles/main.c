/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 8 de junio de 2020, 01:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbol.h"
#define MAX 100

TArbol busca(TArbol ptrArbol,int valor)
{
    if (ptrArbol==NULL)
        return NULL;
    else
    {   if(ptrArbol->elem==valor)
            return ptrArbol;
        else
        {
            if(ptrArbol->elem<valor)
                ptrArbol=ptrArbol->der;
            else
                ptrArbol=ptrArbol->izq;
            return(busca(ptrArbol,valor));
        }
    }
}

int cuenta(TArbol ptrArbol) {
    int cont=0;
	if (ptrArbol) 
        cont=cuenta(ptrArbol->izq)+cuenta(ptrArbol->der)+1;
    return(cont);
    
}
//////////////////////////////////////////////////////////////////
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

TArbol borranodo(TArbol ptr_arbol, int valor) 
{   if (ptr_arbol == NULL)
    {   printf("Valor no encontrado\n");
        return ptr_arbol; 
    }
    if (valor < ptr_arbol->elem) 
        ptr_arbol->izq = borranodo(ptr_arbol->izq, valor); 
  
    else 
        if (valor > ptr_arbol->elem) 
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
            ptr_arbol->elem = temp->elem; 
            ptr_arbol->der = borranodo(ptr_arbol->der, temp->elem); 
        } 
        return ptr_arbol; 
}
//////////////////////////////////////////////////////////////////

int niveles(TArbol ptr_arbol){
	int izq=0,der=0,mayor;
	if(ptr_arbol==NULL)
		return 0;
	if(ptr_arbol->der!=NULL)
            der=niveles(ptr_arbol->der);
	if(ptr_arbol->izq!=NULL)
            izq=niveles(ptr_arbol->izq);
			
	if(izq>der)
		mayor=izq;
	else
		mayor=der;
	return (1+mayor);
			
}

int esbalanceado(TArbol ptrArbol){
    int der,izq;
    if(!ptrArbol)
	return 1;
    der=niveles(ptrArbol->der);
    izq=niveles(ptrArbol->izq);
    if((fabs(der-izq)==1 || der-izq==0 )&& esbalanceado(ptrArbol->der) 
    	&&esbalanceado(ptrArbol->izq) )
    return 1;
    else 
        return 0;
	
}
//////////////////////////////////////////////////////////////////
int resultado[MAX];

int cargaenorden(TArbol ptrArbol,int n) {
    if (ptrArbol) {
        n=cargaenorden(ptrArbol->izq,n);
        resultado[n]= ptrArbol->elem;
        n++;
        n=cargaenorden(ptrArbol->der,n);
    }
    return n;
}

int repetidos(TArbol ptrArbol){
	int i,n;
	if(ptrArbol)
	{
            n=cargaenorden(ptrArbol,0);
            for(i=0;i<n-1;i++)
            	if(resultado[i]==resultado[i+1])
                    return 1;	
	}	
	return 0;
}
//////////////////////////////////////////////////////////


void junta(TArbol* ptrArbol1,TArbol* ptrArbol2){
    int valor;
    TNodo* paux;
    paux = *ptrArbol2;
    if (paux) {
        junta(ptrArbol1,&paux->izq);
        junta(ptrArbol1,&paux->der);
        valor = paux->elem;
        free(paux); 
        inserta_nodo(ptrArbol1, valor);
        *ptrArbol2 = NULL;
    }
    
}


int main(int argc, char** argv) {
    TArbol ptrArbol,ptrMenor,ptrArbol2;

    crea_arbol(&ptrArbol);
    inserta_nodo(&ptrArbol, 8);
    inserta_nodo(&ptrArbol, 2);
    inserta_nodo(&ptrArbol, 15);
    inserta_nodo(&ptrArbol, 6);
    inserta_nodo(&ptrArbol, 5);
    printf("\nArbol1:");
    en_orden(ptrArbol);
    
    crea_arbol(&ptrArbol2);
    inserta_nodo(&ptrArbol2, 10);
    inserta_nodo(&ptrArbol2, 7);
    inserta_nodo(&ptrArbol2, 9);
    inserta_nodo(&ptrArbol2, 4);
    inserta_nodo(&ptrArbol2, 16);
    printf("\nArbol2:");
    en_orden(ptrArbol2);
    
    junta(&ptrArbol,&ptrArbol2);
    printf("\nUnion:");
    pre_orden(ptrArbol);
    printf("\nQueda:");
    en_orden(ptrArbol2);
    
    
    /*
    ptrMenor = buscaM(ptrArbol);
    printf("\nEl menor es:%d",ptrMenor->elem);
    ptrArbol=borranodo(ptrArbol,15);
    printf("\n");
    en_orden(ptrArbol); 
    printf("\n");
    if(busca(ptrArbol,0)) printf("Encontro");
    else printf("No encontro");
    printf("\nHay %d nodos\n",cuenta(ptrArbol));
    
    printf("\nEn orden:\n");
    en_orden(ptrArbol);
    printf("\nPre Orden:\n");
    pre_orden(ptrArbol);
    printf("\nPost Orden:\n");
    pos_orden(ptrArbol);
 
    printf("\nNiveles:%d\n",niveles(ptrArbol));    

    if(esbalanceado(ptrArbol))
    	printf("\nEs balanceado");
    else 	
    	printf("\nNo es balanceado\n");
    	
    if(repetidos(ptrArbol))
    	printf("\nTiene repetidos\n");
    else 	
    	printf("\nNo hay repetidos\n");
    */
    
    
    return (0);
}

