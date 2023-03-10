#include <stdio.h>
#include <stdlib.h>
#include "TAD Linked List.c"

// 20180146

void eliminarDuplicados(TLista *Lista) {
	TNodo *aux1, *aux2, *dup;
	aux1 = (*Lista);
	while (aux1 && aux1->next) {
		aux2 = aux1;
		while (aux2->next) {
			if (aux1->data == aux2->next->data) {
				dup = aux2->next;
				aux2->next = aux2->next->next;
				free(dup);
			} else {
				aux2 = aux2->next;
			}
		}
		aux1 = aux1->next;
	}
}

int main () {
	int num, dato, i;
	TLista miLista;
	crearLista(&miLista);
	printf("Ingrese el numero de datos: ");
	scanf("%d",&num);
	for (i = 0; i < num; i++) {
		scanf("%d",&dato);
		insertar_final(&miLista,dato);
	}
	printf("Lista Original:\n");
	imprimirLista(miLista);
	eliminarDuplicados(&miLista);
	printf("Lista Resultante:\n");
	imprimirLista(miLista);
}
