#include <stdio.h>
#include <stdlib.h>

// 20180146

/* prio 1 = VIP 
   prio 2 = Cliente
   prio 3 = No Cliente*/

typedef struct NodoColaPrio {
	int data;
	int prio;
	struct NodoColaPrio *next;
} TNodoColaPrio;

typedef TNodoColaPrio *TColaPrio;

void crearCola(TColaPrio *ColaPrio) {
	(*ColaPrio) = NULL;
}

int esColaVacia(TColaPrio ColaPrio) {
	return ColaPrio == NULL;
}

int tamanioCola(TColaPrio ColaPrio) { 
	TColaPrio Aux;
	if (ColaPrio == NULL) return 0;
	Aux = ColaPrio;
	ColaPrio = ColaPrio->next;
	return (tamanioCola(ColaPrio)+1);
}

void encolar(TColaPrio *ColaPrio, int elem, int p) {
	TNodoColaPrio *nodoNuevo, *Aux, *Ult, *penUlt, *temp;
	nodoNuevo = (TNodoColaPrio *)malloc(sizeof(TNodoColaPrio));	
	Aux = (*ColaPrio);
	penUlt = Aux;
	if (esColaVacia(*ColaPrio)) { // encolamos normal
		nodoNuevo->data = elem;
		nodoNuevo->prio = p;
		nodoNuevo->next = (*ColaPrio);
		(*ColaPrio) = nodoNuevo;
	} else if (Aux->prio <= p) { // encolamos normal
		nodoNuevo->data = elem;
		nodoNuevo->prio = p;
		nodoNuevo->next = (*ColaPrio);
		(*ColaPrio) = nodoNuevo;
	} else {
		while (Aux && Aux->prio > p) { 
			Ult = penUlt;
			penUlt = Ult->next;
			Aux = penUlt->next;
		}
		temp = Aux;
		int cant = 0;
		while (temp && temp->prio < 2) {
			temp = temp->next;
			cant++;
		}
		if (p == 1 && cant >= 3) {
			nodoNuevo->data = elem;
			nodoNuevo->prio = p;
			nodoNuevo->next = penUlt;
			Ult->next = nodoNuevo;
		} else {
			nodoNuevo->data = elem;
			nodoNuevo->prio = p;
			nodoNuevo->next = Aux;
			penUlt->next = nodoNuevo;
		}							
	}	
}

void imprimirCola(TColaPrio ColaPrio) {
	int n = tamanioCola(ColaPrio);
	while (ColaPrio) {
		printf("(ID: %d , TIPO_CLIENTE: %d, TURNO: %02d)\n",ColaPrio->data,ColaPrio->prio,n);
		ColaPrio = ColaPrio->next;
		n--;
	}
}

int main () {
	int cant = 9;
	TColaPrio ColaBanco;
	crearCola(&ColaBanco);
	encolar(&ColaBanco,1004,1);
	encolar(&ColaBanco,8700,1);
	encolar(&ColaBanco,1897,1);	
	encolar(&ColaBanco,5426,2);
	encolar(&ColaBanco,5487,2);	
	encolar(&ColaBanco,6936,3);
	encolar(&ColaBanco,4355,1);
	encolar(&ColaBanco,6010,1);
	encolar(&ColaBanco,8010,1);
	encolar(&ColaBanco,9010,1);
	encolar(&ColaBanco,5496,3);
	encolar(&ColaBanco,9999,2);	
	imprimirCola(ColaBanco);
	return 0;
}
