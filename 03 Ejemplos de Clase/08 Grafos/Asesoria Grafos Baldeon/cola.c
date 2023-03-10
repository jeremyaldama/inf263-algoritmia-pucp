#include <stdlib.h>
#include "cola.h"

TNodoCola * InicializaCola() {
    return NULL;
}

int ColaVacia(TNodoCola *ptrCola){
    return ptrCola==NULL;
}

TNodoCola * PideTurno(TNodoCola *ptrCola, TNodoVertice* ValorCola) {
    TNodoCola *ptrNuevo;
    ptrNuevo = (TNodoCola *) malloc(sizeof (TNodoCola));
    ptrNuevo->ValorCola = ValorCola;
    ptrNuevo->ptrSig = ptrCola;
    ptrCola = ptrNuevo;
    return ptrCola;
}

TNodoCola *Avanze(TNodoCola *ptrCola, TNodoVertice** ValorCola){
    TNodoCola *ptrRecorrido, *ptrAnterior;

    if (!ColaVacia(ptrCola)){
    
        ptrAnterior = NULL;
        ptrRecorrido = ptrCola;
        while ( ptrRecorrido->ptrSig != NULL){
            ptrAnterior = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->ptrSig;
        }
        if (ptrAnterior == NULL)
            ptrCola = NULL; 
        else
            ptrAnterior->ptrSig = NULL;        

        *ValorCola = ptrRecorrido->ValorCola;
        free(ptrRecorrido);
    }
    return ptrCola;
}

void LiberaCola(TNodoCola *ptrCola){
    TNodoCola *ptrEliminar;
    while (ptrCola != NULL){
        ptrEliminar = ptrCola;
        ptrCola = ptrCola->ptrSig;
        free(ptrEliminar);
    }
}