#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

// 20180146

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

TArbol buscar(TArbol Arbol, TInfo cod) {
	if (Arbol == NULL) return NULL;
	else {
		if(Arbol->cod == cod) return Arbol;
		else {
			TArbol a1 = buscar(Arbol->izq,cod);
			if (a1 == NULL) return buscar(Arbol->der,cod);
			else return a1;
		}
	}
}

TArbol buscaM(TArbol Arbol){
    if(Arbol == NULL) return NULL;
    else {
        if(Arbol->izq != NULL) return(buscaM(Arbol->izq));
        else return(Arbol);
    }     
}

TArbol buscaMenor(TArbol Arbol, TInfo cod) {
	TNodo *ptrRec = buscar(Arbol,cod);
	if(ptrRec == NULL) return buscaM(Arbol);
	TNodo *ptrAux = ptrRec;
	if (buscar(ptrRec->izq,cod) == NULL) return ptrRec;
	int flag = 1;
    while(flag) {
    	ptrRec = buscar(ptrRec->izq,cod);
    	if (ptrRec->izq == NULL) flag = 0;
	}   
	return ptrRec;
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

TArbol borraNodo(TArbol Arbol, TInfo cod, TInfo lote) {
	if (Arbol == NULL) return Arbol;
	if (lote < Arbol->lote) Arbol->izq = borraNodo(Arbol->izq,cod,lote);
	else {
		if (lote > Arbol->lote) Arbol->der = borraNodo(Arbol->der,cod,lote);
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
			TArbol temp = buscaMenor(Arbol->der,cod);
			Arbol->lote = temp->lote;
			Arbol->cod = temp->cod;
			Arbol->cant = temp->cant;
			Arbol->der = borraNodo(Arbol->der,temp->cod,temp->lote);
		}
	}
	return Arbol;
}

void despachar(TArbol *Arbol, TInfo cod, TInfo cant) {
	int falta, lote;
	TArbol ptrAux;
	if(cant == 0) return;
	ptrAux = (*Arbol);
	ptrAux = buscaMenor(ptrAux,cod);
	if (ptrAux->cod != cod) {
		printf("\nNo existen suficientes productos para ser despachados ... Hacen falta %d\n",cant);
		return;
	}
	if (ptrAux->cant <= cant) {
		falta = cant - ptrAux->cant;
		lote = ptrAux->lote;
		(*Arbol) = borraNodo(*Arbol,cod,lote);
		despachar(Arbol,cod,falta);		
	} else ptrAux->cant = ptrAux->cant - cant;
}

void en_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		en_orden(Arbol->izq);
		printf("     %d         %d       %d\n",Arbol->cod,Arbol->lote,Arbol->cant);
		en_orden(Arbol->der);		
	}
}


int main () {
	TArbol Almacen;
	crearArbol(&Almacen);
	FILE *arch = fopen("data.txt","r");
	int cod, lote, cant, codp, cantidad;
	while (1) {
		fscanf(arch,"%d %d %d",&cod,&lote,&cant);
		if(feof(arch)) break;
		insertarRec(&Almacen,cod,lote,cant);
	}
	printf("\n  Cod. Prod     num. lote    cant. disp\n");
	printf("  ========================================\n");
	en_orden(Almacen);
	printf("\nIngrese producto a despachar: ");
	scanf("%d",&codp);
	printf("Ingrese cantidad: ");
	scanf("%d",&cantidad);
	despachar(&Almacen,codp,cantidad);
	printf("\nDespachando...\n\n");
	printf("  Cod. Prod     num. lote    cant. disp\n");
	printf("  ========================================\n");
	en_orden(Almacen);
	return 0;
}
