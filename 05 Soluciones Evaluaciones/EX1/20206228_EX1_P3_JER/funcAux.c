#include <stdio.h>
#include <stdlib.h>
#include "funcAux.h"
#define MENOR_NUM_NATU 2

Lista obtenerListaNumerosNaturales(int numero_maximo){
    Lista aux;
    construir(&aux);
    for (int i=MENOR_NUM_NATU; i<=numero_maximo; i++){
        insertar_final(&aux, i);
    }
    return aux;
}
