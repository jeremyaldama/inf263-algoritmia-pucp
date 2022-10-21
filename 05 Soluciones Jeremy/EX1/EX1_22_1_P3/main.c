/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 17:24
 */

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void actualizarDuracion(NodoLista *cabeza, int tiempoEjec){
    cabeza->proceso.duracion -= tiempoEjec;
}

void ejecutarProceso(Lista*procesos, int tiempoEjec){
    actualizarDuracion(procesos->cabeza, tiempoEjec);
}

void ejecutarProcesos(Lista *procesos, int tiempoEjec){
    int otroProc;
    int cantidad = procesos->cantidad;
    while (cantidad>0){
        ejecutarProceso(procesos, tiempoEjec);
        ElementoLista elem = desencolar(procesos);
        printf("Se ejecuto proceso #%d\n", elem.numeroProceso);
        
        if (elem.duracion<=0){
            printf("Se completo proceso #%d\n", elem.numeroProceso);
            cantidad--;
        }
        else{
            InsertarAlFinal(procesos, elem);
        }
        
        printf("Desea insertar un nuevo proceso?: ");
        scanf("%d", &otroProc);
        if (otroProc){
            ElementoLista nuevoProceso;
            printf("Indicar duracion de proceso #%d: ", cantidad+1);
            scanf("%d", &nuevoProceso.duracion);
            nuevoProceso.numeroProceso = cantidad+1;
            InsertarAlInicio(procesos, nuevoProceso);
            cantidad++;
        }
    }
}

int main(int argc, char** argv) {
    /*
    # procesos iniciales = 3, T = 1 min
    Duraciones iniciales de procesos (en minutos, respectivamente) = 2, 3, 2
     * 
    Se ejecutó proceso #1
    Desea insertar un nuevo proceso? 1
    Indicar duración de proceso #4: 2
     *
    Se ejecutó proceso #4
    Desea insertar un nuevo proceso? 0
     *
    Se ejecutó proceso #2
    Desea insertar un nuevo proceso? 0
     *
    Se ejecutó proceso #3
    Desea insertar un nuevo proceso? 0
     * 
    Se ejecutó proceso #1
    Se completó proceso #1
     * 
    Desea insertar un nuevo proceso? 0
    Se ejecutó proceso #4
    Se completó proceso #4
     * 
    Desea insertar un nuevo proceso? 0
    Se ejecutó proceso #2
     * 
    Desea insertar un nuevo proceso? 0
    Se ejecutó proceso #3
    Se completó proceso #3
     * 
    Desea insertar un nuevo proceso? 0
    Se ejecutó proceso #2
    Se completó proceso #2
    Desea insertar un nuevo proceso? 0
     */
    int numProc, tiempoEjec;
    printf("# procesos iniciales y T: ");
    scanf("%d %d", &numProc, &tiempoEjec);
    printf("Duraciones iniciales de procesos = ");
    
    Lista procesos;
    ConstruirLista(&procesos);
    ElementoLista elemento;
    
    for (int i=numProc; i>0; i--){
        scanf("%d", &elemento.duracion);
        elemento.numeroProceso = i;
        InsertarAlInicio(&procesos, elemento);
    }
    
    ejecutarProcesos(&procesos, tiempoEjec);
    
    return (EXIT_SUCCESS);
}

