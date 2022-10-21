#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo* ptrSig;
}TNodoLista;

typedef TNodoLista* TLista;

void crear_lista(TLista* L /*Direccion de memoria de la lista*/){
    *L = NULL; //Dereferencia 
}

void insertar_inicio(TLista* L, int x){
    //Crear un nuevo nodo
    TNodoLista* nuevo = (TNodoLista*)malloc(sizeof(TNodoLista));
    nuevo->dato = x;

    nuevo->ptrSig = *L;
    *L = nuevo;

}


void imprimir_lista(TLista L){ //Lista se envi por valor
    if(L == NULL)
        return;
    
    printf("%d ", L->dato);
    imprimir_lista(L->ptrSig);
}

//Cambiar la estructura de la lista
void liberar_memoria(TLista* L){ //Parametro por referencia
    while(*L != NULL){
        TLista aux = *L;
        *L = (*L)->ptrSig;
        free(aux);
    }
}

TNodoLista* invertir(TLista* L, TNodoLista* nodo){
    if(nodo == NULL){
        return NULL;
    }
    if(nodo->ptrSig == NULL){
        *L = nodo;
        return nodo;
    }

    TNodoLista* nodo1 = invertir(L, nodo->ptrSig);
    nodo1->ptrSig = nodo;
    nodo->ptrSig = NULL;
    return nodo;
}

int main(){

    TLista lista;
    crear_lista(&lista);

    insertar_inicio(&lista, 5);
    insertar_inicio(&lista, 3);
    insertar_inicio(&lista, 2);
    insertar_inicio(&lista, 4);

    imprimir_lista(lista);

    invertir(&lista, lista);
    printf("\n");
    imprimir_lista(lista);
    liberar_memoria(&lista);
}