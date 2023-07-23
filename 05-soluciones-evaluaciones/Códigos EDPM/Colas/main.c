/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 23:12
 */

#include <stdio.h>
#include <stdlib.h>

#include "cola.h"

void ordenacolarec(Cola *cola1,int n){
    ElementoCola menor,aux;
    int i=1;
    
    //Condicion base puede ser cola vacia o n=0
    if(n==0 || esColaVacia(*cola1)) return;
    
    
    menor = desencolar(cola1);
    
    while(i<n){
        aux = desencolar(cola1);
    
        if(aux<menor){
            encolar(cola1,menor);
            menor = aux;
        }else{
            encolar(cola1,aux);
        }
        i++;
    }
    
    ordenacolarec(cola1,n-1);
    encolar(cola1,menor);
    
}

int main(int argc, char** argv) {
    
    return (EXIT_SUCCESS);
}



