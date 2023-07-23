#include <stdio.h>
#include <stdlib.h>

typedef int TInfo;

typedef struct Nodo{
    TInfo dato;
    struct Nodo* izq;
    struct Nodo* der;
}TNodo;

typedef struct Arbol{
    TNodo* raiz;
}TArbol;

void crear_arbol(TArbol *T){
    T->raiz = NULL;
}

void preorden(TNodo *N){

    if(N==NULL)
        return;

    printf("%d ", N->dato);
    preorden(N->izq);
    preorden(N->der);
}

void inorden(TNodo *N){
    if(N == NULL)
        return;

    inorden(N->izq);
    printf("%d ", N->dato);
    inorden(N->der);
}

void postorden(TNodo* N){
    if(N==NULL)
        return;

    postorden(N->izq);
    postorden(N->der);
    printf("%d ", N->dato);
}

void insertar(TArbol* T, TInfo x){
    TNodo* nuevo = (TNodo*)malloc(sizeof(TNodo));
    nuevo->dato = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    //Si el arbol esta vacio
    if(T->raiz == NULL){
        T->raiz = nuevo;
        return;
    }

    //Busqueda del padre de x
    TNodo* q = T->raiz;
    TNodo* p = NULL;

    while(q != NULL){
        p = q;
        if(x < q->dato)
            q = q->izq;
        else
            q = q->der;
    }

    //Insertar x en p
    if(x < p->dato)
        p->izq = nuevo;
    else
        p->der = nuevo;
}

void eliminar(TArbol* T, TInfo x){
    if(T->raiz == NULL)
        return;

    //Buscar el nodo a eliminar
    TNodo* q = T->raiz;
    TNodo* p = NULL;

    while(q!=NULL && q->dato != x){
        p = q;
        if(x < q->dato)
            q = q->izq;
        else if(x > q->dato)
            q = q->der;
    }

    if(q==NULL)
        return;

    //Primer caso: Nodo hoja
    if(q->izq == NULL && q->der == NULL){
        if(q == T->raiz){ // Nodo hoja es raiz
            free(q);
            T->raiz = NULL;
            return;
        }else{ // Nodo hoja no es la raiz
            if(q->dato < p->dato){
                p->izq = NULL;
            }else{
                p->der = NULL;
            }
            free(q);
            return;
        }
    }

    //Segundo caso: Nodo tiene 1 hijo por la izq
    if(q->izq != NULL && q->der == NULL){
        if(q == T->raiz){ //Raiz tiene 1 hijo pos la izq
            T->raiz = q->izq;
            free(q);
            return;
        }else{
            if(q->dato < p->dato){
                p->izq = q->izq;
            }else{
                p->der = q->izq;
            }
            free(q);
            return;
        }
    }
    //Segundo caso: Nodo tiene 1 hijo por la der
    if(q->izq == NULL && q->der != NULL){
        if(q == T->raiz){ //Raiz tiene 1 hijo por la der
            T->raiz = q->der;
            free(q);
            return;
        }else{
            if(q->dato < p->dato){
                p->izq = q->der;
            }else{
                p->der = q->der;
            }
            free(q);
            return;
        }
    }

    //Tercer caso: nodo tiene 2 hijos
    //Buscar clave de reemplazo
    TNodo* aux = q->izq;

    while(aux->der != NULL)
        aux = aux->der;

    TInfo k = aux->dato;
    eliminar(T, k);

    q->dato = k;

}

int contarNodos(TNodo* N){
    if(N==NULL)
        return 0;

    return 1 + contarNodos(N->izq) + contarNodos(N->der);
}

int max(int a,int b){
    return (a > b)? a : b;
}
int profudidad(TNodo* N){
    if(N==NULL)
        return 0;

    return 1 + max(profundidad(N->izq), produnfidad(N->der));
}

void finalizar(TNodo* N){
    if(N==NULL)
        return;

    finalizar(N->izq);
    finalizar(N->der);
    free(N);
}

void main(){
    TArbol T;
    crear_arbol(&T);

    insertar(&T, 12);
    insertar(&T, 7);
    insertar(&T, 14);
    insertar(&T, 10);
    insertar(&T, 5);
    insertar(&T, 6);

    preorden(T.raiz);
    printf("\n");

    eliminar(&T, 14);

    preorden(T.raiz);
    printf("\n");

    finalizar(T.raiz);
    T.raiz = NULL;
}
