#include <stdio.h>
#include <stdlib.h>

typedef int TInfo;

typedef struct Nodo{
    TInfo dato;
    
    struct Nodo* izq;
    struct Nodo* der;
}TNodo;

typedef struct Arbol{
    TNodo* raiz;
}TArbol;


/* COLA AUXILIAR PARA CONSTRUIR ARBOL DE PRUEBA**************************************************/
typedef struct NodoCola{
    TNodo* elem;
    struct NodoCola* sig;
}TNodoCola;

typedef TNodoCola* TCola;

void crea_cola(TCola *ptrCola);
int cola_vacia(TCola ptrCola);
void encolar(TCola *ptrCola, TNodo* valor);
TNodo* desencolar(TCola *ptrCola);

void crea_cola(TCola *ptrCola){
    *ptrCola = NULL;
}

int cola_vacia(TCola ptrCola){
    return ptrCola==NULL;
}

void encolar(TCola *ptrCola, TNodo* valor){
    TNodoCola *ptrNuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    ptrNuevo->elem=valor;
    ptrNuevo->sig=*ptrCola;
    *ptrCola=ptrNuevo; 
}

TNodo* desencolar(TCola *ptrCola)
{   TNodoCola *ptrRecorrido, *ptrUltimo;
    TNodo* valor;    
    if (!cola_vacia(*ptrCola))
    {
        ptrUltimo = NULL;
        ptrRecorrido = *ptrCola;
        while (ptrRecorrido->sig)
        {
            ptrUltimo = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->sig;
        }
        if (ptrUltimo == NULL)
            *ptrCola=NULL;
        else
            ptrUltimo->sig=NULL; 
            
        valor=ptrRecorrido->elem;
        free(ptrRecorrido);
        return(valor);
    }
    
}

// pilas

typedef struct NodoPila{
    TNodo* elem;
    struct NodoPila *next;
}TNodoPila;

typedef TNodoPila* TPila ;

void crearPila(TPila *Pila) {
	(*Pila) = NULL;
}

void apilar(TPila *Pila, TNodo* elem) {
	TNodoPila *nodoNuevo;
	nodoNuevo = (TNodoPila*)malloc(sizeof(TNodoPila));
	nodoNuevo->elem = elem;
	nodoNuevo->next = (*Pila);
	(*Pila) = nodoNuevo;
}

TNodo* desapilar(TPila *Pila) {
	TNodoPila *Aux;
	TNodo* valor;
	if (!esPilaVacia(Pila)) {
		Aux = (*Pila);
		valor = Aux->elem;
		(*Pila) = Aux->next;
		free(Aux);
	}
	return valor;
}

TNodo* cima(TPila *Pila) {
	TNodoPila *Aux;
	Aux = (*Pila);
	return Aux->elem;
}

int esPilaVacia(TPila *Pila) {
	return (*Pila) == NULL;
}


void crear_arbol(TArbol *T){
    T->raiz = NULL;
}

/*FIN DE COLA AUXILIAR ******************************************************/

//Función para crear un árbol para el lab5. Usar siempre parámetros de 2^n - 1. Por ejemplo:
// 3, 7, 15, 31, etc

void crear_arbol_lab5(TArbol* T, int n){
    TCola C;
    crea_cola(&C);
    TNodo* nodo;

    int pos = (n+1)/2;
    int i;
    for(i = 0; i < pos; i++){
        nodo = (TNodo*)malloc(sizeof(TNodo));
        nodo->dato = i;
        nodo->izq = nodo->der = NULL;
        encolar(&C, nodo);
    }
    
    int cont = pos;
    while(cont < n){
        TNodo* nodo1 = desencolar(&C);
        TNodo* nodo2 = desencolar(&C);
        nodo = (TNodo*)malloc(sizeof(TNodo));
        nodo->dato = cont++;
        nodo->izq = nodo1;
        nodo->der = nodo2;
        encolar(&C, nodo); 
    }

    T->raiz = desencolar(&C);
}


// FUNCIONES DE ARBOL************************************************
void insertar(TArbol* T, TInfo x){
    //Crear nodo nuevo
    TNodo* nuevo = (TNodo*)malloc(sizeof(TNodo));
    nuevo->dato = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    //Si el arbol esta vacio
    if(T->raiz == NULL){
        T->raiz = nuevo;
        return;
    }

    //Busqueda del padre de x
    TNodo* q = T->raiz;
    TNodo* p = NULL;

    while(q != NULL){
        p = q;
        if(x < q->dato)
            q = q->izq;
        else
            q = q->der;
    }

    //Insertar x en p
    if(x < p->dato)
        p->izq = nuevo;
    else
        p->der = nuevo;
}



void finalizar(TNodo* N){
    if(N==NULL)
        return;

    finalizar(N->izq);
    finalizar(N->der);
    free(N);
}


void inorden(TNodo* N){
    if(N==NULL)
        return;

    inorden(N->izq);
    printf("%d ", N->dato);
    inorden(N->der);
}

void preorden(TNodo* N){
    if(N==NULL)
        return;

    printf("%d ", N->dato);
    preorden(N->izq);
    preorden(N->der);
}

void postorden(TNodo* N){
    if(N==NULL)
        return;

    postorden(N->izq);
    postorden(N->der);
    printf("%d ", N->dato);
}

void recorrer_niveles_orden(TNodo *N) {
	TCola C;
	TPila P;
	int valor;
    crea_cola(&C);
    crearPila(&P);
    TNodo* rec = N;
    encolar(&C,rec);
    while (!cola_vacia(C)) {
    	rec = desencolar(&C);
    	apilar(&P,rec);
    	if (rec->der) encolar(&C,rec->der);
    	if (rec->izq) encolar(&C,rec->izq);    	
	}
	while (!esPilaVacia(&P)) {
		rec = desapilar(&P);
		printf("%d ",rec->dato);
	} 
}

void main(){
    TArbol T;
    
    //Llamar a esta funcion para crear un arbol para el LAB. 
    //Usar siempre números 2^n - 1. Ejemplo: 3, 7, 15, 31, ...

    crear_arbol_lab5(&T, 7);
    inorden(T.raiz);
    printf("\n");

    //Llama aquí a tu función
    recorrer_niveles_orden(T.raiz);

    finalizar(T.raiz);
    T.raiz = NULL;
}
