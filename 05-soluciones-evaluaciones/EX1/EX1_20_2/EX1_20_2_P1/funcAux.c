#include <stdio.h>
#include <stdlib.h>
#include "funcAux.h"

int ObtenerHash(int calidad, int codigo_producto, int cantidad_productos){
    //cantidad de productos < 100
    return (codigo_producto*1000 + calidad*100 + cantidad_productos);
}

char ObtenerCalidad(int hash){
    return (int)(hash%1000)/100 + 'A';
}

int ObtenerCodigo(int hash){
    return hash/1000;
}

int ObtenerCantidad(int hash){
    return hash%100;
}

Cola obtenerProductos(){
    FILE*arch = fopen("datos.txt","r");
    int cantidad_elementos;
    fscanf(arch, "%d", &cantidad_elementos);
    Cola aux;
    construirCola(&aux);
    
    int calidad, codigo_producto, cantidad_productos;


    for (int i=0; i<cantidad_elementos; i++){
        fscanf(arch, "%d %d %d", &calidad, &codigo_producto,
                                 &cantidad_productos);
        encolar(&aux, ObtenerHash(calidad, codigo_producto,
                cantidad_productos));
    }

    fclose(arch);
    return aux;
}

Cola generarNuevaCola(Cola*productos){
    Cola nueva_cola;
    construirCola(&nueva_cola);
    
    Pila pila_aux;
    construir_pila(&pila_aux);
    
    while (productos->cabeza){
        ElementoCola ele = desencolar(productos);
        int codigo = ObtenerCodigo(ele);
        char calidad = ObtenerCalidad(ele);
        if (calidad!='C')
            insertar_orden(&nueva_cola, ele);
    }
    mostrarCola(nueva_cola);
    return nueva_cola;
}

void insertar_orden(Cola *tad,ElementoCola dato){
    NodoCola *nuevo,*ptr,*aux=NULL;
    
    nuevo = crearNuevoNodoCola(dato);
    
    ptr = tad->cabeza;
    
    while(1){
        if(ptr==NULL || dato < ptr->elemento  ){
            break;
        }
        aux = ptr;
        ptr = ptr->sig;
    }
    if(aux==NULL){
        nuevo->sig = tad->cabeza;
        tad->cabeza = nuevo;
    }
    else{
        aux->sig = nuevo;
        nuevo->sig = ptr;
    }
    tad->longitud ++;
    
}