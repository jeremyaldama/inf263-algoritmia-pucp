#ifndef ABB_H
#define ABB_H


typedef int ElementoArbol;

typedef struct nodo{
    struct nodo *hizq;
    ElementoArbol elemento;
    struct nodo *hder;
}Nodo;
typedef Nodo* ArbolBinario;
typedef ArbolBinario ArbolBinarioBusqueda;
void construirArbol(ArbolBinario *pAB);
Nodo *crearNuevoNodo(ArbolBinario arbolIzq,ElementoArbol elemento, ArbolBinario arbolDer);
void plantar(ArbolBinario *pAB,ArbolBinario arbolIzq,ElementoArbol elemento,ArbolBinario arbolDer);
int esArbolVacio(ArbolBinario AB);
void recorrerEnPostOrden(ArbolBinario AB);
int contarNodos(ArbolBinario AB);
int esHoja(ArbolBinario AB);
int maximo(int x,int y);
int altura(ArbolBinario AB);
int esEquilibrado(ArbolBinario AB);
int buscar(ArbolBinarioBusqueda ABB, ElementoArbol valor);
ElementoArbol menor(ArbolBinarioBusqueda ABB);
void eliminar(ArbolBinarioBusqueda *pABB,ElementoArbol elemento);
void destruir(ArbolBinarioBusqueda *pABB);

#endif /* ABB_H */

