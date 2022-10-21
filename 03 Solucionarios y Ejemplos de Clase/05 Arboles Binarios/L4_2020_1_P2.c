#include <stdio.h>
#include <stdlib.h>

// 20180146

typedef int TInfo;

typedef struct Nodo {
	TInfo lote;
	TInfo cant; // stock
	struct Nodo *izq;
	struct Nodo *der;
} TNodo;

typedef TNodo *TArbol;

void crearArbol(TArbol *Arbol) {
	(*Arbol) = NULL;
}

void insertarRec(TArbol *Arbol, TInfo lote, TInfo cant) {	
	if ((*Arbol) == NULL) {
		TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
		ptrNuevo->lote = lote;
		ptrNuevo->cant = cant;
		ptrNuevo->izq = ptrNuevo->der = NULL;
		(*Arbol) = ptrNuevo;
	} else {
		if ((*Arbol)->lote > lote) insertarRec(&((*Arbol)->izq),lote,cant);
		else insertarRec(&((*Arbol)->der),lote,cant);
	}
}

int numNodos(TArbol Arbol) {
	if (Arbol == NULL) return 0;
	return 1 + numNodos(Arbol->izq) + numNodos(Arbol->der);	
}

void en_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		en_orden(Arbol->izq);
		printf("  %d      %d\n",Arbol->lote,Arbol->cant);
		en_orden(Arbol->der);		
	}
}

void pre_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		printf("  %d      %d\n",Arbol->lote,Arbol->cant);
		pre_orden(Arbol->izq);
		pre_orden(Arbol->der);
	}
}

TArbol buscaMenor(TArbol Arbol){
    if(Arbol == NULL) return NULL;
    else {
        if(Arbol->izq != NULL) return(buscaMenor(Arbol->izq));
        else return(Arbol);
    }     
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
			Arbol->cant = temp->cant;
			Arbol->der = borraNodo(Arbol->der,temp->lote);
		}
	}
	return Arbol;
}

// verifica si un elemento esta presente en un arbol

int esta(TArbol Arbol, TInfo lote) {
	TNodo *aux;
	aux = Arbol;
	while (aux != NULL) {
		if (aux->lote == lote) 
			return 1;
		else if (lote < aux->lote) aux = aux->izq;
		else aux = aux->der;
	}
	return 0;
}

// funcion que modifica el stock en caso exista en el arbol (suma stock)

void modificar(TArbol *Arbol, TInfo lote, TInfo cant) {
	TNodo *aux;
	aux = *Arbol;
	while (aux != NULL) {
		if (aux->lote == lote) {
			aux->cant += cant;
			return;
		}
		else if (lote < aux->lote) aux = aux->izq;
		else aux = aux->der;
	}
}

// destino = arbol 1  y  emisor = arbol 2

void juntar(TArbol *Arbol1, TArbol *Arbol2) {
	TNodo *aux, *temp;
	aux = *Arbol2;
	// recorremos el emisor borrando el nodo en cada iteracion
	// y en caso el lote exista en el arbol destino actualizamos
	// el nodo del arbol destino en donde se encuentra dicho lote (stock)
	// y en caso no exista lo insertamos
	while (aux != NULL) {
		temp = buscaMenor(aux);
		if (esta(*Arbol1,temp->lote)) {
			modificar(Arbol1,temp->lote,temp->cant);
		} else {
			insertarRec(Arbol1,temp->lote,temp->cant);
		}		
		aux = borraNodo(aux,temp->lote);
	}
	*Arbol2 = NULL;
}


void juntarArboles(TArbol *Arbol1, TArbol *Arbol2) {
	// verificamos quien es el emisor y quien es el destino
	int a = numNodos(*Arbol1);
	int b = numNodos(*Arbol2);
	if (a > b) juntar(Arbol1,Arbol2);
	else juntar(Arbol2,Arbol1);
}

int main () {
	FILE *arch1, *arch2;
	arch1 = fopen("datos1.txt","r");
	arch2 = fopen("datos2.txt","r");
	TArbol Almacen1, Almacen2;
	crearArbol(&Almacen1);
	crearArbol(&Almacen2);
	int lote,cant;
	// insertamos datos en los arbolesbb
	while (1) {
		fscanf(arch1,"%d %d",&lote,&cant);
		if (feof(arch1)) break;
		insertarRec(&Almacen1,lote,cant);
	}
	fclose(arch1);
		while (1) {
		fscanf(arch2,"%d %d",&lote,&cant);
		if (feof(arch2)) break;
		insertarRec(&Almacen2,lote,cant);
	}
	fclose(arch2);
	// impresion en orden y pre orden
	printf("Almacen 1 (En orden y pre orden):\n\n");
	printf("\n num. lote    stock. disp\n");
	printf("==========================\n");
	en_orden(Almacen1);
	printf("\n");
	printf("\n num. lote    stock. disp\n");
	printf("==========================\n");
	pre_orden(Almacen1);
	printf("\n");
	printf("Almacen 2 (En orden y pre orden):\n\n");
	printf("\n num. lote    stock. disp\n");
	printf("==========================\n");
	en_orden(Almacen2);
	printf("\n");
	printf("\n num. lote    stock. disp\n");
	printf("==========================\n");
	pre_orden(Almacen2);
	// fusionamos los arboles
	juntarArboles(&Almacen1,&Almacen2);
	printf("\nAlmacen resultante:\n\n");
	printf("Almacen 1 (En orden y pre orden):\n\n");
	printf("\n num. lote    stock. disp\n");
	printf("==========================\n");
	en_orden(Almacen1);
	printf("\n");
	printf("\n num. lote    stock. disp\n");
	printf("==========================\n");
	pre_orden(Almacen1);
	return 0;
}
