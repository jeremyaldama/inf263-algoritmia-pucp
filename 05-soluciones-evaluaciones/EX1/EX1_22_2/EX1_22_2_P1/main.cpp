#include <iostream>
#include <fstream>
#include <iomanip>
#include "lse.h"
#define DIAS 5

using namespace std;

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

int main() {
    ifstream arch("datos.txt", ios::in);

    Lista lista[DIAS];
    
    int hora, sucursal, clave;
    
    for (int i=0; i<DIAS; i++){
        construir(&lista[i]);
        // leer linea hasta el salto de linea
        while (1){
            arch >> hora >> sucursal;
            clave = agrupar(hora, sucursal, i);
            insertar_final(&lista[i], clave);
            if (arch.peek()=='\n') break;
        }
    }
    
    //imprimir
    for (int i=0; i<DIAS; i++){
        cout<<"Lista "<<i<<": ";
        imprimir(lista[i]);
    }
    MergeLists(&lista[0], &lista[1]);
    MergeLists(&lista[0], &lista[2]);
    MergeLists(&lista[0], &lista[3]);
    MergeLists(&lista[0], &lista[4]);
    
    imprimirListaFinal(lista[0]);

    return 0;
}