#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

TNodoLista * InicializaLista() {
    return NULL;
}

TNodoLista *InsertaLista(TNodoLista *ptrLista, TNodoVertice* ValorLista) {
    TNodoLista *ptrNuevo, *ptrAnterior, *ptrRecorrido;

        ptrNuevo = (TNodoLista *) malloc(1 * sizeof (TNodoLista));
        ptrNuevo->ValorLista = ValorLista;
        ptrNuevo->ptrSig = NULL;

        ptrAnterior = NULL;
        ptrRecorrido = ptrLista;
        while (ptrRecorrido) {
            ptrAnterior = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->ptrSig;
        }
        if (ptrAnterior == NULL)
            ptrLista = ptrNuevo;
        else
            ptrAnterior->ptrSig = ptrNuevo;
    
    return ptrLista;
}

int Pertenece(TNodoLista *ptrLista, TNodoVertice* ValorLista){
    while (ptrLista){
        if (ptrLista->ValorLista == ValorLista)
            return 1;
        ptrLista = ptrLista->ptrSig;
    }
    return 0;
}

void ImprimeLista(TNodoLista *ptrLista){
    int imprime_coma=0;
    printf("{");
    while (ptrLista != NULL){
        if (imprime_coma)
            printf(", ");
        else
            imprime_coma = 1;
        printf("%c", ptrLista->ValorLista->ValorNodo);
        ptrLista = ptrLista->ptrSig;
    }
    printf("}\n");
}

void LiberaLista(TNodoLista *ptrLista){
    TNodoLista *ptrEliminar;
    while (ptrLista != NULL){
        ptrEliminar = ptrLista;
        ptrLista = ptrLista->ptrSig;
        free(ptrEliminar);
    }
}