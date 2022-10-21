#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

// OscarDD BST Library

/* Estructura de un Arbol Binario de Busqueda */

typedef int TInfo;

typedef struct Nodo {
	TInfo elem;
	struct Nodo *izq;
	struct Nodo *der;
} TNodo;

typedef TNodo *TArbol;

/* Funciones Principales */

// crear arbol

void crearArbol(TArbol *Arbol) {
	(*Arbol) = NULL;
}

// insertar nodo 

void insertarNodo(TArbol *Arbol, TInfo elem) {
	TNodo *ptrRecorrido, *ptrPadre;
	TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
	ptrNuevo->elem = elem;
	ptrNuevo->izq = ptrNuevo->der = NULL;
	if ((*Arbol) == NULL) (*Arbol) = ptrNuevo;
	else {
		ptrPadre = NULL;
		ptrRecorrido = (*Arbol);
		while (ptrRecorrido != NULL) {
			ptrPadre = ptrRecorrido;
			if (ptrRecorrido->elem > elem) ptrRecorrido = ptrRecorrido->izq;
			else ptrRecorrido = ptrRecorrido->der;
		}
		if (ptrPadre->elem > elem) ptrPadre->izq = ptrNuevo;
		else ptrPadre->der = ptrNuevo;
	}
}

// insertar nodo recursivo

void insertarRec(TArbol *Arbol, TInfo elem) {	
	if ((*Arbol) == NULL) {
		TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
		ptrNuevo->elem = elem;
		ptrNuevo->izq = ptrNuevo->der = NULL;
		(*Arbol) = ptrNuevo;
	} else {
		if ((*Arbol)->elem > elem) insertarRec(&((*Arbol)->izq),elem);
		else insertarRec(&((*Arbol)->der),elem);
	}
}

// buscar elemento -> arbol

TArbol buscar(TArbol Arbol, TInfo elem) {
	if (Arbol == NULL) return NULL;
	else {
		if(Arbol->elem == elem) return Arbol;
		else {
			if (Arbol->elem < elem) Arbol = Arbol->der;
            else Arbol = Arbol->izq;
            return(buscar(Arbol,elem));
		}
	}
}

// pre orden rec (root -> left -> right)

void pre_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		printf("%d  ",Arbol->elem);
		pre_orden(Arbol->izq);
		pre_orden(Arbol->der);
	}
}

// pos orden rec (left -> right -> root)

void pos_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		pos_orden(Arbol->izq);
		pos_orden(Arbol->der);
		printf("%d  ",Arbol->elem);
	}
}

// en orden rec (left -> root -> right)

void en_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		en_orden(Arbol->izq);
		printf("%d  ",Arbol->elem);
		en_orden(Arbol->der);		
	}
}

int es_vacio(TArbol *Arbol) {
	return (*Arbol) == NULL;
}

/* minimo y maximo de un numero */

int minn(int a, int b) {
	if (a > b) return b;
	else return a;
}

int maxx(int a, int b) {
	if (a > b) return a;
	else return b;
}

// recorre mayores a un elemento

void recorreMayores(TArbol Arbol, TInfo elem) {
	if (Arbol != NULL) {
		if (Arbol->elem > elem) printf("%d  ",Arbol->elem);	
		recorreMayores(Arbol->izq,elem);
		recorreMayores(Arbol->der,elem);		
	}
}

// escribe de menor a mayor el arbol

void escribeMenores(TArbol Arbol) {
	if (Arbol != NULL) {
		escribeMenores(Arbol->der);
		printf("%d  ",Arbol->elem);
		escribeMenores(Arbol->izq);
	}
}

// altura de un arbol

int altura(TArbol Arbol) {
	if (Arbol == NULL) return 0;
	int alt_izq = altura(Arbol->izq);
	int alt_der = altura(Arbol->der);
	if (alt_izq > alt_der) return alt_izq + 1;
	else return alt_der + 1;
}

// diametro de un arbolBB

int diametro(TArbol Arbol) {
	if (Arbol == NULL) return 0;
	int curr = 1 + altura(Arbol->izq) + altura(Arbol->der);
	return maxx(curr,maxx(diametro(Arbol->izq),diametro(Arbol->der)));
}

// esta un elemento en el arbol?

int esta(TArbol Arbol, TInfo elem) {
	TNodo *aux;
	aux = Arbol;
	while (aux != NULL) {
		if (aux->elem == elem) 
			return 1;
		else if (elem < aux->elem) aux = aux->izq;
		else aux = aux->der;
	}
	return 0;
}

