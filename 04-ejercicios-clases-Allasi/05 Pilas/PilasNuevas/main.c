/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 20 de agosto de 2022, 22:33
 */

#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
#include "pilas.h"

void pasar(Pila*pila1, Pila*pila2){
    int valor, aux, n;
    while (!es_pila_vacia(*pila1)){
        valor = desapilar(pila1);
        
        n = 0;
        while (!es_pila_vacia(*pila1)){
            apilar(pila2, valor);
            valor = desapilar(pila1);
            n++;
        }
        while (!es_pila_vacia(*pila2) && n>0){
            aux = desapilar(pila2);
            apilar(pila1, aux);
            n--;
        }
        apilar(pila2, valor);
    }
    
}

void ordena(Pila *pila1){
    int n, max, valor;
    Pila pila2;
    
    n = pila1->contenido.longitud;
    
    construir_pila(&pila2);
    
    while (n>0){
        max = desapilar(pila1);
        n--;
        while (!es_pila_vacia(*pila1) && n>0){
            valor = desapilar(pila1);
            if (max<valor){
                apilar(&pila2, max);
                max = valor;
            }
            else apilar(&pila2, valor);
            n--;
        }
        apilar(pila1, max);
        n = 0;
        while (!es_pila_vacia(pila2)){
            n++;
            apilar(pila1,desapilar(&pila2));
        }
    }
}

int main(int argc, char** argv) {
    Pila pila, pila2;
    construir_pila(&pila);
    construir_pila(&pila2);


    apilar(&pila, 17);
    apilar(&pila, 10);
    apilar(&pila, 18);
    apilar(&pila, 11);


    imprime(pila.contenido);
    printf("\n");
    pasar(&pila, &pila2);
    imprime(pila2.contenido);
    
    ordena(&pila2);
    imprime(pila2.contenido);
    return (EXIT_SUCCESS);
}

