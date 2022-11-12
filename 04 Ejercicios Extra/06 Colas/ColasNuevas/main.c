/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 21 de agosto de 2022, 20:05
 */

#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

void ordenaCola(Cola*cola){
    int n, menor, valor, i;
    n = cola->contenido.longitud;
    int j=n;
    while (n>0){
        menor = avanzar(cola);
        i=1;
        while (i<n){
            valor = avanzar(cola);
            if (valor<menor){
                pide_vez(cola, menor);
                menor = valor;
            }
            else pide_vez(cola, valor);
            i++;
        }
        for (i=n; i<j; i++){
            valor = avanzar(cola);
            pide_vez(cola, valor);
        }
        pide_vez(cola, menor);
        n--;
    }
}

int main(int argc, char** argv) {
    Cola cola;
    construir_cola(&cola);
    
    pide_vez(&cola, 20);
    pide_vez(&cola, 10);
    pide_vez(&cola, 12);
    pide_vez(&cola, 13);
    pide_vez(&cola, 18);
    pide_vez(&cola, 15);
    
    ordenaCola(&cola);
    imprime(cola.contenido);
    
    return (EXIT_SUCCESS);
}

