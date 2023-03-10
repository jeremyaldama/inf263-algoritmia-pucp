/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva.r
 *
 * Created on 19 de septiembre de 2022, 12:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

void invierte(Lista *lista){
    int i,j,n;
    Nodo *paux,*ptr,*pini;
    if(es_lista_vacia(*lista)) return;
    n = lista->longitud;
    for(i=1;i<n;i++){
        ptr=lista->cabeza;
        for(j=i;j<n;j++){
            paux=ptr;
            ptr=ptr->sig;
        }
        if(i==1)
            pini = ptr;
        ptr->sig = paux;
    }
    if(i!=1){
        paux->sig = NULL;
        lista->cabeza = pini;  
    }
   
}
Nodo *recorre(Nodo*ptr){
    Nodo *pini;
    if(ptr==NULL) return NULL;
    if(ptr->sig==NULL) return ptr;
    pini = recorre(ptr->sig);
    ptr->sig->sig = ptr;
    ptr->sig = NULL;
    return pini;
}


void invierterec(Lista *ptr){
    Nodo * pini;
    //se puede ser en una linea
    pini = recorre(ptr->cabeza);
    ptr->cabeza = pini;
    
}

void invierteRecursivo(Nodo*q, Nodo*p, Lista*lst){
    if (p){
        invierteRecursivo(p, p->sig, lst);
        p->sig = q;
    }
    else{
        lst->cabeza = q;
    }
}

int main(int argc, char** argv) {
    Lista lista1;
    
    construir(&lista1);
    insertar_orden(&lista1,8);
    insertar_orden(&lista1,2);
    insertar_orden(&lista1,6);
    insertar_orden(&lista1,3);
    insertar_orden(&lista1,1);
    insertar_orden(&lista1,7);
    imprimir(lista1);
    invierte(&lista1);
    imprimir(lista1);
    invierterec(&lista1);
    imprimir(lista1);
    
    invierteRecursivo(NULL,lista1.cabeza, &lista1);
    imprimir(lista1);
    return 0;
}

