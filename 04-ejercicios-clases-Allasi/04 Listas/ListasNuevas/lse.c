#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

void construirLista(Lista *tad){
    tad->cabeza = NULL;
    tad->longitud = 0;
}

int esListaVacia(Lista tad){
    return tad.cabeza == NULL;
}

void insertarAlInicio(Lista *tad, ElementoLista elemento){
    Nodo *nuevoNodo = crearNuevoNodo(elemento, tad->cabeza);
    tad->cabeza = nuevoNodo;
    tad->longitud++;
}

Nodo *crearNuevoNodo(ElementoLista elemento, Nodo *sig){
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->elemento = elemento;
    nuevoNodo->sig = sig;
    return nuevoNodo;
}

void insertarAlFinal(Lista *tad, ElementoLista elemento){
    Nodo *nuevoNodo = crearNuevoNodo(elemento, NULL);
    Nodo *ultimoNodo = obtenerUltimoNodo(*tad);
    //Puede pasar que la lista esté vacía, en este caso no existen nodos,
    //y por tanto no existirá último nodo. En esta situación la func retornará NULL
    if (ultimoNodo == NULL) tad->cabeza = nuevoNodo;
    else ultimoNodo->sig = nuevoNodo;
    tad->longitud++;
}

Nodo *obtenerUltimoNodo(Lista tad){
    Nodo *ultimo = NULL;
    Nodo *recorrido = tad.cabeza;
    while (recorrido != NULL){
        ultimo = recorrido;
        recorrido = recorrido->sig;
    }
    return ultimo;
}

void insertarEnOrden(Lista *tad, ElementoLista elemento){
    Nodo *nuevoNodo = crearNuevoNodo(elemento, NULL);
    Nodo *nodoAnterior = obtenerNodoAnterior(*tad, elemento);
    //Puede que no exista un nodo anterior, esto sucede cuando: 
    //la lista está vacía o cuando se inserta al inicio
    if (nodoAnterior == NULL){
        nuevoNodo->sig = tad->cabeza;//cabeza de la lista
        tad->cabeza = nuevoNodo;//cabeza apunta al nuevo nodo
    }
    else{
        nuevoNodo->sig = nodoAnterior->sig;
        nodoAnterior->sig = nuevoNodo;
    }
    tad->longitud++;
}

void *obtenerNodoAnterior(Lista tad,ElementoLista elemento){
    Nodo *anterior = NULL;
    Nodo *recorrido = tad.cabeza;
    while (recorrido != NULL && recorrido->elemento < elemento){
        anterior = recorrido;
        recorrido = recorrido->sig;
    }
    return anterior;
}

void destruirLista(Lista *tad){
    Nodo *recorrido = tad->cabeza;
    while (recorrido != NULL){
        Nodo *nodoAEliminar = recorrido;
        recorrido = recorrido->sig;
        free(nodoAEliminar);
    }
    tad->cabeza = NULL;//la lista queda vacía-> la cabeza debe apuntar a NULL
    tad->longitud = 0;
}

int longitud(Lista tad){
    return tad.longitud;
}

//se va a recorrer la lista usando el recorrido secuencial
void imprime(Lista tad){
    Nodo *recorrido = tad.cabeza;
    int imprimeCabeza = 1;
    printf("[");
    while (recorrido != NULL){
        if (!imprimeCabeza) printf(", ");
        else
            imprimeCabeza = 0;
        printf("%d", recorrido->elemento);
        recorrido = recorrido->sig;
    }
    printf("]\n");
}

Nodo *seEncuentra(Lista tad, ElementoLista llave){//busqueda secuencial
    Nodo *recorrido = tad.cabeza;
    while (recorrido != NULL && recorrido->elemento != llave){
        recorrido = recorrido->sig;
    }
    return recorrido;
}

int estaEnLista(Lista ptrLista, int elem){
    Nodo *recorr;
    recorr = ptrLista.cabeza;
    while (recorr){
        if (recorr->elemento == elem) return 1;
        recorr = recorr->sig;
    }
    return 0;
}

void invierte(Lista *lista){
    if (esListaVacia(*lista)) return;
    int i, j, n;
    Nodo *recorr, *ant, *ini;
    n = lista->longitud;
    
    for (i = 1; i < n; i++){
        recorr = lista->cabeza;
        
        for (j = i; j < n; j++){
            ant = recorr;
            recorr = recorr->sig;
        }
        if (i == 1) ini = recorr;
        recorr->sig = ant;
    }
    if (i != 1){
        ant->sig = NULL;
        lista->cabeza = ini;
    }
}

void invierteRecursivo(Lista*lista){
    Nodo *ini;
    ini = recorreRec(lista->cabeza);
    lista->cabeza = ini;
}

Nodo *recorreRec(Nodo *cabeza){
    Nodo *ini;
    
    if (cabeza == NULL) return NULL;
    if (cabeza->sig == NULL) return cabeza;
    
    ini = recorreRec(cabeza->sig);
    cabeza->sig->sig = cabeza;
    cabeza->sig = NULL;
    
    return ini;
}

