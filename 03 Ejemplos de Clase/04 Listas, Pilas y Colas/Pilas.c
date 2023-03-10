
/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 3 de noviembre de 2018, 05:47 PM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct NodoPila{
    int valor;
    struct NodoPila *ptrSig; /*estructura auto-referenciada*/
}TNodoPila;

typedef TNodoPila* Tpila ;

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

void top(Tpila *ptrPila)
{   TNodoPila *ptrrec;
    
    ptrrec=*ptrPila;
    if(pila_vacia(ptrPila))
        printf("Pila vacia\n");
    else
        printf("%d\n",ptrrec->valor);

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

void cambia(Tpila ptrPila,int n)
{
    ptrPila->valor=n;

}

void imprimepila(Tpila ptrpila)
{
	while(ptrpila!=NULL){
		printf("%d ",ptrpila->valor);
		ptrpila=ptrpila->ptrSig;
	}
	
	
}

void imprimepila2(Tpila ptrPila)
{	Tpila  ptraux;
    
    if(ptrPila==NULL)
    	return;
    	
	ptraux=ptrPila;
	ptrPila=ptrPila->ptrSig;
	imprimepila(ptrPila);
	printf("%d ",ptraux->valor);

}
int main() {
    Tpila ptrPila;

    crear(&ptrPila);
    top(&ptrPila);
    push(&ptrPila, 19);
    push(&ptrPila, 18);
    push(&ptrPila, 17);
    push(&ptrPila, 20);
	imprimepila(ptrPila);
	
    printf("\nDesapila:%d\n", pop(&ptrPila));
    printf("Desapila:%d\n", pop(&ptrPila));
    printf("Top:");
	top(&ptrPila);
	imprimepila(ptrPila);
    finalizar(ptrPila);
    
    return (0);
}
