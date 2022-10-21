/* 
 * File:   main.c
 * Author: Jeremy Aldama 20206228
 *
 * Created on 13 de octubre de 2022, 20:12
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcAux.h"

int main(int argc, char** argv) {
    Cola linea;
    crearCola(&linea);
    
    encolar(&linea,3);
    encolar(&linea,5);
    encolar(&linea,8);
    encolar(&linea,7);
    encolar(&linea,6);
    encolar(&linea,10);    
    encolar(&linea,20);    
    encolar(&linea,2);
    
    Pila pilaPrincipal, pilaAux1, pilaAux2;
    construirPila(&pilaPrincipal);
    construirPila(&pilaAux1);
    construirPila(&pilaAux2);
    
    apilarConPrioridad(&linea, &pilaPrincipal, &pilaAux1, &pilaAux2);
    printf("\n");
    mostrarPila(pilaPrincipal);
    return (EXIT_SUCCESS);
}

