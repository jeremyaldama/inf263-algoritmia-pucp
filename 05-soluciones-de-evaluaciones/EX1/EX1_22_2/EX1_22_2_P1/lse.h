#ifndef LSE_H
#define LSE_H

typedef int Elemento;

typedef struct nodo{
    Elemento elemento;    
    struct nodo *sig;
} Nodo;

typedef struct{
    Nodo *cabeza;
    int longitud;
}Lista;

void construir(Lista *);
void insertar_inicio(Lista *,Elemento );
void imprimir(Lista );
void insertar_orden(Lista *,Elemento );
void insertar_final(Lista *,Elemento );
Nodo *crear_nodo(Elemento );
Nodo *busca_nodo(Lista tad,Elemento dato);
void destruir(Lista *);
void Elimina_nodo(Lista *,Elemento );
int es_lista_vacia(Lista );
Elemento retorna_cabeza(Lista tad);
void elimina_cabeza(Lista *tad);

#endif
