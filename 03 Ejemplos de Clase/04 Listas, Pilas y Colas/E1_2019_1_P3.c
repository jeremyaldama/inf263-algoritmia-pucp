#include <stdio.h>
#include <stdlib.h>
#include "TAD Linked List.c"

// 20180146

void invertirListaRec(TLista *Lista) {
	TNodo *Aux, *then;
	Aux = (*Lista);
	then = Aux->next;
	if (Aux == NULL || Aux->next == NULL) return;
	invertirListaRec(&then);
	Aux->next->next = Aux;
	Aux->next = NULL;
	(*Lista) = then;
}

int main () {
	TLista miLista;
	int num, i, data;
	crearLista(&miLista);
	printf("Ingrese la cantidad de elementos: ");
	scanf("%d",&num);
	for (i = 0; i < num; i++) {
		scanf("%d",&data);
		insertar_final(&miLista,data);
	}
	printf("Lista Original:\n");
	imprimirLista(miLista);
	invertirListaRec(&miLista);
	printf("Lista Invertida:\n");
	imprimirLista(miLista);
	return 0;
}
