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
        /*char letra = ObtenerNombre(tad->dato);
        int precio = ObtenerPrecio(tad->dato);
        printf("(%c - %d), ", letra, precio);*/
        printf("%d ", tad->dato);
        InOrden(tad->hijo_der);
    }
}
void PreOrden(ABB tad){
    if (tad){
        printf("%d ", tad->dato);
        PreOrden(tad->hijo_izq);
        PreOrden(tad->hijo_der);
    }
}

int main(){
    ABB arbol;
    ConstruirArbol(&arbol);
    //LeerDatos(&arbol);

    /*InsertarRecursivoAVL(&arbol, 180);
    InsertarRecursivoAVL(&arbol, 190);
    InsertarRecursivoAVL(&arbol, 200);*/

    InsertarRecursivoAVL(&arbol, 190);
    InsertarRecursivoAVL(&arbol, 180);
    InsertarRecursivoAVL(&arbol, 150);
    InsertarRecursivoAVL(&arbol, 210);
    InsertarRecursivoAVL(&arbol, 100);
    InsertarRecursivoAVL(&arbol, 140);
    InsertarRecursivoAVL(&arbol, 20);
    InsertarRecursivoAVL(&arbol, 0);
    
    PreOrden(arbol);

    return 0;
}