// esta recursivo

int estaRec(TArbol Arbol, TInfo elem) {
	if (Arbol == NULL) return 0;
	if (Arbol->elem == elem) return 1;
	if (estaRec(Arbol->izq,elem)) return 1;
	return (estaRec(Arbol->der,elem));
}

// numero de nodos de un arbol

int numNodos(TArbol Arbol) {
	if (Arbol == NULL) return 0;
	return 1 + numNodos(Arbol->izq) + numNodos(Arbol->der);	
}

// eliminar nodos de un arbol

void eliminarNodo(TArbol *Arbol, TInfo elem) {
	TNodo *ptrRecorrido, *ptrAnt, *ptrAux;
	int encontrado = 0;
	ptrAnt = NULL;
	ptrRecorrido = (*Arbol);
	while (!encontrado && (ptrRecorrido != NULL)) {
		if (elem == ptrRecorrido->elem) encontrado = 1;
		else {
			ptrAnt = ptrRecorrido;
			if (ptrRecorrido->elem > elem) ptrRecorrido = ptrRecorrido->izq;
			else ptrRecorrido = ptrRecorrido->der;
		}
	}
	if (ptrRecorrido != NULL) {
		ptrAux = ptrRecorrido;
		if (ptrAux->izq == NULL) {
			if (ptrAnt == NULL) (*Arbol) = ptrAux->der;
			else if (ptrAnt->elem > elem) ptrAnt->izq = ptrAux->der;
			else ptrAnt->der = ptrAux->der;
		} else {
			if (ptrAux->der == NULL) {
				if (ptrAnt == NULL) (*Arbol) = ptrAux->izq;
				else {
					if (ptrAnt->elem > elem) ptrAnt->izq = ptrAux->izq;
					else ptrAnt->der = ptrAux->izq;
				}
			} else {
				TNodo *ptr1, *ptr2;
				ptr2 = ptrAux;
				ptr1 = ptrAux->izq;
				while (ptr1->der != NULL) {
					ptr2 = ptr1;
					ptr1 = ptr1->der;
				}
				ptrAux->elem = ptr1->elem;
				if (ptr2 == ptrAux) ptrAux->izq = ptr1->izq;
				else ptr2->der = ptr1->izq;
				ptrAux = ptr1;
			}
			free(ptrAux);
		}
	}
}

// elemento minimo de un arbol

int minimo(TArbol *Arbol) {
	TNodo *ptrRecorrido;
	ptrRecorrido = (*Arbol);
	int min = ptrRecorrido->elem;
	while (ptrRecorrido->izq != NULL) {
		min = ptrRecorrido->izq->elem;
		ptrRecorrido = ptrRecorrido->izq;
	}
	return min;
}

/* Recorridos Iterativos del Arbol BB no recursivos */

typedef TArbol TInfo2;

typedef struct NodoPila{
    TInfo2 elem;
    struct NodoPila *next;
}TNodoPila;

typedef TNodoPila* TPila ;

void crearPila(TPila *Pila) {
	(*Pila) = NULL;
}

void apilar(TPila *Pila, TInfo2 elem) {
	TNodoPila *nodoNuevo;
	nodoNuevo = (TNodoPila*)malloc(sizeof(TNodoPila));
	nodoNuevo->elem = elem;
	nodoNuevo->next = (*Pila);
	(*Pila) = nodoNuevo;
}

TInfo2 desapilar(TPila *Pila) {
	TNodoPila *Aux;
	TInfo2 valor;
	if (!esPilaVacia(Pila)) {
		Aux = (*Pila);
		valor = Aux->elem;
		(*Pila) = Aux->next;
		free(Aux);
	}
	return valor;
}

int esPilaVacia(TPila *Pila) {
	return (*Pila) == NULL;
}

TInfo2 cima(TPila *Pila) {
	TNodoPila *Aux;
	Aux = (*Pila);
	return Aux->elem;
}

void finalizarPila(TPila Pila) {
	TNodoPila *Aux;
	Aux = Pila;
	while (Aux) {
		Pila = Aux->next;
		free(Pila);
		Aux = Pila;
	}
}

void pre_orden_iter(TArbol Arbol) {
	TPila miPila;
	crearPila(&miPila);
	while (1) {
		while (Arbol != NULL) {
			apilar(&miPila,Arbol);
			printf("%d  ",Arbol->elem);
			Arbol = Arbol->izq;
		}
		if (esPilaVacia(&miPila)) break;		
		Arbol = desapilar(&miPila);
		Arbol = Arbol->der;
	}
	finalizarPila(miPila);
}

