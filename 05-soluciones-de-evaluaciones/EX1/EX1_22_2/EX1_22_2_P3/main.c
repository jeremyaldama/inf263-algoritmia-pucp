#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "lse.h"
#define MENOR_NUM_NATU 2

void eliminarYEncolarMultiplos(int numero,int max, Nodo *rec, Lista*lista, Cola *colaPares){
    if (rec==NULL){
        return;
    }
    
    if (rec->elemento%numero==0){
        encolar(colaPares, rec->elemento);
        Elimina_nodo(lista, rec->elemento);
        rec = lista->cabeza;
    }
    eliminarYEncolarMultiplos(numero, max, rec->sig, lista, colaPares);
}

void algoritmo(int n, Nodo *rec, Lista* lista_numeros){
    if (rec==NULL){
        return;
    }
    
    Cola colaPares;
    construirCola(&colaPares);
    eliminarYEncolarMultiplos(rec->elemento, n, rec->sig,
                              lista_numeros, &colaPares);
    
    printf("Numero procesado: %d",rec->elemento);
    if (!esColaVacia(colaPares)){
        printf("\nNumeros Tachados para el %d: ", rec->elemento);
        rec = rec->sig;
        elimina_cabeza(lista_numeros);
        mostrarCola(colaPares);
        printf("\n");
        algoritmo(n, rec,lista_numeros);
    }
    else{
        printf(", no tiene numeros tachados.\n\n");
        algoritmo(n, rec->sig, lista_numeros);
    }
}

Lista obtenerListaNumerosNaturales(int numero_maximo){
    Lista aux;
    construir(&aux);
    for (int i=MENOR_NUM_NATU; i<=numero_maximo; i++){
        insertar_final(&aux, i);
    }
    return aux;
}

int main() {
    int n;
    printf("Ingrese el numero n maximo: ");
    scanf("%d", &n);
    
    Lista lista_numeros = obtenerListaNumerosNaturales(n);
    imprimir(lista_numeros);
    printf("\n");
    
    algoritmo(n, lista_numeros.cabeza, &lista_numeros);
    
    return 0;
}