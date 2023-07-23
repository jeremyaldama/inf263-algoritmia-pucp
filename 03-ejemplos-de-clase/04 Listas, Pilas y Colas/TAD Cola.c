#include <stdio.h>
#include <stdlib.h>

// 20180146

typedef struct NodoCola{
    int data;
    struct NodoCola *next;
} TNodoCola;

typedef TNodoCola *TCola;

void crearCola(TCola *Cola) {
	(*Cola) = NULL;
}

int esColaVacia(TCola Cola) {
	return Cola == NULL;
}

void encolar(TCola *Cola, int elem) {
	TNodoCola *nodoNuevo;
	nodoNuevo = (TNodoCola *)malloc(sizeof(TNodoCola));
	nodoNuevo->data = elem;
	nodoNuevo->next = (*Cola);
	(*Cola) = nodoNuevo;
}

int desencolar(TCola *Cola) {
	TNodoCola *Aux, *Ult;
	int elem;
	if (!esColaVacia(*Cola)) { 
		Ult = NULL;
		Aux = (*Cola);
		while (Aux->next) {
			Ult = Aux;
			Aux = Aux->next;
		}
		if (Ult == NULL) (*Cola) = NULL;
		else Ult->next = NULL;
		elem = Aux->data;
		free(Aux);
		return elem;
	}		
}

int tamanioCola(TCola Cola) { 
	TCola Aux;
	if (Cola == NULL) return 0;
	Aux = Cola;
	Cola = Cola->next;
	return (tamanioCola(Cola)+1);
}

void imprimirCola(TCola Cola) {
	while (Cola) {
		printf("%d\n",Cola->data);
		Cola = Cola->next;
	}
}










void ordColaRec(TCola*ptrcola,int n){
    int menor,i,aux;
    i=1;
    if(cola_vacia(*ptrcola)) return;
    menor=desencolar(ptrcola);
    while(i<n){
        aux=desencolar(ptrcola);
        if(aux<menor){
            encolar(ptrcola,menor);
            menor=aux;
        }
        else encolar(ptrcola,aux);
        i++;
    }
    ordColaRec(ptrcola,n-1);
    encolar(ptrcola,menor);
}






void ordenaPilaRec(Tpila *pila1,int n){
    int valor, max,aux;
    Tpila Pila2;
    Pila2= NULL;
    
   
    if(n==0)return;
    
        max=pop(pila1);
        n--;
        while(!pila_vacia(pila1) && n>0){
            valor = pop(pila1);
            if(max<valor){
                push(&Pila2,max);
                max=valor;
            }else
                push(&Pila2,valor);
            n--;
        }
        n=0;
        push(pila1,max);
        while(!pila_vacia(&Pila2)){
            aux=pop(&Pila2);
            push(pila1,aux);
            n++;
        }
    
    
    ordenaPilaRec(pila1,n);
}
