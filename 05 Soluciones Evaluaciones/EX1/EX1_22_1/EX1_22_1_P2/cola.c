#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void ConstruirCola(Cola *tad){
    tad->cabeza = NULL;
    tad->CabVip = NULL;
    tad->CabCli = NULL;
    tad->ultimoCli = NULL;
    tad->ultimoVip = NULL;
    tad->CabNoCli = NULL;
    tad->ultimoNoCli = NULL;
}

NodoCola *crearNuevoNodo(ElementoCola elemento, NodoCola *sig){
    NodoCola *nuevo = (NodoCola*)malloc(sizeof(NodoCola));
    nuevo->elemento = elemento;
    nuevo->sig = sig;
    return nuevo;
}

/*
NodoCola* obtenerUltimoNodoCola(Cola*tad, ElementoCola elem){
    NodoCola *rec;
    NodoCola *ultimo = NULL;
    if (elem.tipo=='V')    rec = tad->CabVip;
    else if (elem.tipo=='C') rec = tad->CabCli;
    else if (elem.tipo=='N') rec = tad->CabNoCli;
    else exit(1);
    while (rec!=NULL && rec->elemento.tipo==elem.tipo &&
           rec->elemento.orden<elem.orden){
            ultimo = rec;
            rec = rec->sig;
    }
    return ultimo;
}
*/

void Encolar(Cola*tad, ElementoCola elemento){
    NodoCola *nuevoNodo = crearNuevoNodo(elemento, NULL);
    
    char tipo = elemento.tipo;
    
    if (tad->cabeza==NULL){
        tad->cabeza = nuevoNodo;
        if (tipo=='V'){
            tad->CabVip = nuevoNodo;
            tad->ultimoVip = nuevoNodo;
        }
        else if (tipo=='C'){
            tad->CabCli = nuevoNodo;
            tad->ultimoCli = nuevoNodo;
        }
        else{
            tad->CabNoCli = nuevoNodo;
            tad->ultimoNoCli = nuevoNodo;
        }
    }
    else{
        if (tipo=='V'){
            if (tad->CabVip==NULL){
                //encolamos al nuevo nodo todo lo que estaba en la cabeza, ya
                //que es vip y debe ir al inicio
                nuevoNodo->sig = tad->cabeza;
                //la cabeza debe ahora apuntar al nuevoNodo Vip
                tad->ultimoVip = nuevoNodo;
                tad->cabeza = nuevoNodo;
                //1er vip
                tad->CabVip = nuevoNodo;
            }
            else{
                tad->ultimoVip->sig = nuevoNodo;
                tad->ultimoVip = nuevoNodo;
            }
            nuevoNodo->sig = tad->CabCli;
        }
        else if (tipo=='C'){
            if (tad->CabCli==NULL){
                tad->CabCli = nuevoNodo;
                tad->ultimoCli = nuevoNodo;
            }
            else{
                tad->ultimoCli->sig = nuevoNodo;
                tad->ultimoCli = nuevoNodo;
            }
            nuevoNodo->sig = tad->CabNoCli;
        }
        else{
            if (tad->CabNoCli==NULL){
                tad->CabNoCli = nuevoNodo;
                tad->ultimoNoCli = nuevoNodo;
            }
            else{
                tad->ultimoNoCli->sig = nuevoNodo;
                tad->ultimoNoCli = nuevoNodo;
            }
        }
    }
}

ElementoCola Desencolar(Cola*tad){
    NodoCola *nodoElim = tad->cabeza;
    tad->cabeza = nodoElim->sig;
    ElementoCola elem;
    elem = nodoElim->elemento;
    free(nodoElim);
    return elem;
}

void MostrarCola(Cola tad){
    NodoCola *rec = tad.cabeza;
    while (rec){
        printf("%c %d, ", rec->elemento.tipo, rec->elemento.orden);
        rec = rec->sig;
    }
}

