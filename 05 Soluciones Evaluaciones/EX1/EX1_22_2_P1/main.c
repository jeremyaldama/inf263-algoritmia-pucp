/* 
 * File:   main.c
 * Author: Jeremy Aldama 20206228
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
    *dia = (clave%10000) / 100;
    *sucursal = clave%100;
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

void InsertarAListaOrdenada(Nodo *cab1, Nodo*cab2, Lista* nuevaLst){
    Nodo *ultimo;
    if (cab1->elemento < cab2->elemento){
        nuevaLst->cabeza = ultimo = cab1;
        cab1 = cab1->sig;
        nuevaLst->cabeza->sig = NULL;
    }
    else{
        nuevaLst->cabeza = ultimo = cab2;
        cab2 = cab2->sig;
        nuevaLst->cabeza->sig = NULL;
    }
    
    while (cab1 || cab2){
        if (cab2==NULL && cab1){
            ultimo->sig = cab1;
            ultimo = cab1;
            cab1 = cab1->sig;
            ultimo->sig = NULL;
        }
        if (cab1==NULL && cab2){
            ultimo->sig = cab2;
            ultimo = cab2;
            cab2 = cab2->sig;
            ultimo->sig = NULL;
        }
        
        if (cab1 && cab2){
            if (cab1->elemento < cab2->elemento){
                ultimo->sig = cab1;
                ultimo = cab1;
                cab1 = cab1->sig;
                ultimo->sig = NULL;
            }
            else{
                ultimo->sig = cab2;
                ultimo = cab2;
                cab2 = cab2->sig;
                ultimo->sig = NULL;
            }
        }
    }     
}

//esto es lo mismo que MergeList, pero guardando cada 2 listas ordenadas en una nueva
Lista obtenerListaDomingo(Lista*lista){
    Lista aux,aux2,aux3,aux4,aux5;
    construir(&aux);
    construir(&aux2);
    construir(&aux3);
    construir(&aux4);
    
    //Este primer for no cuenta para la complejidad, ya que
    //DIAS es un constante que siemrpe vale 5
    
    InsertarAListaOrdenada(lista[0].cabeza, lista[1].cabeza, &aux);
    InsertarAListaOrdenada(aux.cabeza, lista[2].cabeza, &aux2);
    InsertarAListaOrdenada(aux2.cabeza, lista[3].cabeza, &aux3);
    InsertarAListaOrdenada(aux3.cabeza, lista[4].cabeza, &aux4);
    
    return aux4;
}

void MergeLists(Lista*lista1, Lista*lista2){
    Nodo *nodoLista1 = lista1->cabeza;
    Nodo *nodoLista2 = lista2->cabeza;
    Nodo *ultimo;
    if (nodoLista1->elemento < nodoLista2->elemento){
        lista1->cabeza = ultimo = nodoLista1;
        nodoLista1 = nodoLista1->sig;
        lista1->cabeza->sig = NULL;
    }
    else{
        lista1->cabeza = ultimo = nodoLista2;
        nodoLista2 = nodoLista2->sig;
        lista1->cabeza->sig = NULL;
    }
    
    while (nodoLista1 || nodoLista2){
        if (nodoLista1==NULL && nodoLista2){
            ultimo->sig = nodoLista2;
            ultimo = nodoLista2;
            nodoLista2 = nodoLista2->sig;
            ultimo->sig = NULL;
        }
        if (nodoLista1 && nodoLista2==NULL){
            ultimo->sig = nodoLista1;
            ultimo = nodoLista1;
            nodoLista1 = nodoLista1->sig;
            ultimo->sig = NULL;
        }
        
        if (nodoLista1 && nodoLista2){
            if (nodoLista1->elemento < nodoLista2->elemento){
                //la lista 1 aca se actualiza y se agrega el nuevo nodo sig
                ultimo->sig = nodoLista1;
                ultimo = nodoLista1;
                nodoLista1 = nodoLista1->sig;
                ultimo->sig = NULL;
            }
            else{
                ultimo->sig = nodoLista2;
                ultimo = nodoLista2;
                nodoLista2 = nodoLista2->sig;
                ultimo->sig = NULL;
            }
        }
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
    
    //Lista listaDomingo = obtenerListaDomingo(lista);
    
    MergeLists(&lista[0], &lista[1]);
    MergeLists(&lista[0], &lista[2]);
    MergeLists(&lista[0], &lista[3]);
    MergeLists(&lista[0], &lista[4]);
    
    imprimirListaFinal(lista[0]);
    return (EXIT_SUCCESS);
}

