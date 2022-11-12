#ifndef ABC_H
#define ABC_H

typedef int ElementoArbol;

typedef struct nodo{
    struct nodo *hizq;
    ElementoArbol elemento;
    struct nodo *hder;
}Nodo;
typedef Nodo* ArbolBinario;
typedef ArbolBinario ABC;

void construirArbol(ArbolBinario *pAB);
Nodo *crearNuevoNodo(ArbolBinario arbolIzq,ElementoArbol elemento, ArbolBinario arbolDer);
void plantar(ArbolBinario *pAB,ArbolBinario arbolIzq,ElementoArbol elemento,ArbolBinario arbolDer);
int esArbolVacio(ArbolBinario AB);
void recorrerEnOrden(ArbolBinario AB);
void recorrerEnPreOrden(ArbolBinario AB);
void recorrerEnPostOrden(ArbolBinario AB);
int contarNodos(ArbolBinario AB);
int esHoja(ArbolBinario AB);
int maximo(int x,int y);
int altura(ArbolBinario AB);
int esEquilibrado(ArbolBinario AB);
void insertar(ABC *pAAB, ElementoArbol elemento);
int buscar(ABC ABB, ElementoArbol valor);
ElementoArbol menor(ABC ABB);
void eliminar(ABC *pABB,ElementoArbol elemento);
void destruir(ABC *pABB);

#endif /* ABB_H */

