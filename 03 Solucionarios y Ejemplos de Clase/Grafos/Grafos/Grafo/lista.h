#ifndef LISTA_H
#define LISTA_H
#include "grafo.h"

/*Definimos el tipo de dato que representará la Lista. */
struct SNodoLista{
    TNodoVertice *ValorLista;
    struct SNodoLista *ptrSig;
};

typedef struct SNodoLista TNodoLista;

/*prototipos*/
TNodoLista * InicializaLista();
TNodoLista *InsertaLista(TNodoLista *ptrLista, TNodoVertice* ValorLista);
int Pertenece(TNodoLista *ptrLista, TNodoVertice* ValorLista);
void ImprimeLista(TNodoLista *ptrLista);
void LiberaLista(TNodoLista *ptrLista);

#endif /* LISTA_H */

