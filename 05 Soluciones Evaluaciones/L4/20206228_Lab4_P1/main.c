/* 
 * File:   main.c
 * Author: Jeremy Aldama 20206228
 *
 * Created on 5 de noviembre de 2022, 15:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ABC.h"

int hash(int bin, int dato){
    //suponiendo que el elemento maximo sea hasta 999
    return bin*1000 + dato;
}

int ObtenerBin(int hash){
    return hash/1000;
}

int ObtenerElemento(int hash){
    return hash%1000;
}

int numeroNodos(ArbolBinario tad){
    if (esArbolVacio(tad))
        return 0;
    else
        return 1 + numeroNodos(tad->hizq) + numeroNodos(tad->hizq);
}

void InsertarEnArbolCromosoma(ABC *arbol, int dato_a_insertar, int cantidad_nodos_arbol){
    Nodo *p, *p_ant;
    
    p = *arbol;
    int num_nodos = numeroNodos(p);//sin contar el de mas arriba
    int cantidad_nodos_lado = cantidad_nodos_arbol/2;
    
    
    while (p!=NULL){
        p_ant = p;
        if (num_nodos<=cantidad_nodos_lado){
            p = p->hizq;
        }
        else p = p->hder;
        
        cantidad_nodos_lado = cantidad_nodos_lado/2;
        num_nodos = numeroNodos(p);
    }
    
    if (p_ant->hizq == NULL)
        plantar(&p_ant->hizq, NULL, dato_a_insertar, NULL);
    else if (p_ant->hder == NULL)
        plantar(&p_ant->hder, NULL, dato_a_insertar, NULL);
}

ABC GenerarArbolCromosoma(int*arreglo, int n){
   ABC arbol; //Arbol Binario Cromosoma
   construirArbol(&arbol);
   //el primero siempre es 0
   plantar(&arbol, NULL, 0, NULL);
   int cantidad_nodos, dato_a_insertar, bin;
   
   for (int i=0; i<n; i++){
       cantidad_nodos = (int)pow(2, i+1);
       for (int j=0; j<cantidad_nodos; j++){
           if (j%2==0) bin=0;
           else bin=1;
           
           dato_a_insertar = hash(bin , arreglo[i]);
           InsertarEnArbolCromosoma(&arbol, dato_a_insertar, (int)pow(2, i+2)-1);
       }
   }
   return arbol;
}

int CalcularCombinacionesQueCumplen(ABC arbol){
    
}

int main(int argc, char** argv) {
    int arreglo[] = {10, 50};
    int n = sizeof(arreglo)/sizeof(int);
    
    ABC arbol_cromo = GenerarArbolCromosoma(arreglo, n);
    //recorrerEnPostOrden(arbol_cromo);
    
    int combinaciones;
    combinaciones = CalcularCombinacionesQueCumplen(arbol_cromo);
    return (EXIT_SUCCESS);
}

