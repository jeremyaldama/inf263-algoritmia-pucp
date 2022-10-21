#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef int TInfo;

typedef struct Nodo {
	TInfo cod;
	TInfo lote;
	TInfo cant;
	struct Nodo *izq;
	struct Nodo *der;
} TNodo;

typedef TNodo *TArbol;

void crearArbol(TArbol *Arbol) {
	(*Arbol) = NULL;
}

void insertarRec(TArbol *Arbol, TInfo cod, TInfo lote, TInfo cant) {	
	if ((*Arbol) == NULL) {
		TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
		ptrNuevo->cod = cod;
		ptrNuevo->lote = lote;
		ptrNuevo->cant = cant;
		ptrNuevo->izq = ptrNuevo->der = NULL;
		(*Arbol) = ptrNuevo;
	} else {
		if ((*Arbol)->lote > lote) insertarRec(&((*Arbol)->izq),cod,lote,cant);
		else insertarRec(&((*Arbol)->der),cod,lote,cant);
	}
}

TArbol buscaMenor(TArbol Arbol){
    if(Arbol == NULL) return NULL;
    else {
        if(Arbol->izq != NULL) return(buscaMenor(Arbol->izq));
        else return(Arbol);
    }     
}

void imp2D(TArbol Arbol, int space) {
	if (Arbol == NULL) return;
	int i;
	space += COUNT;
	imp2D(Arbol->der,space);
	printf("\n");
	for(i = COUNT; i < space; i++) printf(" ");
	printf("%d-%d-%d\n",Arbol->cod,Arbol->lote,Arbol->cant);
	imp2D(Arbol->izq,space);
}

void imprimir2D(TArbol Arbol) {
	imp2D(Arbol,0);
}

TArbol borraNodo(TArbol Arbol, TInfo lote) {
	if (Arbol == NULL) return Arbol;
	if (lote < Arbol->lote) Arbol->izq = borraNodo(Arbol->izq,lote);
	else {
		if (lote > Arbol->lote) Arbol->der = borraNodo(Arbol->der,lote);
		else {
			if (Arbol->izq == NULL) {
				TArbol temp = Arbol->der;
				free(Arbol);
				return temp;
			} else if (Arbol->der == NULL) {
				TArbol temp = Arbol->izq;
				free(Arbol);
				return temp;
			}
			TArbol temp = buscaMenor(Arbol->der);
			Arbol->lote = temp->lote;
			Arbol->der = borraNodo(Arbol->der,temp->lote);
		}
	}
	return Arbol;
}

void despachar(TArbol *Arbol, TInfo cant) {
	int falta, lote;
	TArbol ptrAux;
	if(cant == 0) return;
	ptrAux = (*Arbol);
	ptrAux = buscaMenor(ptrAux);
	if (ptrAux->cant <= cant) {
		falta = cant - ptrAux->cant;
		lote = ptrAux->lote;
		(*Arbol) = borraNodo(*Arbol,lote);
		despachar(Arbol,falta);
		
	} else ptrAux->cant = ptrAux->cant - cant;
}

int main () {
	TArbol Almacen;
	crearArbol(&Almacen);
	FILE *arch = fopen("data.txt","r");
	int cod, lote, cant;
	while (1) {
		fscanf(arch,"%d %d %d",&cod,&lote,&cant);
		if(feof(arch)) break;
		insertarRec(&Almacen,cod,lote,cant);
	}
	imprimir2D(Almacen);
	//despachar(&Almacen,65);
	//imprimir2D(Almacen);
	return 0;
}
