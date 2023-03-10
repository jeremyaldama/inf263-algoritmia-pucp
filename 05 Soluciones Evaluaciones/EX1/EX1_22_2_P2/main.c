/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 15 de octubre de 2022, 16:00
 */

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(int argc, char** argv) {
    
    int frecuencia[]={1,2,1,4,5,6,4,5,2,2,1};
    //int frecuencia[]={1,2,5,6,5,5,5,4,3,3,2};
    int n = sizeof(frecuencia)/sizeof(int);
    
    Pila frecuencias_altas;
    construir_pila(&frecuencias_altas);
    
    double area_debajo, area_debajo_ant;
    int desafina = 0;
    
    for (int i=0; i<n-1; i++){
        if (frecuencia[i+1]>=frecuencia[i]){
            area_debajo = frecuencia[i]; //la base siempre es 1, así que no se necesita multiplicar
            if (desafina){
                if (frecuencia[i+2]-frecuencia[i+1]<-1)
                    area_debajo = area_debajo_ant;
                else area_debajo = frecuencia[i];
            }
        }
        else{
            area_debajo = frecuencia[i+1];
        }
        
        if (frecuencia[i+1]-frecuencia[i]>1){
            area_debajo = 0;
            desafina = 1;
            area_debajo_ant = frecuencia[i+1];
        }
        if (frecuencia[i+1]-frecuencia[i]<-1){
            desafina = 0;
        }
        push(&frecuencias_altas, area_debajo);
    }
    
    int max_frecuencia=-1, tiempo_total=0;
    ElementoPila frecuencia_actual;
    
    while (!es_pila_vacia(frecuencias_altas)){
        frecuencia_actual = pop(&frecuencias_altas);
        
        if (frecuencia_actual>max_frecuencia){
            max_frecuencia = frecuencia_actual;
            tiempo_total = 0; //se reinicia;
            tiempo_total++;//siempre inicia en 1, por la primera frecuencia que se cuenta su tiempo
        }
        if (frecuencia_actual==max_frecuencia) tiempo_total++;
    }

    printf("Frecuencia maxima = %d\n", max_frecuencia);
    printf("Duracion = %d\n", tiempo_total);
    return (EXIT_SUCCESS);
}

