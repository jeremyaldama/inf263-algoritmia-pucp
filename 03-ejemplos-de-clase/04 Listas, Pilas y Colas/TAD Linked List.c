#include <stdio.h>
#include <stdlib.h>

// 20180146

typedef int TData;

typedef struct Nodo { 
	TData data; 
	struct Nodo *next; 
} TNodo; 

typedef TNodo *TLista;

void crearLista(TLista *Lista) {
	(*Lista) = NULL;
}

int estaVacia(TLista Lista) {
	return Lista == NULL;
}

void insertar_inicio(TLista *Lista, TData elem) {
	TNodo *nuevoNodo;
	nuevoNodo = (TNodo*)malloc(sizeof(TNodo));
	nuevoNodo->data = elem;
	nuevoNodo->next = (*Lista);
	(*Lista) = nuevoNodo;
}

void insertar_final(TLista *Lista, TData elem) { 
	TNodo *nodoNuevo, *nodoAux, *nodoUlt;
	nodoNuevo = (TNodo*)malloc(sizeof(TNodo));
	nodoNuevo->data = elem;
	nodoNuevo->next = NULL;
	nodoAux = (*Lista);
	nodoUlt = NULL;
	while (nodoAux) {
		nodoUlt = nodoAux;
		nodoAux = nodoAux->next;
	}
	if (nodoUlt) nodoUlt->next = nodoNuevo;
	else (*Lista) = nodoNuevo; 
}

void imprimirLista(TLista Lista) {
	TNodo *Aux;
	Aux = Lista;
	while (Aux) {
		printf("%d -> ",Aux->data);
		Aux = Aux->next;
	}
	printf("NULL\n");
}

int tamanioLista(TLista Lista) {
	TLista Aux;
	int contador = 0;
	Aux = Lista;
	while (Aux) {
		Aux = Aux->next;
		contador++;
	}
	return contador;
}

int esta_enla_Lista(TLista Lista, TData elem) {
	TNodo *Aux;
	Aux = Lista;
	while (Aux) {
		if (Aux->data == elem) return 1;
		Aux = Aux->next;
	}
	return 0;
}

void invierteLista(TLista *Lista) {   
	TLista Aux, ant, ini;
    int i, j, n;   
    n = tamanioLista(*Lista);
    for (i = 1; i < n; i++) {   
		Aux = (*Lista);
        for (j = i; j < n; j++) {   
			ant = Aux; 
            Aux = Aux->next;
        }
        if (i == 1)
            ini = Aux;
        Aux->next = ant;
    }
    ant->next = NULL;
    (*Lista) = ini;
}

int nodoNesimo(TLista Lista, TData pos) {
	TNodo *Aux = Lista;
	int contador = 0;
	while (Aux) {
		if (contador == pos) return Aux->data;
		contador++;
		Aux = Aux->next;
	}
	return -1;
}

int contarRep(TLista Lista, TData elem) {
	TNodo *Aux = Lista;
	int contador = 0;
	while (Aux) {
		if (Aux->data == elem) contador++;
		Aux = Aux->next;
	}
	return contador;
}

void finalizarLista(TLista Lista) {
	TNodo *Aux, *liberar;
	Aux = Lista;
	while (Aux) {
		liberar = Aux;
		Aux = Aux->next;
		free(liberar);
	}
}

void divide2(TLista Lista, TLista *L1, TLista *L2) {
	int i = 1, n;
	n = tamanioLista(Lista);
	while (i <= n) {
		if (i % 2 == 0) insertar_final(L1,Lista->data);
		else  insertar_final(L2,Lista->data);
		i++;
		Lista = Lista->next;
	}
}

void eliminarNodo(TLista *Lista, TData elem) {
	TNodo *Aux, *ant;
	Aux = (*Lista);
	if (Aux && Aux->data == elem) {
		(*Lista) = Aux->next;
		free(Aux);
		return;
	}
	while (Aux && Aux->data != elem) {
		ant = Aux;
		Aux = Aux->next;
	}
	if (Aux == NULL) return;
	ant->next = Aux->next;
	free(Aux);
}

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

void intercambiarNodos(TLista *Lista, int elem1, int elem2) {
	TNodo *prev1, *act1, *prev2, *act2, *aux;
	if(elem1 == elem2) return;
	prev1 = NULL;
	act1 = (*Lista);
	while (act1 && act1->data != elem1) {
		prev1 = act1;
		act1 = act1->next;
	}
	prev2 = NULL;
	act2 = (*Lista);
	while (act2 && act2->data != elem2) {
		prev2 = act2;
		act2 = act2->next;
	}
	if (act1 == NULL || act2 == NULL) return;
	if (prev1 != NULL) prev1->next = act2;
	else (*Lista) = act2;
	if (prev2 != NULL) prev2->next = act1;
	else (*Lista) = act1;
	aux = act2->next;
	act2->next = act1->next;
	act1->next = aux;
}

void ordenarLista(TLista *Lista) {
	TNodo *prev, *act, *aux;
	int n = tamanioLista(*Lista);
	int i;
	for (i = 0; i < n-1; i++) {
		prev = NULL;
		act = (*Lista);
		while (act != NULL && act->next != NULL) {
			if(act->data > act->next->data) {
				if(prev == NULL) {
					aux = act->next;
					act->next = aux->next;
					aux->next = act;
					prev = aux;
					(*Lista) = prev;
				} else {
					aux = act->next;
					prev->next = aux;
					act->next = aux->next;
					aux->next = act;
					prev = aux;
				}
			} else {
				aux = act->next;
				prev = act;
				act = aux;
			}
		}
	}	
}

