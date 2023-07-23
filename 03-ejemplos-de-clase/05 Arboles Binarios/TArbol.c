
#include <stdio.h>
#include <stdlib.h>

/*informacion que se almacenara en el nodo*/
typedef int TInfo;

/*se define el  tipo de dato TNodo que representa a una estructura autoreferenciada*/
typedef struct Nodo {
    TInfo elem;
    struct Nodo* izq;
    struct Nodo* der;
} TNodo;

/*se define el tipo de dato para gestionar la lista enlazada*/
typedef TNodo* TArbol;


typedef struct NodoPila{
    int valor;
    struct NodoPila *ptrSig; /*estructura auto-referenciada*/
}TNodoPila;

typedef TNodoPila* Tpila ;

void crea_arbol(TArbol *ptrArbol);
void inserta_nodo(TArbol *ptrArbol, TInfo elem);
void en_orden(TArbol ptrArbol);
void pre_orden(TArbol ptrArbol);
void pos_orden(TArbol ptrArbol);
TArbol busca(TArbol ptrArbol,int valor);
int contar(TArbol ptrArbol);


/* al inicio la pila se inicializa con nulo, lo que indica que esta¡ vacia*/
void crear(Tpila *ptrpila) {
    *ptrpila=NULL;
}

/*Se implementara¡ usando una lista simplemente enlazada. push insertara¡ siempre
 un nodo al inicio.*/
void push(Tpila *Pila, int valor) {
    TNodoPila *ptrNuevo;
    
    ptrNuevo = (TNodoPila *) malloc(sizeof (TNodoPila));
    ptrNuevo->valor = valor;
    ptrNuevo->ptrSig = *Pila;
    *Pila = ptrNuevo;
    
}

int pila_vacia(Tpila *ptrPila){
    return *ptrPila==NULL;
}


int top(Tpila *ptrPila)
{   TNodoPila *ptrrec;
    
    ptrrec=*ptrPila;
    if(pila_vacia(ptrPila))
        return(0);
    else
        return(ptrrec->valor);

}

/*Dado que se ha realizado una insercion al inicio, para que la estructura se
 comporte como pila, se debe sacar los dados a partir del inicio de la lista.*/

int pop(Tpila *Pila) {    
    TNodoPila *ptrEliminar;
    int valor;
    
    if (!pila_vacia(Pila)) { 
        ptrEliminar=*Pila;
        valor = ptrEliminar->valor; 
        *Pila = ptrEliminar->ptrSig; 
        free(ptrEliminar);
    }
    return valor;
}

/*Libera toda la memoria reservada para la lista utilizada en la pila.*/
void finalizar(Tpila ptrPila){
    TNodoPila *ptrEliminar;
    
    ptrEliminar = ptrPila;
    
    while (ptrEliminar != NULL){
        
        ptrPila = ptrEliminar->ptrSig;
        free(ptrEliminar);
        ptrEliminar = ptrPila;
    }
}

void posOrdenIterativa(TArbol ptr_arbol)
{   TArbol ptrrec;
    Tpila stack;
    int ultimo=0,alto ;
    
    ptrrec=ptr_arbol;
    if (ptr_arbol == NULL) 
        return; 
      
    crear(&stack); 
    do
    { 
        while (ptrrec) 
        { 
            push(&stack,ptrrec->elem);
            ptrrec=ptrrec->izq;
        }
        alto=top(&stack);
        ptrrec=busca(ptr_arbol,alto);
        
        if (ptrrec->der && ultimo!=(ptrrec->der)->elem )
        {
            ptrrec=ptrrec->der;
        }    
        else
        {
            ultimo=pop(&stack);
            ptrrec=NULL;
            printf("%3d",ultimo);
        }
    } while (!pila_vacia(&stack)); 
} 


int main() {
    TArbol ptrArbol;
	int n;
    crea_arbol(&ptrArbol);
    inserta_nodo(&ptrArbol, 10);
    inserta_nodo(&ptrArbol, 8);
    inserta_nodo(&ptrArbol, 15);
    inserta_nodo(&ptrArbol, 20);
    inserta_nodo(&ptrArbol, 9);
    inserta_nodo(&ptrArbol, 6);
    inserta_nodo(&ptrArbol, 4);
    
    printf("\nCuenta: %d\n",contar(ptrArbol));
	
	printf("\nEn orden:\n");
    en_orden(ptrArbol);
    printf("\nPre Orden:\n");
    pre_orden(ptrArbol);
    printf("\nPost Orden:\n");
    pos_orden(ptrArbol);
    printf("\nPost Iterativa:\n");
    posOrdenIterativa(ptrArbol);
    
    if(busca(ptrArbol,4))printf("\nEncontro");
    else
    	printf("\nNo encontro");
    
    return (0);
}

void crea_arbol(TArbol *ptrArbol) {
    *ptrArbol = NULL;
}

/*Implementacion iterariva de la insercion de un nodo en un 
 arbol binario de busqueda (ABB)*/
void inserta_nodo(TArbol *ptrArbol, TInfo elem) {
    /*ptrPadre apuntara al padre de la hoja que estoy insertando. Para llegar
     a esto ptrReccorido lo usaremos como estructura auxiliar, al final ptrRecorrido
     se hace NULL. Todo esto solo vale en el caso que el arbol no este vacio.*/
    TNodo *ptrRecorrido, *ptrPadre;

    /*se esta creando una hoja con el valor del elemento informado en el parametro*/
    TNodo *ptrNuevo = (TNodo*) malloc(sizeof (TNodo));
    ptrNuevo->elem = elem;
    ptrNuevo->izq = ptrNuevo->der = NULL;

    if (*ptrArbol == NULL) {
        /*si el arbol esta vacio, la nueva hoja sera la raiz del arbol*/
        *ptrArbol = ptrNuevo;
    } else {
        ptrPadre = NULL;
        ptrRecorrido = *ptrArbol;

        while (ptrRecorrido != NULL) {
            ptrPadre = ptrRecorrido;
            if (ptrRecorrido->elem > elem)
                ptrRecorrido = ptrRecorrido->izq;
            else
                ptrRecorrido = ptrRecorrido->der;
        }

        if (ptrPadre->elem > elem)
            ptrPadre->izq = ptrNuevo;
        else
            ptrPadre->der = ptrNuevo;
    }
}

TArbol busca(TArbol ptrArbol,int valor)
{
    if (ptrArbol==NULL)
        return NULL;
    else
    {   if(ptrArbol->elem==valor)
            return ptrArbol;
        else
        {
            if(ptrArbol->elem<valor)
                ptrArbol=ptrArbol->der;
            else
                ptrArbol=ptrArbol->izq;
            return(busca(ptrArbol,valor));
        }
    }
}

void en_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        en_orden(ptrArbol->izq);
        printf("%3d", ptrArbol->elem);
        en_orden(ptrArbol->der);
    }
}

void pre_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        printf("%3d", ptrArbol->elem);
        pre_orden(ptrArbol->izq);
        pre_orden(ptrArbol->der);
    }
}

void pos_orden(TArbol ptrArbol) {
    if (ptrArbol) {
        pos_orden(ptrArbol->izq);
        pos_orden(ptrArbol->der);
        printf("%3d", ptrArbol->elem);
    }
}

int contar(TArbol ptrArbol) {
	int cont=0;
    if (ptrArbol) {
        cont=contar(ptrArbol->izq)+contar(ptrArbol->der)+1;
    }
    return cont;
}








