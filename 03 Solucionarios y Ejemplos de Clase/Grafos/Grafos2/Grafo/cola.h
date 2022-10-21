#ifndef COLA_H
#define COLA_H
#include "grafo.h"

/*Definimos el tipo de dato que representará la Cola. */
struct SNodoCola {
    TNodoVertice *ValorCola;
    struct SNodoCola *ptrSig;
};

typedef struct SNodoCola TNodoCola;

/*prototipos*/
TNodoCola * InicializaCola();
int ColaVacia(TNodoCola *ptrCola);
TNodoCola * PideTurno(TNodoCola *ptrCola, TNodoVertice* ValorCola);
TNodoCola *Avanze(TNodoCola *ptrCola, TNodoVertice** ValorCola);
void LiberaCola(TNodoCola *ptrCola);

#endif /* COLA_H */

