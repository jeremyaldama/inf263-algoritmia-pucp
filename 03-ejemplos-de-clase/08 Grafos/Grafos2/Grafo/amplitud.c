#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "cola.h"
#include "lista.h"

void BusquedaEnAmplitud(TNodoVertice *ptrListaVertices, 
        TNodoGrafo Estado_Inicial, 
        TNodoGrafo Estado_Meta){
    TNodoVertice *ptrU;
    TNodoCola *ptrEstado = InicializaCola();
    TNodoLista *ptrVisitados = InicializaLista();
    TNodoVertice *ptrP = NULL;
    TNodoArista *ptrHijos_P = NULL;
    TNodoVertice *ptrEstado_Inicial = ExisteVertice(ptrListaVertices, Estado_Inicial);
    TNodoVertice *ptrEstado_Meta = ExisteVertice(ptrListaVertices, Estado_Meta);

    if (ptrEstado_Inicial && ptrEstado_Meta){
        ptrEstado = PideTurno(ptrEstado, ptrEstado_Inicial);
        while (!ColaVacia(ptrEstado) && ptrP!=ptrEstado_Meta){
            ptrEstado = Avanze(ptrEstado, &ptrP);
            ptrVisitados = InsertaLista(ptrVisitados, ptrP);
            printf("\n%c",ptrP->ValorNodo);
            ptrHijos_P = ptrP->ptrListaArista;
            while (ptrHijos_P){
                ptrU = ExisteVertice(ptrListaVertices, ptrHijos_P->ValorNodo);
                if (ptrU)
                    if (!Pertenece(ptrVisitados, ptrU))
                        ptrEstado = PideTurno(ptrEstado, ptrU);
                ptrHijos_P = ptrHijos_P->ptrSigArista;
            }
        }
    }
    ImprimeLista(ptrVisitados);

    LiberaCola(ptrEstado);
    LiberaLista(ptrVisitados);
}