void pos_orden_iter(TArbol Arbol) {
	TPila miPila;
	crearPila(&miPila);
	while (1) {
		if (Arbol != NULL) {
			apilar(&miPila,Arbol);
			Arbol = Arbol->izq;
		} else {
			if (esPilaVacia(&miPila)) break;
			Arbol = cima(&miPila)->der;
			if (Arbol == NULL) {
				TNodo *ptrRecorrido = NULL;
				while (!esPilaVacia(&miPila) && cima(&miPila)->der == ptrRecorrido) {
					ptrRecorrido = cima(&miPila);
					TNodo *no_sirve = desapilar(&miPila);
					printf("%d  ",ptrRecorrido->elem);
				}
			}
		}
	}
	finalizarPila(miPila);
}

void en_orden_iter(TArbol Arbol) {
	TPila miPila;
	crearPila(&miPila);
	while (1) {
		while (Arbol != NULL) {
			apilar(&miPila,Arbol);
			Arbol = Arbol->izq;
		}
		if (esPilaVacia(&miPila)) break;
		Arbol = desapilar(&miPila);
		printf("%d  ",Arbol->elem);
		Arbol = Arbol->der;
	}
	finalizarPila(miPila);
}

/* imprimir un arbol en 2D */

void imp2D(TArbol Arbol, int space) {
	if (Arbol == NULL) return;
	int i;
	space += COUNT;
	imp2D(Arbol->der,space);
	printf("\n");
	for(i = COUNT; i < space; i++) printf(" ");
	printf("%d\n",Arbol->elem);
	imp2D(Arbol->izq,space);
}

void imprimir2D(TArbol Arbol) {
	imp2D(Arbol,0);
}

/* camino de nodo a nodo */

// ancestro comun de dos nodos

TArbol LWCA(TArbol Arbol, TArbol A, TArbol B) {
	if (Arbol == NULL) return NULL;
	if (Arbol == A || Arbol == B) return Arbol;
	TArbol izq = LWCA(Arbol->izq,A,B);
	TArbol der = LWCA(Arbol->der,A,B);	
	if (izq != NULL && der != NULL) return Arbol;
	else {
		if (izq != NULL ) return izq;
		else return der;
	}
}

void camino(TArbol Arbol, TInfo a, TInfo b) {
	TPila miPila;
	crearPila(&miPila);
	TArbol Padre = LWCA(Arbol,buscar(Arbol,a),buscar(Arbol,b));
	TNodo *ptrRec = Padre;
	while (1) {
		while (ptrRec != NULL && ptrRec->elem != a) {
			apilar(&miPila,ptrRec);
			ptrRec = ptrRec->izq;
		}
		if (ptrRec != NULL && ptrRec->elem == a) {
			printf("%d ",ptrRec->elem);
			break;
		}
		if (cima(&miPila)->der == NULL) {
			ptrRec = desapilar(&miPila);
			while (!esPilaVacia(&miPila) && cima(&miPila)->der == ptrRec) ptrRec = desapilar(&miPila);
		}
		if(esPilaVacia(&miPila)) ptrRec = NULL;
		else ptrRec = cima(&miPila)->der;
	}
	while (!esPilaVacia(&miPila)) printf("%d ",desapilar(&miPila)->elem);
	finalizarPila(miPila);
	ptrRec = Padre;
	while (ptrRec->elem != b) {
		if (b > ptrRec->elem) ptrRec = ptrRec->der;
		else ptrRec = ptrRec->izq;
		printf("%d ",ptrRec->elem);		
	}	
}

// camino de un elemento de un arbol a la raiz

int camino_root(TArbol Arbol, TInfo elem) {
	if (Arbol == NULL) return 0;
	if (Arbol->elem == elem) {
		printf("%d ",Arbol->elem);
		return 1;
	}
	if (camino_root(Arbol->izq,elem) || camino_root(Arbol->der,elem)) {
		printf("%d ",Arbol->elem);
		return 1;
	}
	return 0;
}

// verifica que todos elementos del arbol esten en el rango [min,max]

int esta_rango(TArbol Arbol, TInfo min, TInfo max) {
	if (Arbol == NULL) return 1;
	if ((Arbol->elem >= min && Arbol->elem <= max) && esta_rango(Arbol->izq,min,max)
		&& esta_rango(Arbol->der,min,max)) return 1;
	return 0;
}

