/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 15 de octubre de 2022, 9:34
 */

#include <stdio.h>
#include <stdlib.h>
#define DIAS 5
#include "lse.h"

int agrupar(int hora, int sucursal, int dia){
    //suponiendo que las sucursales sean < a 100
    //y los días < 10 (enrealidad son 5)
    //ponemos a la hora mas signifiticativa, porque al
    //insertar es lo que queremos que se ordene (por hora),
    //luego si la hora coincide, lo que quiere que se ordene es por día
    //y al final la sucursal que no importa en el ordenamiento
    //dia: 0=LUNES, 1=MARTES, ... 4=VIERNES
    return hora*10000 + dia*100 + sucursal;
}

void ObtenerHora_Sucursal_Dia(int clave, int*hora, int *dia, int*sucursal){
    *hora = clave/10000;;
    *dia = (clave%10000) / 10;
    *sucursal = clave%100;
}

void InsertarAListaOrdenada(Nodo *c1, Nodo*c2, Lista* c3, Elemento ele){
    Nodo *ultimo;
    if (c1->elemento < c2->elemento){
        c3->cabeza = ultimo = c1;
        c1 = c1->sig;
        c3->cabeza->sig = NULL;
    }
    else{
        c3->cabeza = ultimo = c2;
        c2 = c2->sig;
        c3->cabeza->sig = NULL;
    }
    
    while (c1 && c2){
        if (c1->elemento < c2->elemento){
            ultimo->sig = c1;
            ultimo = c1;
            c1 = c1->sig;
            ultimo->sig = NULL;
        }
        else{
            ultimo->sig = c2;
            ultimo = c2;
            c2 = c2->sig;
            ultimo->sig = NULL;
        }
    }
}

Lista obtenerListaDomingo(Lista*lista){
    Lista aux;
    construir(&aux);
    
    //Este primer for no cuenta para la complejidad, ya que
    //DIAS es un constante que siemrpe vale 5
    for (int i=0; i<DIAS; i++){
        while (lista[i].cabeza){
            Elemento ele = retorna_cabeza(lista[i]);
            elimina_cabeza(&lista[i]);
            insertar_orden(&aux, ele);
        }
    }
    return aux;
}

void imprimirDia(int dia){
    if (dia==0) printf("(Lunes)");
    else if (dia==1) printf("Martes");
    else if (dia==2) printf("Miercoles");
    else if (dia==3) printf("Jueves");
    else printf("Viernes");
}

void imprimirListaFinal(Lista listaDomingo){
    Nodo *rec = listaDomingo.cabeza;
    int hora, sucursal, dia;
    while (rec){
        ObtenerHora_Sucursal_Dia(rec->elemento, &hora, &dia, &sucursal);
        printf("%d(%d)", hora, sucursal);
        imprimirDia(dia);
        printf(" -> ");
        rec = rec->sig;
    }
}

int main(int argc, char** argv) {
    //5 dias
    FILE*arch = fopen("datos.txt","r");
    Lista lista[DIAS];
    
    int hora, sucursal, clave;
    
    //Almacenamiento de informacion en un arreglo de 5 listas para los días
    for (int i=0; i<DIAS; i++){
        construir(&lista[i]);
        
        while (1){
            fscanf(arch, "%d", &hora);
            if (feof(arch)) break;
            fscanf(arch, "%d", &sucursal);
            //i es el dia
            clave = agrupar(hora, sucursal, i);
            insertar_final(&lista[i], clave);
            if (fgetc(arch)=='\n') break;
        }
        
    }
    
    Lista listaDomingo = obtenerListaDomingo(lista);
    imprimirListaFinal(listaDomingo);
    return (EXIT_SUCCESS);
}

