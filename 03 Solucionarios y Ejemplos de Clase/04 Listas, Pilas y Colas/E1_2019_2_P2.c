#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 20180146

typedef struct Nodo { 
	int data; 
	struct Nodo *next; 
} TNodo; 

typedef TNodo *TLista;

void crearLista(TLista *Lista) {
	(*Lista) = NULL;
}

int estaVacia(TLista Lista) {
	return Lista == NULL;
}

void insertar_inicio(TLista *Lista, int elem) {
	TNodo *nuevoNodo;
	nuevoNodo = (TNodo*)malloc(sizeof(TNodo));
	nuevoNodo->data = elem;
	nuevoNodo->next = (*Lista);
	(*Lista) = nuevoNodo;
}

void insertar_final(TLista *Lista, int elem) { 
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

int nodoNesimo(TLista Lista, int pos) {
	TNodo *Aux = Lista;
	int contador = 0;
	while (Aux) {
		if (contador == pos) return Aux->data;
		contador++;
		Aux = Aux->next;
	}
	return -1;
}

void cargabin(int num,int cromo[],int max) {	
	int i = 0, j, res;
	for(j = 0; j < max; j++) cromo[j]=0;	
	while(num>0) {
		res = num%2;
		num = num/2;
		cromo[i] = res;
		i++;
	}
}

void maximizarCargaCamion(TLista *Lista, int n, int maxcarga) {
	TLista Camion;
	crearLista(&Camion);
	int comb = pow(2,n);
	int max = 12;
	int i, j, parcial, unos, peso, mcomb;
	int cromo[n];
	for(i = 0; i < comb; i++) { 
		parcial = 0;
		cargabin(i,cromo,n);
		unos = 0;
		for(j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				parcial = parcial + nodoNesimo(*Lista,j);
				unos++;
				if(unos > max) break;
			}
		}
		if(parcial <= maxcarga && unos <= max) { 
			mcomb = i;
		}
	}
	cargabin(mcomb,cromo,n);
	peso = 0;
	for(j = 0; j < n; j++) {
		if(cromo[j] == 1) {
			peso = peso + nodoNesimo(*Lista,j);
			insertar_final(&Camion,nodoNesimo(*Lista,j));
		}
	}
	printf("Cajas Seleccionadas:\n");
	imprimirLista(Camion);
	printf("Peso Total: %d",peso);
}

int main () {
	TLista cajas;
	int arr[20] = {50,100,10,110,120,100,60,20,100,200,120,130,120,140,250,100,200,200,100,300};
	crearLista(&cajas);
	int n = 20, i;
	for (i = 0; i < 20; i++) {
		insertar_final(&cajas,arr[i]);	
	}
	printf("Lista de Cajas Original:\n");
	imprimirLista(cajas);
	maximizarCargaCamion(&cajas, n, 2000);
}
