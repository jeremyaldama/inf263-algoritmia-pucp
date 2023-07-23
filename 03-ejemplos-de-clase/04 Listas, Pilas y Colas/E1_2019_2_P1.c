#include <stdio.h>
#include <stdlib.h>
#define max 100

// 20180146

typedef struct NodoPilaInc{ 
	int dia;
	int precio;
	int intervalo;
	struct NodoPilaInc *next;
} TNodoPilaInc;

typedef TNodoPilaInc *TPilaInc;

void crearPila(TPilaInc *PilaInc) {
	(*PilaInc) = NULL;
}

int es_pila_vacia(TPilaInc *PilaInc){
    return (*PilaInc) == NULL;
}

void cima(TPilaInc *PilaInc, int *precio, int *intervalo) {
	TNodoPilaInc *Aux;
	Aux = (*PilaInc);
	if (es_pila_vacia(PilaInc)) { 
		(*precio) = -1;
		(*intervalo) = -1;
	} else {
		(*precio) = Aux->precio;
		(*intervalo) = Aux->intervalo;
	}
}

void apilar(TPilaInc *PilaInc, int precio, int intervalo) {
	TNodoPilaInc *Nuevo;
	Nuevo = (TNodoPilaInc *)malloc(sizeof(TNodoPilaInc));
	Nuevo->precio = precio;
	Nuevo->intervalo = intervalo;
	Nuevo->next = (*PilaInc);
	(*PilaInc) = Nuevo;
}

void desapilar(TPilaInc *PilaInc, int *precio, int *intervalo) {
	TNodoPilaInc *Aux;
	if (!es_pila_vacia(PilaInc)) {
		Aux = (*PilaInc);
		(*precio) = Aux->precio;
		(*intervalo) = Aux->intervalo;
		(*PilaInc) = Aux->next;
		free(Aux);
	}
}

int main () {
	int precios[7] = {100,80,60,70,60,75,85};
	int cant = 7, i;
	int conj[max];
	int precio, intervalo;
	TPilaInc PilaInc;
	crearPila(&PilaInc);
	for (i = 0; i < cant; i++)	{ 
		conj[i] = 1; // intervalo min de cada precio
		if (i == 0) apilar(&PilaInc,precios[i],1);
		else {
			cima(&PilaInc,&precio,&intervalo);
			if (precios[i] < precio) {
				apilar(&PilaInc,precios[i],1);
			} else {
				while (PilaInc)	{ 
					cima(&PilaInc,&precio,&intervalo);
					//printf("PILA: %d %d %d\n",precio,intervalo,precios[i]);
					if (precios[i] < precio) {
						apilar(&PilaInc,precios[i],conj[i]);
						break;
					} else desapilar(&PilaInc,&precio,&intervalo);
					conj[i] += intervalo;
				}
			}
		}
	}
	for(i = 0; i < cant; i++) printf("%d ",conj[i]);
	return 0;
}