/* imprimir por niveles un arbol */

typedef struct NodoCola{
    TInfo2 elem;
    struct NodoCola *next;
} TNodoCola;

typedef TNodoCola *TCola;

void crearCola(TCola *Cola) {
	(*Cola) = NULL;
}

int esColaVacia(TCola Cola) {
	return Cola == NULL;
}

void encolar(TCola *Cola, TInfo2 elem) {
	TNodoCola *nodoNuevo;
	nodoNuevo = (TNodoCola *)malloc(sizeof(TNodoCola));
	nodoNuevo->elem = elem;
	nodoNuevo->next = (*Cola);
	(*Cola) = nodoNuevo;
}

TInfo2 desencolar(TCola *Cola) {
	TNodoCola *Aux, *Ult;
	TInfo2 elem;
	if (!esColaVacia(*Cola)) { 
		Ult = NULL;
		Aux = (*Cola);
		while (Aux->next) {
			Ult = Aux;
			Aux = Aux->next;
		}
		if (Ult == NULL) (*Cola) = NULL;
		else Ult->next = NULL;
		elem = Aux->elem;
		free(Aux);
		return elem;
	}		
}

int tamanioCola(TCola Cola) { 
	if (Cola == NULL) return 0;
	Cola = Cola->next;
	return (tamanioCola(Cola)+1);
}

void finalizarCola(TCola Cola) {
	TNodoCola *Aux;
	Aux = Cola;
	while (Aux) {
		Cola = Aux->next;
		free(Cola);
		Aux = Cola;
	}
}

// recorrido por niveles de un arbol

void nivel_orden(TArbol Arbol) {
	TCola ColaAux;
	crearCola(&ColaAux);
	TNodo *ptrRec = Arbol;
	while (ptrRec != NULL) {
		printf("%d  ",ptrRec->elem);
		if (ptrRec->izq != NULL) encolar(&ColaAux,ptrRec->izq);
		if (ptrRec->der != NULL) encolar(&ColaAux,ptrRec->der);
		if(esColaVacia(ColaAux)) break;
		ptrRec = desencolar(&ColaAux);
	}
	finalizarCola(ColaAux);
}

void nivel_desorden(TArbol Arbol) {
	TCola ColaAux;
	TPila pila;
	crearCola(&ColaAux);
	crearPila(&pila);
	TNodo *ptrRec = Arbol;
	while (ptrRec != NULL) {
		apilar(&pila,ptrRec);
		if (ptrRec->izq != NULL) encolar(&ColaAux,ptrRec->izq);
		if (ptrRec->der != NULL) encolar(&ColaAux,ptrRec->der);
		if(esColaVacia(ColaAux)) break;
		ptrRec = desencolar(&ColaAux);
	}
	while (!esPilaVacia(&pila)) printf("%d ",desapilar(&pila)->elem);
	finalizarCola(ColaAux);
}

// buscar elemento menor de un arbol -> retorna arbol

TArbol buscaMenor(TArbol Arbol){
    if(Arbol == NULL) return NULL;
    else {
        if(Arbol->izq != NULL) return(buscaMenor(Arbol->izq));
        else return(Arbol);
    }     
}

// eliminar nodo recursivo

TArbol borraNodo(TArbol Arbol, TInfo elem) {
	if (Arbol == NULL) return Arbol;
	if (elem < Arbol->elem) Arbol->izq = borraNodo(Arbol->izq,elem);
	else {
		if (elem > Arbol->elem) Arbol->der = borraNodo(Arbol->der,elem);
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
			Arbol->elem = temp->elem;
			Arbol->der = borraNodo(Arbol->der,temp->elem);
		}
	}
	return Arbol;
}

// duplicar arbolBB

void duplicarArbol(TArbol Arbol) {
	if (Arbol == NULL) return;
	duplicarArbol(Arbol->izq);
	duplicarArbol(Arbol->der);
	TArbol aux = Arbol->izq;
	TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
	ptrNuevo->elem = Arbol->elem;
	ptrNuevo->izq = ptrNuevo->der = NULL;
	Arbol->izq = ptrNuevo;
	Arbol->izq->izq = aux;
}

// insertar rec -> arbol

TArbol insertRec(TArbol Arbol, TInfo elem) {
	if (Arbol == NULL) {
		TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
		ptrNuevo->elem = elem;
		ptrNuevo->izq = ptrNuevo->der = NULL;
		Arbol = ptrNuevo;
	} else {
		if (Arbol->elem > elem) Arbol->izq = insertRec(Arbol->izq,elem);
		else Arbol->der = insertRec(Arbol->der,elem);
	}
	return Arbol;
}

