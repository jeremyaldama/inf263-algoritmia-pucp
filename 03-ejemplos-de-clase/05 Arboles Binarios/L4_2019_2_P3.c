#include <stdio.h>
#include <stdlib.h>

typedef int TInfo;

typedef struct Nodo {
	TInfo elem;
	struct Nodo *izq;
	struct Nodo *der;
} TNodo;

typedef TNodo *TArbol;

/* Funciones Principales */

void crearArbol(TArbol *Arbol) {
	(*Arbol) = NULL;
}

void insertarNodo(TArbol *Arbol, TInfo elem) {
	TNodo *ptrRecorrido, *ptrPadre;
	TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
	ptrNuevo->elem = elem;
	ptrNuevo->izq = ptrNuevo->der = NULL;
	if ((*Arbol) == NULL) (*Arbol) = ptrNuevo;
	else {
		ptrPadre = NULL;
		ptrRecorrido = (*Arbol);
		while (ptrRecorrido != NULL) {
			ptrPadre = ptrRecorrido;
			if (ptrRecorrido->elem > elem) ptrRecorrido = ptrRecorrido->izq;
			else ptrRecorrido = ptrRecorrido->der;
		}
		if (ptrPadre->elem > elem) ptrPadre->izq = ptrNuevo;
		else ptrPadre->der = ptrNuevo;
	}
}

// buscar : devuelve un Arbol BB con el nodo buscado como raiz;

TArbol buscar(TArbol Arbol, TInfo elem) {
	if (Arbol == NULL) return NULL;
	else {
		if(Arbol->elem == elem) return Arbol;
		else {
			if (Arbol->elem < elem) Arbol = Arbol->der;
            else Arbol = Arbol->izq;
            return(buscar(Arbol,elem));
		}
	}
}

void en_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		en_orden(Arbol->izq);
		printf("%d  ",Arbol->elem);
		en_orden(Arbol->der);		
	}
}

typedef TArbol TInfo2;

typedef struct NodoPila{
    TInfo2 elem;
    struct NodoPila *next;
}TNodoPila;

typedef TNodoPila* TPila ;

void crearPila(TPila *Pila) {
	(*Pila) = NULL;
}

void apilar(TPila *Pila, TInfo2 elem) {
	TNodoPila *nodoNuevo;
	nodoNuevo = (TNodoPila*)malloc(sizeof(TNodoPila));
	nodoNuevo->elem = elem;
	nodoNuevo->next = (*Pila);
	(*Pila) = nodoNuevo;
}

TInfo2 desapilar(TPila *Pila) {
	TNodoPila *Aux;
	TInfo2 valor;
	if (!esPilaVacia(Pila)) {
		Aux = (*Pila);
		valor = Aux->elem;
		(*Pila) = Aux->next;
		free(Aux);
	}
	return valor;
}

int esPilaVacia(TPila *Pila) {
	return (*Pila) == NULL;
}

TInfo2 cima(TPila *Pila) {
	TNodoPila *Aux;
	Aux = (*Pila);
	return Aux->elem;
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

void ordenarBST(TArbol Arbol1, TArbol Arbol2) {
	TNodo *ptrRec1, *ptrRec2;
	TPila miPila1, miPila2;
	crearPila(&miPila1);
	crearPila(&miPila2);
	ptrRec1 = Arbol1;
	ptrRec2 = Arbol2;
	if (Arbol1 == NULL) {
		en_orden(Arbol2);
		return;
	}
	if (Arbol2 == NULL) {
		en_orden(Arbol1);
		return;
	}
	while (ptrRec1 != NULL || ptrRec2 != NULL || !esPilaVacia(&miPila1) || !esPilaVacia(&miPila2)) {
		if (ptrRec1 != NULL || ptrRec2 != NULL) {
			if (ptrRec1 != NULL) {
				apilar(&miPila1,ptrRec1);
				ptrRec1 = ptrRec1->izq;
			}
			if (ptrRec2 != NULL) {
				apilar(&miPila2,ptrRec2);
				ptrRec2 = ptrRec2->izq;
			}			
		} else {
			if (esPilaVacia(&miPila1)) {
				while (!esPilaVacia(&miPila2)) {
					ptrRec2 = desapilar(&miPila2);
					ptrRec2->izq = NULL;
					en_orden(ptrRec2);
				}
				return;
			}
			if (esPilaVacia(&miPila2)) {
				while (!esPilaVacia(&miPila1)) {
					ptrRec1 = desapilar(&miPila1);
					ptrRec1->izq = NULL;
					en_orden(ptrRec1);
				}
				return;
			}
			ptrRec1 = desapilar(&miPila1);
			ptrRec2 = desapilar(&miPila2);
			if (ptrRec1->elem < ptrRec2->elem) {
				printf("%d   ",ptrRec1->elem);
				ptrRec1 = ptrRec1->der;
				apilar(&miPila2,ptrRec2);
				ptrRec2 = NULL;
			} else {
				printf("%d   ",ptrRec2->elem);
				ptrRec2 = ptrRec2->der;
				apilar(&miPila1,ptrRec1);
				ptrRec1 = NULL;
			}
		}
	}
}

int main () {
	TArbol Arbol1, Arbol2;
	crearArbol(&Arbol1);
	crearArbol(&Arbol2);
	insertarNodo(&Arbol1,2058);
	insertarNodo(&Arbol1,825);
	insertarNodo(&Arbol1,115);
	insertarNodo(&Arbol1,600);
	insertarNodo(&Arbol1,5207);
	insertarNodo(&Arbol1,100);
	insertarNodo(&Arbol1,556);
	insertarNodo(&Arbol1,9578);
	
	insertarNodo(&Arbol2,3341);
	insertarNodo(&Arbol2,1022);
	insertarNodo(&Arbol2,4587);
	insertarNodo(&Arbol2,4130);
	insertarNodo(&Arbol2,877);
	insertarNodo(&Arbol2,1988);
	insertarNodo(&Arbol2,1515);
	insertarNodo(&Arbol2,5033);
	insertarNodo(&Arbol2,7041);
	insertarNodo(&Arbol2,700);
	insertarNodo(&Arbol2,2255);
	
	printf("Productos Ordenados por codigo de producto:\n\n");
	ordenarBST(Arbol1,Arbol2);
	return 0;
}
