#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "amplitud.h"

int main() {
    TNodoVertice *ptrListaVertices = CreaGrafo();

    ptrListaVertices = InsertaVertice(ptrListaVertices, 'A');
    ptrListaVertices = InsertaVertice(ptrListaVertices, 'B');
    ptrListaVertices = InsertaVertice(ptrListaVertices, 'C');
    ptrListaVertices = InsertaVertice(ptrListaVertices, 'D');
    ptrListaVertices = InsertaVertice(ptrListaVertices, 'E');
    ptrListaVertices = InsertaVertice(ptrListaVertices, 'F');
    //ptrListaVertices = InsertaVertice(ptrListaVertices, 'G');
    //ptrListaVertices = InsertaVertice(ptrListaVertices, 'H');
    //ptrListaVertices = InsertaVertice(ptrListaVertices, 'I');

    InsertaArista(ptrListaVertices, 'A', 'B', 0);
    InsertaArista(ptrListaVertices, 'A', 'C', 0);
    InsertaArista(ptrListaVertices, 'A', 'D', 0);
    InsertaArista(ptrListaVertices, 'C', 'E', 0);
    //InsertaArista(ptrListaVertices, 'D', 'E', 0);
    InsertaArista(ptrListaVertices, 'D', 'F', 0);
        
    ImprimeGrafo(ptrListaVertices);
    printf("\n");
    printf("\n");
    /*TODO: Haga un esquema del grafo antes de analisar el algoritmo*/
    BusquedaEnAmplitud(ptrListaVertices, 'A', 'F');

    LiberaGrafo(ptrListaVertices);

    return (EXIT_SUCCESS);
}

