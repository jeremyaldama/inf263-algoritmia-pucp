#include <stdio.h>
#include <stdlib.h>

/*informacion que se almacenara en el nodo*/
typedef int TInfo;

/*se define el  tipo de dato TNodo que representa a una estructura autoreferenciada*/
typedef struct Nodo{
    int elem;
    struct Nodo* sig;
} TNodo;

/*se define el tipo de dato para gestionar la lista enlazada*/
typedef TNodo* TLista;

/*prototipos del TAD Lista*/
void crear_lista(TLista *ptrLista);
int esta_vacia(TLista ptrLista);
void insertar_inicio(TLista *ptrLista, TInfo elem);
void insertar_final(TLista *ptrLista, TInfo elem);
void imprimir(TLista ptrLista);
void finalizar_lista(TLista ptrLista);
int  esta_en_lista(TLista ptrLista, TInfo elem);
int tamano(TLista ptrLista);

int main() {
    TLista ptrLista,ptrpar,ptrimpar;
    
    crear_lista(&ptrLista);
    insertar_final(&ptrLista, 19);
    insertar_final(&ptrLista, 20);
    insertar_final(&ptrLista, 16);
    insertar_final(&ptrLista, 14);
    imprimir(ptrLista);
    printf("Tamano:%d\n",tamano(ptrLista));
    imprimir(ptrLista);
    finalizar_lista(ptrLista);
    return (EXIT_SUCCESS);
}

int tamano(TLista ptrLista)
{   TLista ptrrec;
    int cont=0;
    
    ptrrec=ptrLista;
    while(ptrrec)
    {
        ptrrec=ptrrec->sig;
        cont++;
    }
    
    return cont;
}

void crear_lista(TLista *ptrLista){
    *ptrLista = NULL;
}

int esta_vacia(TLista ptrLista){
    return ptrLista==NULL;
}

void insertar_inicio(TLista *ptrLista, TInfo elem){
    TNodo *ptrNuevo;
    ptrNuevo = (TNodo*)malloc(sizeof(TNodo));
    
    ptrNuevo->elem = elem;
    ptrNuevo->sig = *ptrLista;
    *ptrLista = ptrNuevo;
}

void insertar_final(TLista *ptrLista, TInfo elem){
    TNodo *ptrNuevo, *ptrRec, *ptrUltimo;
    ptrNuevo = (TNodo*)malloc(sizeof(TNodo));
    
    ptrNuevo->elem = elem;
    ptrNuevo->sig = NULL;
    ptrRec = *ptrLista;    
    ptrUltimo = NULL;
    while (ptrRec){
        ptrUltimo = ptrRec;
        ptrRec = ptrRec->sig;
    }
    
    if (ptrUltimo)
        ptrUltimo->sig=ptrNuevo;
    else
        *ptrLista = ptrNuevo;
}


void imprimir(TLista ptrLista){
    TNodo *ptrRec;
    ptrRec = ptrLista;
    
    while (ptrRec){
        printf("%d -> ", ptrRec->elem);
        ptrRec = ptrRec->sig;
    }
    printf("NULL\n");
}

void finalizar_lista(TLista ptrLista){
    TNodo *ptrRec, *ptrLiberar;
    ptrRec = ptrLista;
    
    while (ptrRec){
        ptrLiberar = ptrRec;
        ptrRec = ptrRec->sig;
        free(ptrLiberar);
    }
}

int esta_en_lista(TLista ptrLista, TInfo elem){
    TNodo *ptrRec;
    ptrRec = ptrLista;
    
    while (ptrRec){
        if (ptrRec->elem==elem)
            return 1;
        ptrRec = ptrRec->sig;
    }
    return 0;
}
