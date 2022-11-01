#include <stdio.h>
#include <math.h>
#include "abb.h"
#include "cola.h"

int GenerarClave(int codigo, int calidad){
    return codigo*100 + calidad;
}

int ObtenerCodigo(int clave){
    return clave/100;
}

int ObtenerCalidad(int clave){
    return clave%100;
}


void LeerDatos(ABB*arbol){
    FILE*arch = fopen("datos.txt","r");
    int codigo, calidad, clave;
    while (1){
        fscanf(arch, "%d %d", &codigo, &calidad);
        if (feof(arch)) break;
        clave = GenerarClave(codigo, calidad);
        //printf("%d  %d\n", codigo, calidad);
        InsertarRecursivo(arbol, clave);
        //printf("%d \n", (*arbol)->dato);
    }
    fclose(arch);
}

void RecorrerPorAmplitud(ABB tad){
    Cola cola;
    ConstruirCola(&cola);
    if (tad!=NULL){
        Encolar(&cola, tad);
        int clave, codigo, calidad;
        int inicio=1;
        while (cola.cabeza){
            ABB tad2 = Desencolar(&cola);
            clave = tad2->dato;
            if (!inicio) printf(", ");
            inicio = 0;
            codigo = ObtenerCodigo(clave);
            calidad = ObtenerCalidad(clave);
            printf("%d %d", codigo, calidad);
            
            if (tad2->hijo_izq){
                Encolar(&cola, tad2->hijo_izq);
            }
            if (tad2->hijo_der){
                Encolar(&cola, tad2->hijo_der);
            }
        }
    }
    printf("\n");
    DestruirCola(&cola);
}

int VerificarInsertarCalidad(ABB tad, int calidad_a_insertar){
    Cola cola;
    ConstruirCola(&cola);
    if (tad!=NULL){
        Encolar(&cola, tad);
        int clave, codigo, calidad;
        int cantidad = 0;
        while (cola.cabeza){
            ABB tad2 = Desencolar(&cola);
            clave = tad2->dato;
            codigo = ObtenerCodigo(clave);
            calidad = ObtenerCalidad(clave);
            if (calidad==calidad_a_insertar) cantidad++;
            if (calidad>calidad_a_insertar) break;

            if (tad2->hijo_izq){
                Encolar(&cola, tad2->hijo_izq);
            }
            if (tad2->hijo_der){
                Encolar(&cola, tad2->hijo_der);
            }
        }
        return cantidad!=(int)round(pow(2, calidad_a_insertar-1));
    }
    DestruirCola(&cola);
}

NodoArbol* BuscarNodo(ABB tad, int codigo_a_actualizar){
    if (tad==NULL) return NULL;
    int codigo = ObtenerCodigo(tad->dato);
    if (codigo==codigo_a_actualizar){
        return tad;
    }
    if (codigo_a_actualizar>codigo){
        return BuscarNodo(tad->hijo_der, codigo_a_actualizar);
    }
    else{
        return BuscarNodo(tad->hijo_izq, codigo_a_actualizar);
    }
}

int VerificarActualizarCodigo(ABB tad,
                              int codigo_a_actualizar, int codigo_nuevo){

    NodoArbol *p_nodo;
    p_nodo = BuscarNodo(tad, codigo_a_actualizar);
    int clave_hijo_izq = p_nodo->hijo_izq->dato;
    int clave_hijo_der = p_nodo->hijo_der->dato;
    int cod_izq = ObtenerCodigo(clave_hijo_izq);
    int cod_der = ObtenerCodigo(clave_hijo_der);
    return codigo_nuevo>=cod_izq && codigo_nuevo<cod_der? 1:0;
}

int main(){
    ABB arbol;
    ConstruirArbol(&arbol);
    LeerDatos(&arbol);
    RecorrerPorAmplitud(arbol);
    int calidad_a_insertar=0, es_posible_insertar;
    while (calidad_a_insertar!=-1){
        printf("Ingrese la calidad que desea insertar: ");
        scanf("%d", &calidad_a_insertar);
        es_posible_insertar = VerificarInsertarCalidad(arbol, calidad_a_insertar);
        printf("Es posible insertar? %d\n", es_posible_insertar);
    }
    
    int codigo_a_actualizar=0, codigo_nuevo, es_posible_actualizar;
    while (codigo_a_actualizar!=-1){
        printf("Ingrese el codigo que desea actualizar y el codigo nuevo: ");
        scanf("%d %d", &codigo_a_actualizar, &codigo_nuevo);
        es_posible_actualizar = VerificarActualizarCodigo(arbol,
                                codigo_a_actualizar, codigo_nuevo);
        printf("Es posible actualizar? %d\n", es_posible_actualizar);
    }
    return 0;
}