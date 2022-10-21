#ifndef LSE_H
#define LSE_H

typedef int ElementoLista;

//se define el tipo de dato Nodo como una ESTRUCTURA AUTOREFERENCIADA
//En el primer campo está un ElementoLista y en el 2do campo es una
//referencia, un enlace, un puntero, al sucesor conforme
//la definicion de Lista Simplemente Enlazada
typedef struct nodo{//nombre del struct
    ElementoLista elemento;
    struct nodo *sig;
} Nodo;//nombre del tipo de dato

//Se define el tipo de dato que describe el TAD, es decir, la LSE
typedef struct{//no es necesario poner el nombre del struct, ya que no
    Nodo *cabeza;           //lo volveremos a usar
    int longitud;
} Lista;

void construirLista(Lista *);
int esListaVacia(Lista);
void insertarAlInicio(Lista *, ElementoLista);
void insertarAlFinal(Lista *, ElementoLista);
Nodo *obtenerUltimoNodo(Lista tad);
Nodo *crearNuevoNodo(ElementoLista, Nodo *);
void insertarEnOrden(Lista *, ElementoLista);
void *obtenerNodoAnterior(Lista,ElementoLista);
void destruirLista(Lista *);
int longitud(Lista);
void imprime(Lista);
int estaEnLista(Lista ptrLista, int elem);
void invierte(Lista *lista);
void invierteRecursivo(Lista*lista);

#endif