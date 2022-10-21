#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

/* Estructura de un Arbol Binario de Busqueda */

typedef int TInfo;

typedef struct Nodo {
	TInfo elem;
	TInfo key;
	struct Nodo *izq;
	struct Nodo *der;
} TNodo;

typedef TNodo *TArbol;

void crearArbol(TArbol *Arbol) {
	(*Arbol) = NULL;
}

void insertarRec(TArbol *Arbol, TInfo elem, TInfo clave) {	
	if ((*Arbol) == NULL) {
		TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
		ptrNuevo->elem = elem;
		ptrNuevo->key = clave;
		ptrNuevo->izq = ptrNuevo->der = NULL;
		(*Arbol) = ptrNuevo;
	} else {
		if ((*Arbol)->elem > elem || ((*Arbol)->elem == elem && ((*Arbol)->key > clave))) 
			insertarRec(&((*Arbol)->izq),elem,clave);
		else insertarRec(&((*Arbol)->der),elem,clave);
	}
}

void imp2D(TArbol Arbol, int space) {
	if (Arbol == NULL) return;
	int i;
	space += COUNT;
	imp2D(Arbol->der,space);
	printf("\n");
	for(i = COUNT; i < space; i++) printf(" ");
	printf("[%06d||%04d]\n",Arbol->elem,Arbol->key);
	imp2D(Arbol->izq,space);
}

void imprimir2D(TArbol Arbol) {
	imp2D(Arbol,0);
}

void main () {
	TArbol Almacen;
	crearArbol(&Almacen);
	int fecha, num;
	printf("Ingrese fecha del producto y su numero secuencial\n");
	printf("(Ingrese -1 -1 para finalizar):\n");
	/*while (1) {		
		scanf("%d %d",&fecha,&num);
		if (fecha == -1 && num == -1) break;
		insertarRec(&Almacen,fecha,num);
	}*/
	insertarRec(&Almacen,201809,109);
	insertarRec(&Almacen,201710,1230);
	insertarRec(&Almacen,201902,109);
	insertarRec(&Almacen,201709,890);
	insertarRec(&Almacen,201710,1703);
	insertarRec(&Almacen,201709,124);
	imprimir2D(Almacen);
}
