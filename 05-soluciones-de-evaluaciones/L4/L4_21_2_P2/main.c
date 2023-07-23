#include <stdio.h>
#include "abb.h"

int ObtenerClave(char letra, int precio){
    return precio*100 + (int)letra;
}

char ObtenerNombre(int clave){
    return (char)(clave%100);
}

int ObtenerPrecio(int clave){
    return clave/100;
}

void LeerDatos(ABB* arbol){
    FILE*arch = fopen("datos.txt","r");

    char letra;
    int precio, clave;
    while (1){
        fscanf(arch, "%c %d", &letra, &precio);
        if (feof(arch)) break;
        fscanf(arch, "\n");
        clave = ObtenerClave(letra, precio);
        InsertarRecursivo(arbol, clave);
    }
    fclose(arch);
}

void InOrden(ABB tad){
    if (tad){
        InOrden(tad->hijo_izq);
        char letra = ObtenerNombre(tad->dato);
        int precio = ObtenerPrecio(tad->dato);
        printf("(%c - %d), ", letra, precio);
        //printf("%d ", tad->dato);
        InOrden(tad->hijo_der);
    }
}
void PreOrden(ABB tad){
    if (tad){
        /*char letra = ObtenerNombre(tad->dato);
        int precio = ObtenerPrecio(tad->dato);
        printf("(%c - %d), ", letra, precio);*/
        printf("%d ", tad->dato);
        PreOrden(tad->hijo_izq);
        PreOrden(tad->hijo_der);
    }
}


void mostrarPreciosFiltradorPreOrden(ABB arbol, int 
                                     precio_filtro){
    if (arbol){
        int precio = ObtenerPrecio(arbol->dato);
        if (precio<=precio_filtro){
            char letra = ObtenerNombre(arbol->dato);
            printf("(%c - %d), ", letra, precio);
        }
        mostrarPreciosFiltradorPreOrden(arbol->hijo_izq, precio_filtro);
        mostrarPreciosFiltradorPreOrden(arbol->hijo_der, precio_filtro);
    }
}

int main(){
    ABB arbol;
    ConstruirArbol(&arbol);
    //LeerDatos(&arbol);

    /*InsertarRecursivoAVL(&arbol, 220);
    InsertarRecursivoAVL(&arbol, 210);
    InsertarRecursivoAVL(&arbol, 200);*/

    InsertarRecursivoAVL(&arbol, 190);
    InsertarRecursivoAVL(&arbol, 180);
    InsertarRecursivoAVL(&arbol, 150);
    InsertarRecursivo(&arbol, 210);
    InsertarRecursivo(&arbol, 100);
    InsertarRecursivo(&arbol, 140);
    InsertarRecursivo(&arbol, 20);
    InsertarRecursivo(&arbol, 0);
    InsertarRecursivo(&arbol, 30);
    InsertarRecursivo(&arbol, 120);
    InsertarRecursivo(&arbol, 145);
    InsertarRecursivo(&arbol, 155);
    InsertarRecursivo(&arbol, 185);

    PreOrden(arbol);
    printf("altura: %d\n", arbol->altura);

    BalancearArbol(&arbol);
    PreOrden(arbol);

    int precio_filtro;
    printf("\nIngrese precio para filtrar menores/iguales: ");
    scanf("%d", &precio_filtro);
    mostrarPreciosFiltradorPreOrden(arbol, precio_filtro);
    return 0;
}