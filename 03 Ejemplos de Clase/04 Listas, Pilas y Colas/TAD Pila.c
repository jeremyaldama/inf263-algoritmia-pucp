#include <stdio.h>
#include <stdlib.h>

// 20180146

typedef struct NodoPila{
    int data;
    struct NodoPila *next;
}TNodoPila;

typedef TNodoPila* TPila ;

void crearPila(TPila *Pila) {
	(*Pila) = NULL;
}

void apilar(TPila *Pila, int elem) {
	TNodoPila *nodoNuevo;
	nodoNuevo = (TNodoPila*)malloc(sizeof(TNodoPila));
	nodoNuevo->data = elem;
	nodoNuevo->next = (*Pila);
	(*Pila) = nodoNuevo;
}

int desapilar(TPila *Pila) {
	TNodoPila *Aux;
	int valor;
	if (!esPilaVacia(Pila)) {
		Aux = (*Pila);
		valor = Aux->data;
		(*Pila) = Aux->next;
		free(Aux);
	}
	return valor;
}

int esPilaVacia(TPila *Pila) {
	return (*Pila) == NULL;
}

int cima(TPila *Pila) {
	TNodoPila *Aux;
	Aux = (*Pila);
	if (esPilaVacia(Pila)) return -1;
	else return Aux->data;
}

void imprimirPila(TPila Pila) {
	TPila Aux;
	if (Pila == NULL) return;
	Aux = Pila;
	Pila = Pila->next;
	imprimirPila(Pila);
	printf("%d\n",Aux->data);
}

void finalizarPila(TPila Pila) {
	TNodoPila *Aux;
	Aux = Pila;
	while (Aux) {
		Pila = Aux->next;
		free(Pila);
		Aux = Pila;
	}
}

void invertirPila(TPila *Pila, TPila *nuevaPila) {
	int valor;
	while(!esPilaVacia(Pila)) {		
		valor = desapilar(Pila);
		free(Pila);
		apilar(nuevaPila,valor);
	}
}

int tamanioPila(TPila Pila) { 
	TPila Aux;
	if (Pila == NULL) return 0;
	Aux = Pila;
	Pila = Pila->next;
	return (tamanioPila(Pila)+1);
}


