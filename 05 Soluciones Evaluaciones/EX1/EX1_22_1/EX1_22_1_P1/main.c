#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pila.h"
#define MAX_FECHAS 100
#define MAX 

ElementoPila leerProducto(FILE*arch){
    ElementoPila aux;
    fscanf(arch, "%d %d", &aux.id, &aux.fechaCad);
    return aux;
}

Pila obtenerProductos(int*canProd, int*capacidadCaja){
    Pila aux;
    construirPila(&aux);
    FILE*arch = fopen("productos.txt","r");
    fscanf(arch, "%d %d", canProd, capacidadCaja);
    while (1){
        ElementoPila prod = leerProducto(arch);
        if (feof(arch)) break;
        //printf("%d \n", prod.fechaCad);
        apilar(&aux, prod);
    }
    fclose(arch);
    return aux;
}

void merge(int A[],int ini,int med, int fin){
	int t1,t2,i,p,q;
	
	t1=med-ini+1;
	t2=fin-med;
	
	int P[t1+1];
	int Q[t2+1];
	
	for(i=ini;i<=med;i++)
		P[i-ini]=A[i];
	
	for(i=med+1;i<=fin;i++)
		Q[i-(med+1)]=A[i];
	
	P[t1]=9999999;Q[t2]=9999999;
	p=q=0;
	for(i=ini;i<=fin;i++)
		if(P[p]<Q[q])
			A[i] = P[p++];
		else
			A[i] = Q[q++];
	
}

void mergesort(int A[],int ini, int fin){
	if(ini==fin)
		return;
	int med = (ini+fin)/2;
	mergesort(A,ini,med);	
	mergesort(A,med+1,fin);
	merge(A,ini,med,fin);
}

void hanoi(int i, Pila*pilaCaja, Pila*pilaCajaAux, Pila*pilaCajaDes){
    if (i==0) return;
    hanoi(i-1, pilaCaja, pilaCajaDes,pilaCajaAux);
    ElementoPila ele = desapilar(pilaCaja);
    apilar(pilaCajaDes, ele);
    hanoi(i-1, pilaCajaAux, pilaCaja, pilaCajaDes);
}

void separarCajas(int i, ElementoPila ele, Pila*pilaCaja,
                    int capacidad){
    if (pilaCaja[0].can<capacidad){
        
    }
    else if (pilaCaja[1].can<capacidad){
        hanoi(i, &pilaCaja[1], &pilaCaja[2], &pilaCaja[3]);
        apilar(&pilaCaja[1], ele);
        hanoi(i, &pilaCaja[3], &pilaCaja[2], &pilaCaja[1]);
    }
}

void apilarEnCajas(Pila *pilaCaja,Pila *pilaContenedor, int capacidad){
    int fechas[MAX_FECHAS];
    int numFechas=0, i;
    while (pilaContenedor->cabeza){
        ElementoPila elem = desapilar(pilaContenedor);
        printf("fecha desapil: %d\n",elem.fechaCad);
        for (i=0; i<numFechas; i++){
            if (elem.fechaCad<fechas[i]) break;
        }
        //separarCajas(i, elem, pilaCaja, capacidad);
        hanoi(i, &pilaCaja[0], &pilaCaja[1], &pilaCaja[2]);
        apilar(&pilaCaja[0], elem);
        hanoi(i, &pilaCaja[2], &pilaCaja[1], &pilaCaja[0]);
        
        fechas[numFechas] = elem.fechaCad;
        mergesort(fechas, 0, numFechas);
        numFechas++;
    }
}

int main(){
    int cantidadProd, capacidadCaja;
    Pila pilaContenedor = obtenerProductos
                            (&cantidadProd,&capacidadCaja);
    int cantidadCajasPeq = (int)ceil(cantidadProd/capacidadCaja);

    Pila *pilaCaja = (Pila*)malloc(sizeof(Pila)*cantidadCajasPeq);
    int i=0;

    for (i=0; i<cantidadCajasPeq; i++){
        construirPila(&pilaCaja[i]);
    }
    
    apilarEnCajas(pilaCaja, &pilaContenedor, capacidadCaja);
    Mostrar(pilaCaja[0]);
    Mostrar(pilaCaja[1]);
    Mostrar(pilaCaja[2]);
    Mostrar(pilaCaja[3]);
    return 0;
}