// imprimir en orden dos arbolesBB

void ordenarBST(TArbol Arbol1, TArbol Arbol2) {
	TNodo *ptrRec1, *ptrRec2;
	TPila miPila1, miPila2;
	crearPila(&miPila1);
	crearPila(&miPila2);
	ptrRec1 = Arbol1;
	ptrRec2 = Arbol2;
	if (Arbol1 == NULL) {
		en_orden(Arbol2);
		return;
	}
	if (Arbol2 == NULL) {
		en_orden(Arbol1);
		return;
	}
	while (ptrRec1 != NULL || ptrRec2 != NULL || !esPilaVacia(&miPila1) || !esPilaVacia(&miPila2)) {
		if (ptrRec1 != NULL || ptrRec2 != NULL) {
			if (ptrRec1 != NULL) {
				apilar(&miPila1,ptrRec1);
				ptrRec1 = ptrRec1->izq;
			}
			if (ptrRec2 != NULL) {
				apilar(&miPila2,ptrRec2);
				ptrRec2 = ptrRec2->izq;
			}			
		} else {
			if (esPilaVacia(&miPila1)) {
				while (!esPilaVacia(&miPila2)) {
					ptrRec2 = desapilar(&miPila2);
					ptrRec2->izq = NULL;
					en_orden(ptrRec2);
				}
				return;
			}
			if (esPilaVacia(&miPila2)) {
				while (!esPilaVacia(&miPila1)) {
					ptrRec1 = desapilar(&miPila1);
					ptrRec1->izq = NULL;
					en_orden(ptrRec1);
				}
				return;
			}
			ptrRec1 = desapilar(&miPila1);
			ptrRec2 = desapilar(&miPila2);
			if (ptrRec1->elem < ptrRec2->elem) {
				printf("%d   ",ptrRec1->elem);
				ptrRec1 = ptrRec1->der;
				apilar(&miPila2,ptrRec2);
				ptrRec2 = NULL;
			} else {
				printf("%d   ",ptrRec2->elem);
				ptrRec2 = ptrRec2->der;
				apilar(&miPila1,ptrRec1);
				ptrRec1 = NULL;
			}
		}
	}
}

// juntar 2 arbolesBB metodo postorden recursivo

void junta(TArbol *Arbol1, TArbol *Arbol2) {
	int valor;
	TNodo *aux;
	aux = *Arbol2;
	if (aux != NULL) {
		junta(Arbol1,&aux->izq);
		junta(Arbol1,&aux->der);
		valor = aux->elem;
		free(aux);
		insertarNodo(Arbol1,valor);
		*Arbol2 = NULL;
	}
}

// juntar 2 arboles metodo preorden recursivo

void junta2(TArbol *Arbol1, TArbol *Arbol2) {
	int valor;
	TNodo *aux;
	aux = *Arbol2;
	if (aux != NULL) {
		valor = aux->elem;		
		insertarNodo(Arbol1,valor);
		junta2(Arbol1,&aux->izq);
		junta2(Arbol1,&aux->der);
		eliminarNodo(&aux,valor);
		*Arbol2 = NULL;
	}
}

// juntar 2 arboles metodo en orden iterativo

void junta3(TArbol *Arbol1, TArbol *Arbol2) {
	int valor;
	TNodo *aux, *temp;
	aux = *Arbol2;
	while (aux != NULL) {
		temp = buscaMenor(aux);
		valor = temp->elem;
		insertarNodo(Arbol1,valor);
		eliminarNodo(&aux,valor);
	}
	*Arbol2 = NULL;
}

// juntar 2 arboles metodo en orden recursivo

void junta4(TArbol *Arbol1, TArbol *Arbol2) {
	int valor;
	TNodo *aux;
	aux = *Arbol2;
	if (aux != NULL) {
		junta4(Arbol1,&aux->izq);
		valor = aux->elem;		
		insertarNodo(Arbol1,valor);				
		junta4(Arbol1,&aux->der);
		eliminarNodo(&aux,valor);		
		*Arbol2 = NULL;
	}
}

// construir arbolBB dados recorridos en orden y pre orden

