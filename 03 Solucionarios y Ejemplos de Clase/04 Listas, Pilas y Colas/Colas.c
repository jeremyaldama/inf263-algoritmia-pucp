#include <stdio.h>
#include <stdlib.h>

/*informacion que se almacenara en el nodo*/
typedef int TInfo;

/*definimos la estructura para representar a la Cola. La cola se representara
 como una lista simplemente enlazada, en donde cada nodo de la lista es un nodo 
 del arbol*/
typedef struct NodoCola{
    TInfo elem;
    struct NodoCola* sig;
} TNodoCola;

typedef TNodoCola* TCola;

/*prototipos para trabajar la cola*/
void crea_cola(TCola *ptrCola);
int cola_vacia(TCola ptrCola);
void encolar(TCola *ptrCola, int valor);
void inserta_nodo(TCola *ptrCola, TInfo elem);
TNodoCola* ingresa(TCola *ptrCola);
int desencolar(TCola *ptrCola);

void imprimecola(TCola ptrcola)
{
	while(ptrcola!=NULL){
		printf("%d ",ptrcola->elem);
		ptrcola=ptrcola->sig;
	}
	
	
}

/*implementacion de las funciones para la cola*/
void crea_cola(TCola *ptrCola){
    *ptrCola = NULL;
}

int cola_vacia(TCola ptrCola){
    return ptrCola==NULL;
}

/*encolar, se inserta un elemento al final de la cola. Se representa como una 
 insercion al inicio.*/
void encolar(TCola *ptrCola, int valor){
    TNodoCola *ptrNuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    ptrNuevo->elem=valor;
    ptrNuevo->sig=*ptrCola;
    *ptrCola=ptrNuevo; 
}

/*saco la cabeza de la cola. Se representa como una eliminacion del nodo final de 
 la lista.*/
int desencolar(TCola *ptrCola)
{   TNodoCola *ptrRecorrido, *ptrUltimo;
    int valor;    
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
void finalizar(TCola ptrCola){
    TNodoCola *ptrRec, *ptrLiberar;
    ptrRec = ptrCola;
    
    while (ptrRec){
        ptrLiberar = ptrRec;
        ptrRec = ptrRec->sig;
        free(ptrLiberar);
    }
}

int main() {
    TCola ptrCola;

    crea_cola(&ptrCola);
    encolar(&ptrCola, 15);
    encolar(&ptrCola, 10);
    encolar(&ptrCola, 17);
    encolar(&ptrCola, 16);
    encolar(&ptrCola, 13);
    imprimecola(ptrCola);
    printf("\n");
    encolar(&ptrCola, 18);
    encolar(&ptrCola, 19);
    imprimecola(ptrCola);
	printf("\n Desencolado:%d\n",desencolar(&ptrCola));
	imprimecola(ptrCola);
	finalizar(ptrCola);
    return (EXIT_SUCCESS);
}

