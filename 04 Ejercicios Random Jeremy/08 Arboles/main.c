/* 
 * File:   main.c
 * Author: ANDRES
 * Nombre: Andres Sarmiento Miranda
 * Codigo: 20203869
 * Created on 28 de octubre de 2022, 01:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <math.h>
int main(int argc, char** argv) {
    ArbolBinario arbol;
    construirArbol(&arbol);
    ElementoArbol elemento;
    elemento.lote=4;
    elemento.cantidad=12;
    insertar(&arbol,elemento);
    elemento.lote=5;
    elemento.cantidad=3;
    insertar(&arbol,elemento);
    elemento.lote=3;
    elemento.cantidad=15;
    insertar(&arbol,elemento);
    elemento.lote=6;
    elemento.cantidad=8;
    insertar(&arbol,elemento);
    elemento.lote=8;
    elemento.cantidad=20;
    insertar(&arbol,elemento);
    elemento.lote=1;
    elemento.cantidad=10;
    insertar(&arbol,elemento);
    elemento.lote=7;
    elemento.cantidad=7;
    insertar(&arbol,elemento);
    recorrerEnPreOrden(arbol);
    int cantidad=12;
    //despachar(&arbol,&cantidad);
    //printf("\n");
    //incrementar(&arbol,1,6);
    equilibrar(&arbol);
    printf("\n");
    recorrerEnPreOrden(arbol);
    return (EXIT_SUCCESS);
}
void  equilibrar(ArbolBinario *arbol){
    Nodo *nodo;
    int cantNod1,cantNod2,nodosTota;
    ElementoArbol elemento1,elemento2;
    while(1){
        cantNod1=contarNodos((*arbol)->hizq);
        cantNod2=contarNodos((*arbol)->hder);
        nodosTota=abs(cantNod1-cantNod2);
        if(nodosTota<=1){
            break;
        }
        else{
            if(cantNod1<cantNod2){
                nodo=buscarUltimoDerecha((*arbol)->hder);
                
            }
            else{
                nodo=buscarUltimoIzquierda((*arbol)->hizq);
            }
            elemento1.cantidad=nodo->elemento.cantidad;
            elemento1.lote=nodo->elemento.lote;
            eliminar(arbol,elemento1);
            elemento2.cantidad=(*arbol)->elemento.cantidad;
            elemento2.lote=(*arbol)->elemento.lote;
            (*arbol)->elemento.cantidad=elemento1.cantidad;
            (*arbol)->elemento.lote=elemento1.lote;
            insertar(arbol,elemento2);
        }
    }
}
Nodo *buscarUltimoDerecha(ArbolBinarioBusqueda arbol){
    Nodo *nodo;
    nodo=arbol;
    while(nodo->hizq!=NULL){
        nodo=nodo->hizq;
    }
    return nodo;
}
Nodo *buscarUltimoIzquierda(ArbolBinarioBusqueda arbol){
    Nodo *nodo;
    nodo=arbol;
    while(nodo->hder!=NULL){
        nodo=nodo->hder;
    }
    return nodo;
}
void incrementar(ArbolBinario *arbol,int lote,int cantidad){
    Nodo *nodo,*aux,*ptr;
    ElementoArbol elemento;
    elemento.lote=lote;
    nodo=buscar(*arbol,elemento);
    ptr=nodo;
    aux=crearNuevoNodo(NULL,elemento,NULL);
    aux->elemento.cantidad=nodo->elemento.cantidad + cantidad;
    aux->elemento.lote=lote;
    while(1){
        if(aux->elemento.cantidad>=nodo->elemento.cantidad){
            if(nodo->hder==NULL){
                nodo->hder=aux;
                eliminar(arbol,ptr->elemento);
                break;
            }
            nodo=nodo->hder;
        }
        else{
            if(nodo->hizq==NULL){
                nodo->hizq=aux;
                eliminar(arbol,ptr->elemento);
                break;
            }
            nodo=nodo->hizq;
        }
    }
    
}
void despachar(ArbolBinario *arbol,int *cantidad){
    if(*arbol==NULL || *cantidad==0){
        return;
    }
    Nodo *nodo;
    nodo=buscarAntiguo(*arbol);
    if(nodo->elemento.cantidad < *cantidad){
        *cantidad=*cantidad - nodo->elemento.cantidad;
        eliminar(arbol,nodo->elemento);
    }
    else{
        nodo->elemento.cantidad=nodo->elemento.cantidad - *cantidad;
        *cantidad=0;
    }
    despachar(arbol,cantidad);
}
Nodo * buscarAntiguo(ArbolBinario arbol){
    Nodo *aux;
    aux=arbol;
    while(aux->hizq!=NULL){
        aux=arbol->hizq;
    }
    return aux;
}