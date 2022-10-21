#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

/*Función para crear el grafo. Inicialmente el grafo estará vacío.*/
TNodoVertice *CreaGrafo() {
    return NULL;
}

/*Función que libera toda la memoria reservada para el grafo. Realiza una iteración
 en la cual se eliminan todos los vértices, pero antes de eliminar cada vértice,
 se procede a liberar las aristas de dicho vértice.*/
void LiberaGrafo(TNodoVertice * ptrListaVertices) {
    while (ptrListaVertices) {
        TNodoVertice *ptrVerticeAEliminar = ptrListaVertices;
        TNodoArista *ptrListaAristas;
        ptrListaAristas = ptrVerticeAEliminar->ptrListaArista;
        LiberaAristas(ptrListaAristas);
        ptrListaVertices = ptrListaVertices->ptrSigVertice;
        free(ptrVerticeAEliminar);
    }
}

/*Función que libera toda la memoria reservadad para las aristas. Esta función
 es usada dentro de la función LiberaGrafo para liberar las aristas adyacentes
 a un determinado vértice.*/
void LiberaAristas(TNodoArista *ptrListaAristas) {
    while (ptrListaAristas) {
        TNodoArista *ptrAristaAEliminar = ptrListaAristas;
        ptrListaAristas = ptrListaAristas->ptrSigArista;
        free(ptrAristaAEliminar);
    }
}

/*Función que verifica la existencia de un vértice en un grafo. Retorna NULL si 
 es que el nodo consultado no existe. Caso exista, retorna un puntero al nodo.*/

TNodoVertice *ExisteVertice(TNodoVertice *ptrListaVertices, 
        TNodoGrafo ValorNodo) {
    while (ptrListaVertices) {
        if (ptrListaVertices->ValorNodo == ValorNodo)
            return ptrListaVertices;
        ptrListaVertices = ptrListaVertices->ptrSigVertice;
    }
    return NULL;
}

/*Función que inserta un nodo en la lista de vértices. Se implementará usando
 una inserción al final en una lista simplemente enlazada.*/

TNodoVertice *InsertaVertice(TNodoVertice *ptrListaVertices, 
        TNodoGrafo ValorNodo) {
    TNodoVertice *ptrNuevo, *ptrAnterior, *ptrRecorrido;

    if (!ExisteVertice(ptrListaVertices, ValorNodo)) {
        ptrNuevo = (TNodoVertice *) malloc(1 * sizeof (TNodoVertice));
        ptrNuevo->ValorNodo = ValorNodo;
        ptrNuevo->ptrListaArista = NULL;
        ptrNuevo->ptrSigVertice = NULL;

        ptrAnterior = NULL;
        ptrRecorrido = ptrListaVertices;
        while (ptrRecorrido) {
            ptrAnterior = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->ptrSigVertice;
        }
        if (ptrAnterior == NULL)
            ptrListaVertices = ptrNuevo;
        else
            ptrAnterior->ptrSigVertice = ptrNuevo;
    }
    return ptrListaVertices;
}

void InsertaArista(TNodoVertice *ptrListaVertices, 
        TNodoGrafo Vertice1, 
        TNodoGrafo Vertice2, 
        double Peso) {
    TNodoVertice *ptrNodoVertice1 = ExisteVertice(ptrListaVertices, Vertice1);
    
    if (ptrNodoVertice1 && 
            ExisteVertice(ptrListaVertices, Vertice2) &&
            !ExisteArista(ptrNodoVertice1, Vertice2)) {
        TNodoArista *ptrNuevo, *ptrAnterior, *ptrRecorrido;

        ptrNuevo = (TNodoArista *) malloc(1 * sizeof (TNodoArista));
        ptrNuevo->ValorNodo = Vertice2;
        ptrNuevo->Peso = Peso;
        ptrNuevo->ptrSigArista = NULL;

        ptrAnterior = NULL;
        ptrRecorrido = ptrNodoVertice1->ptrListaArista;
        
        while (ptrRecorrido) {
            ptrAnterior = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->ptrSigArista;
        }
        if (ptrAnterior == NULL)
            ptrNodoVertice1->ptrListaArista = ptrNuevo;
        else
            ptrAnterior->ptrSigArista = ptrNuevo;
    }
}

TNodoArista *ExisteArista(TNodoVertice *ptrNodoVertice1, 
        TNodoGrafo Vertice2) {
    if (!ExistenAristas(ptrNodoVertice1))
        return NULL;
    TNodoArista *ptrListaAristas = ptrNodoVertice1->ptrListaArista;
    while (ptrListaAristas) {
        if (ptrListaAristas->ValorNodo == Vertice2)
            return ptrListaAristas;
        ptrListaAristas = ptrListaAristas->ptrSigArista;
    }
    return NULL;
}

int ExistenAristas(TNodoVertice *ptrListaVertices) {
    if (ptrListaVertices == NULL)
        return 0;
    if (ptrListaVertices->ptrListaArista == NULL)
        return 0;
    return 1;
}

void ImprimeGrafo(TNodoVertice *ptrListaVertices) {
    while (ptrListaVertices) {
        printf("%c: ", ptrListaVertices->ValorNodo);
        if (ExistenAristas(ptrListaVertices))
            ImprimeAristas(ptrListaVertices->ptrListaArista);
        printf("\n");
        ptrListaVertices = ptrListaVertices->ptrSigVertice;
    }
}

void ImprimeAristas(TNodoArista *ptrListaArista) {
    int imprime_coma = 0;
    while (ptrListaArista) {
        if (imprime_coma)
            printf(", ");
        else
            imprime_coma = 1;

        printf("%c(%lf)", ptrListaArista->ValorNodo, ptrListaArista->Peso);
        ptrListaArista = ptrListaArista->ptrSigArista;
    }
}