TArbol buildTree(TInfo in[16], TInfo pre[16], TInfo ini, TInfo fin, TInfo *i) {
	if (ini > fin) return NULL;
	TNodo *ptrAux = (TNodo *)malloc(sizeof(TNodo));
	ptrAux->elem = pre[(*i)];
	ptrAux->izq = ptrAux->der = NULL;
	(*i)++;
	int j;
	for (j = ini; j <= fin; j++) 
		if (in[j] == ptrAux->elem) break;
	ptrAux->izq = buildTree(in,pre,ini,j-1,i);
	ptrAux->der = buildTree(in,pre,j+1,fin,i);	
	return ptrAux;
}

// construir arbolBB dados recorridos en orden y pos orden

TArbol buildTree2(TInfo in[16], TInfo pos[16], TInfo ini, TInfo fin, TInfo *i) {
	if (ini > fin) return NULL;
	TNodo *ptrAux = (TNodo *)malloc(sizeof(TNodo));
	ptrAux->elem = pos[(*i)];
	ptrAux->izq = ptrAux->der = NULL;
	(*i)--;
	int j;
	for (j = ini; j <= fin; j++) 
		if (in[j] == ptrAux->elem) break;
	ptrAux->der = buildTree2(in,pos,j+1,fin,i);
	ptrAux->izq = buildTree2(in,pos,ini,j-1,i);		
	return ptrAux;
}

// construir arbolBB dado recorrido en pre orden

TArbol buildTree3(TInfo pre[16], TInfo min, TInfo max, TInfo n, TInfo *i) {
	if ((*i) >= n) return NULL;	
	TNodo *ptrAux = NULL;
	int j = pre[(*i)];
	int pertenece = (min == -1 || j > min) && (max == -1 || j < max);
	if (pertenece) {
		ptrAux = (TNodo *)malloc(sizeof(TNodo));
		ptrAux->elem = pre[(*i)];
		ptrAux->izq = ptrAux->der = NULL;
		(*i)++;
		ptrAux->izq = buildTree3(pre,min,j,n,i);
		ptrAux->der = buildTree3(pre,j,max,n,i);	
	}
	return ptrAux;
}

// recorrido en orden iterativo sin pilas

void en_orden_wow(TArbol Arbol) {
	TNodo *curr = Arbol;
	while (curr != NULL) {
		if (curr->izq != NULL) {
			TNodo *aux = curr->izq;
			while (aux->der != NULL && aux->der != curr) aux = aux->der;
			if (aux->der == NULL) {
				aux->der = curr;
				curr = curr->izq;
			} else {
				aux->der = NULL;
				printf("%d  ",curr->elem);
				curr = curr->der;
			}
		} else {
			printf("%d  ",curr->elem);
			curr = curr->der;
		}
	}
}

// recorrido pre orden iterativo sin pilas

void pre_orden_wow(TArbol Arbol) {
	while (Arbol != NULL) {
		if (Arbol->izq == NULL) {
			printf("%d  ",Arbol->elem);
			Arbol = Arbol->der;
		} else {
			TNodo *aux = Arbol->izq;
			while (aux->der != NULL && aux->der != Arbol) aux = aux->der;
			if (aux->der == Arbol) {
				aux->der = NULL;
				Arbol = Arbol->der;
			} else {
				printf("%d  ",Arbol->elem);
				aux->der = Arbol;
				Arbol = Arbol->izq;
			}
		}
	}
}

TArbol borraArbolRango(TArbol Arbol, TInfo min, TInfo max) {
	if (Arbol == NULL) return NULL;
	Arbol->izq = borraArbolRango(Arbol->izq,min,max);
	Arbol->der = borraArbolRango(Arbol->der,min,max);
	if (Arbol->elem < min) return Arbol->der;
	if (Arbol->elem > max) return Arbol->izq;
	return Arbol;
}

// verificar que un arbolbb este balanceado

int estaBalanceado(TArbol Arbol) {
	if(Arbol == NULL) return 1;
	int alt_izq = altura(Arbol->izq);
	int alt_der = altura(Arbol->der);
	if (abs(alt_izq - alt_der) <= 1 && estaBalanceado(Arbol->izq) && estaBalanceado(Arbol->der)) return 1;
	else return 0;
}

TArbol kthminNode(TArbol Arbol, TInfo k, TInfo *i) {
	if (Arbol == NULL) return NULL;
	TNodo *ptrAux = kthminNode(Arbol->izq,k,i);
	if (ptrAux != NULL) return ptrAux;
	(*i)++;
	if((*i) == k) return Arbol;
	return kthminNode(Arbol->der,k,i);
	
}
