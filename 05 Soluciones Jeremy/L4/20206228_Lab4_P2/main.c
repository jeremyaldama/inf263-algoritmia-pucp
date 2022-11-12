/* 
 * File:   main.c
 * Author: Jeremy Aldama 20206228
 *
 * Created on 5 de noviembre de 2022, 15:01
 */

#include <stdio.h>
#include <stdlib.h>

#include "ABB.h"

int hash(int fecha, int stock){
    //ordenado por fecha, suponiendo que el stock de lote sea hasta 99
    return fecha*100 + stock;
}

int ObtenerFecha(int hash){
    return hash/100;
}

int ObtenerStock(int hash){
    return hash%100;
}

void recorrerEnOrden(ArbolBinario AB){
    ArbolBinario ABI,ABD;
    if(!esArbolVacio(AB)){
        ABI=AB->hizq;
        ABD=AB->hder;
        recorrerEnOrden(ABI);
        int fecha, stock;
        fecha = ObtenerFecha(AB->elemento);
        stock = ObtenerStock(AB->elemento);
        printf("(%d - %d) ", fecha, stock);
        recorrerEnOrden(ABD);
    }
}

void recorrerEnPreOrden(ArbolBinario AB){
    ArbolBinario ABI,ABD;
    if(!esArbolVacio(AB)){
        ABI=AB->hizq;
        ABD=AB->hder;
        int fecha, stock;
        fecha = ObtenerFecha(AB->elemento);
        stock = ObtenerStock(AB->elemento);
        printf("(%d - %d) ", fecha, stock);
        
        recorrerEnPreOrden(ABI);
        recorrerEnPreOrden(ABD);
    }
}

void insertar(ArbolBinarioBusqueda *pAAB, ElementoArbol elemento){
    Nodo *p,*padre;
    if(esArbolVacio(*pAAB))  
        plantar(pAAB,NULL,elemento,NULL);
    else{
        int fecha = ObtenerFecha(elemento);
        padre=NULL;
        p=*pAAB;
        while(p!=NULL){
            padre=p;
            if(fecha<ObtenerFecha(p->elemento))
                 p=p->hizq;
            else
                p=p->hder;
        }
        if(fecha < ObtenerFecha(padre->elemento))
            plantar(&padre->hizq,NULL,elemento,NULL);
        else
            plantar(&padre->hder,NULL,elemento,NULL);
    }
}

void IngresarDatos(ArbolBinarioBusqueda*arbol_destino, ArbolBinarioBusqueda*arbol_emisor){
    FILE*arch = fopen("datos.txt","r");
    int nodos_destino, nodos_emisor;
    fscanf(arch, "%d %d", &nodos_destino, &nodos_emisor);
    
    int fecha, stock, valor_hash;
    for (int i=0; i<nodos_destino; i++){
        fscanf(arch, "%d %d", &fecha, &stock);
        valor_hash = hash(fecha, stock);
        insertar(arbol_destino, valor_hash);
    }
    
    for (int i=0; i<nodos_emisor; i++){
        fscanf(arch, "%d %d", &fecha, &stock);
        valor_hash = hash(fecha, stock);
        insertar(arbol_emisor, valor_hash);
    }
    fclose(arch);
}

void InsertarEnArbolDestino(ArbolBinarioBusqueda *arbol_destino, ElementoArbol elemento){
    Nodo *p, *padre;
    p = *arbol_destino;
    
    int identificador = ObtenerFecha(elemento);
    
    while (p && identificador != ObtenerFecha(p->elemento)){
        padre = p;
        if (identificador<ObtenerFecha(p->elemento)){
            p = p->hizq;
        }
        else p = p->hder;
    }
    
    if (p!=NULL){
        int fecha = ObtenerFecha(p->elemento);
        int stock = ObtenerStock(p->elemento);
        p->elemento = hash(fecha, stock + ObtenerStock(elemento));
    }
    else{
        if (elemento < padre->elemento){
            plantar(&padre->hizq, NULL, elemento, NULL);
        }
        else
            plantar(&padre->hder, NULL, elemento, NULL);
    }
}

void FusionarAlmacenes(ArbolBinarioBusqueda*arbol_destino,
                       ArbolBinarioBusqueda*arbol_emisor){
    if (*arbol_emisor==NULL) return;
    
    FusionarAlmacenes(arbol_destino, &(*arbol_emisor)->hizq);
    FusionarAlmacenes(arbol_destino, &(*arbol_emisor)->hder);
    
    InsertarEnArbolDestino(arbol_destino, (*arbol_emisor)->elemento);
    ArbolBinarioBusqueda arbol_a_eliminar = *arbol_emisor;
    free(arbol_a_eliminar);
    *arbol_emisor = NULL;
    
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol_destino, arbol_emisor;
    construirArbol(&arbol_destino);
    construirArbol(&arbol_emisor);
    
    IngresarDatos(&arbol_destino, &arbol_emisor);
    printf("Antes:\n");
    printf("Preorden Destino: ");
    recorrerEnPreOrden(arbol_destino);
    printf("\nEnorden Destino: ");
    recorrerEnOrden(arbol_destino);
    
    printf("\n\nPreorden Emisor: ");
    recorrerEnPreOrden(arbol_emisor);
    printf("\nEnorden Emisor: ");
    recorrerEnOrden(arbol_emisor);
    
    FusionarAlmacenes(&arbol_destino, &arbol_emisor);
    
    printf("\n\n\nDespues:\n");
    printf("Preorden Destino: ");
    recorrerEnPreOrden(arbol_destino);
    printf("\nEnorden Destino: ");
    recorrerEnOrden(arbol_destino);
    
    printf("\n\nPreorden Emisor: ");
    recorrerEnPreOrden(arbol_emisor);
    printf("\nEnorden Emisor: ");
    recorrerEnOrden(arbol_emisor);
    return (EXIT_SUCCESS);
}

