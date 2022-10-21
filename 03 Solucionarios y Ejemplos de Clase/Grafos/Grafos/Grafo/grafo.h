#ifndef GRAFO_H
#define GRAFO_H

/*Definimos el tipo de dato que representará al nodo del grafo. Para este ejemplo
 estamos creando grafos en donde cada nodo está representado por un número entero,
 pero podrían trabajarse otros tipos de datos como reales, cadenas de caracteres,
 estructuras, etc. */
typedef int TNodoGrafo;

/*Definimos el tipo de dato que representará la lista de aristas. */
struct SNodoArista {
    TNodoGrafo ValorNodo;
    double Peso;
    struct SNodoArista *ptrSigArista;
};
typedef struct SNodoArista TNodoArista;
/*Definimos el tipo de dato que representará la lista de vertices. */
struct SNodoVertice {
    TNodoGrafo ValorNodo;
    TNodoArista *ptrListaArista;
    struct SNodoVertice *ptrSigVertice;
};

typedef struct SNodoVertice TNodoVertice;

/*prototipos*/
TNodoVertice *CreaGrafo();
void LiberaAristas(TNodoArista *ptrListaAristas);
void LiberaGrafo(TNodoVertice * ptrListaVertices);
TNodoVertice *ExisteVertice(TNodoVertice *ptrListaVertices, TNodoGrafo ValorNodo);
TNodoVertice *InsertaVertice(TNodoVertice *ptrListaVertices, TNodoGrafo ValorNodo);
void InsertaArista(TNodoVertice *ptrListaVertices, TNodoGrafo Vertice1, TNodoGrafo Vertice2, double Peso);
TNodoArista *ExisteArista(TNodoVertice *ptrNodoVertice1, TNodoGrafo Vertice2);
int ExistenAristas(TNodoVertice *ptrListaVertices);
void ImprimeGrafo(TNodoVertice *ptrListaVertices);
void ImprimeAristas(TNodoArista *ptrListaArista);

#endif /* GRAFO_H */

