/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

typedef int TInfo;

typedef struct NodoCola{
    int elem;
    struct NodoCola* sig;
} TNodoCola;
typedef TNodoCola* TCola;

/*prototipos para trabajar la cola*/
void crea_cola(TCola *ptrCola);
int cola_vacia(TCola ptrCola);
void encolar(TCola *ptrCola, int valor);
void inserta_nodo(TCola *ptrCola, TInfo elem);
TNodoCola* ingresa(TCola *ptrCola);
int desencolar(TCola *ptrCola);

void imprimecola(TCola ptrcola)
{
	while(ptrcola!=NULL){
		printf("%d ",ptrcola->elem);
		ptrcola=ptrcola->sig;
	}
	
	
}

/*implementacion de las funciones para la cola*/
void crea_cola(TCola *ptrCola){
    *ptrCola = NULL;
}

int cola_vacia(TCola ptrCola){
    return ptrCola==NULL;
}

/*encolar, se inserta un elemento al final de la cola. Se representa como una 
 insercion al inicio.*/
void encolar(TCola *ptrCola, int valor){
    TNodoCola *ptrNuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    ptrNuevo->elem=valor;
    ptrNuevo->sig=*ptrCola;
    *ptrCola=ptrNuevo; 
}

/*saco la cabeza de la cola. Se representa como una eliminacion del nodo final de 
 la lista.*/
int desencolar(TCola *ptrCola)
{   TNodoCola *ptrRecorrido, *ptrUltimo;
    int valor;    
    if (!cola_vacia(*ptrCola))
    {
        ptrUltimo = NULL;
        ptrRecorrido = *ptrCola;
        while (ptrRecorrido->sig)
        {
            ptrUltimo = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->sig;
        }
        if (ptrUltimo == NULL)
            *ptrCola=NULL;
        else
            ptrUltimo->sig=NULL; 
            
        valor=ptrRecorrido->elem;
        free(ptrRecorrido);
        return(valor);
    }
    
}


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

void imprimir(Tpila ptrPila)
{
    printf("%d\n",ptrPila->valor);

}
void imprimepila(Tpila ptrPila)
{	Tpila  ptraux;
    
    if(ptrPila==NULL)
    	return;
    	
	ptraux=ptrPila;
	ptrPila=ptrPila->ptrSig;
	imprimepila(ptrPila);
	printf("%d ",ptraux->valor);

}

void ordenacola(TCola *ptrcola, int n)
{	int menor,i,j,aux;
	Tpila  ptraux;
	
	crear(&ptraux);
	j=n;	
	while(j>0)
	{	
		i=1;
		menor=desencolar(ptrcola);
		while(i<j)
		{	aux=desencolar(ptrcola);
			if(aux<menor)
			{
				encolar(ptrcola,menor);
				menor=aux;		
			}	
			else
				encolar(ptrcola,aux);
			i++;
		}
		push(&ptraux,menor);
		j--;
	}

	for(i=0;i<n;i++)
	{
		aux=pop(&ptraux);
		encolar(ptrcola,aux);
	}
	
	
}


int main() {
    TCola ptrCola;
	int n;
	
    crea_cola(&ptrCola);
    encolar(&ptrCola, 15);
    encolar(&ptrCola, 10);
    encolar(&ptrCola, 17);
    encolar(&ptrCola, 16);
    encolar(&ptrCola, 13);
    encolar(&ptrCola, 18);
    encolar(&ptrCola, 19);
    imprimecola(ptrCola);
    printf("\n");
	ordenacola(&ptrCola,7);
    printf("\n");
	imprimecola(ptrCola);
    
    return (0);
}
