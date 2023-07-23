/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 1:41
 */

#include <stdio.h>
#include <stdlib.h>

#include "cola.h"

int main(int argc, char** argv) {
    FILE*arch = fopen("cola.txt","r");
    Cola colaBanco;
    ConstruirCola(&colaBanco);
    
    ElementoCola aux;
    
    while (1){
        fscanf(arch, "(");
        if (feof(arch)) break;
        fscanf(arch,"'%c', %d) ", &aux.tipo, &aux.orden);
        printf("%c %d\n",aux.tipo, aux.orden);
        Encolar(&colaBanco, aux);
    }
    
    MostrarCola(colaBanco);
    return (EXIT_SUCCESS);
}

