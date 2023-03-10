#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

int main(int argc, char** argv) {
    Lista lista;
    
    construirLista(&lista);
    insertarEnOrden(&lista, 15);
    insertarEnOrden(&lista, 16);
    insertarEnOrden(&lista, 18);
    insertarEnOrden(&lista, 10);
    insertarEnOrden(&lista, 5);
    
    imprime(lista);
    
    if (estaEnLista(lista, 5)) printf("Si esta");
    else printf("No esta");
    
    invierte(&lista);
    printf("\n");
    imprime(lista);
    invierteRecursivo(&lista);
    return (EXIT_SUCCESS);
}

