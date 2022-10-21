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
//////////////////////////////////////////////////////////


TArbol buscaM(TArbol ptrArbol){
    if(ptrArbol==NULL)
        return NULL;
    else
    {
        if(ptrArbol->izq!=NULL)
            return(buscaM(ptrArbol->izq));
        else
            return(ptrArbol);
    }    
    
}

TArbol borranodo(TArbol ptr_arbol, int valor){
    if(ptr_arbol == NULL)
    {   printf("Valor no encontrado");
        return ptr_arbol;
    }
    if( valor < ptr_arbol->elem)
        ptr_arbol ->izq = borranodo(ptr_arbol->izq,valor);
    else
        if(valor > ptr_arbol->elem)
            ptr_arbol->der = borranodo(ptr_arbol->der,valor);
        else{
            if(ptr_arbol->izq ==NULL){
                TArbol temp = ptr_arbol->der;
                free(ptr_arbol);
                return temp;
            }  
            else  if(ptr_arbol->der ==NULL){
                TArbol temp = ptr_arbol->izq;
                free(ptr_arbol);
                return temp;
            }  
            TArbol temp = buscaM(ptr_arbol->der);
            ptr_arbol->elem = temp->elem;
            ptr_arbol->der = borranodo(ptr_arbol->der,temp->elem);
       
        }
    return ptr_arbol;
}





int main(int argc, char** argv) {
    TArbol ptrArbol,ptrMenor;

    crea_arbol(&ptrArbol);
    inserta_nodo(&ptrArbol, 10);
    inserta_nodo(&ptrArbol, 8);
    inserta_nodo(&ptrArbol, 6);
    inserta_nodo(&ptrArbol, 4);
    inserta_nodo(&ptrArbol, 9);
    inserta_nodo(&ptrArbol, 15);
    inserta_nodo(&ptrArbol, 20);
    inserta_nodo(&ptrArbol, 18);
    
    en_orden(ptrArbol);
    printf("\nTiene %d nodos",cuenta(ptrArbol));
    if(busca(ptrArbol,9)) printf("\nEncontro");
    else printf("No encontro");
    
    ptrMenor = buscaM(ptrArbol);
    printf("\nEl menor es: %d\n",ptrMenor->elem);
    
    ptrArbol = borranodo(ptrArbol,15);
    
    en_orden(ptrArbol);
    
    return (0);

}
