#include <stdio.h>
#include <stdlib.h>

// 20180146

typedef struct NodoColaCaja {
	int real;
	int teorico;
	struct NodoColaCaja *next;
} TNodoColaCaja;

typedef TNodoColaCaja *TColaCaja;

typedef struct NodoPilaProd {
	int real;
	int teorico;
	struct NodoPilaProd *next;
} TNodoPilaProd;

typedef TNodoPilaProd *TPilaProd;

void crearPila(TPilaProd *PilaProd) {
	(*PilaProd) = NULL;
}

void crearCola(TColaCaja *ColaCaja) {
	(*ColaCaja) = NULL;
}

void apilar(TPilaProd *PilaProd, int real,int teorico ) {
    TNodoPilaProd *Aux;  
    Aux = (TNodoPilaProd *)malloc(sizeof(TNodoPilaProd));
    Aux->real = real;
    Aux->teorico = teorico;
	Aux->next= (*PilaProd);
   	(*PilaProd) = Aux;   
}

int es_pila_vacia(TPilaProd *PilaProd) {
    return (*PilaProd) == NULL;
}

/*void cima(TPilaProd *PilaProd) {
	TNodoPilaProd *Aux;   
    Aux = (*PilaProd);
    if (es_pila_vacia(ptrPila))
        printf("Pila vacia\n");
    else
        printf("%d %d\n",ptrrec->real,ptrrec->teorico);

}*/

void desapilar(TPilaProd *PilaProd,int *real, int *teorico) {    
    TNodoPilaProd *Aux;
    int valor;  
    if (!es_pila_vacia(PilaProd)) { 
        Aux = (*PilaProd);
        (*real) = Aux->real; 
        (*teorico) = Aux->teorico; 
		(*PilaProd) = Aux->next; 
        free(Aux);
    }    
}

int es_cola_vacia(TColaCaja ColaCaja){
    return ColaCaja == NULL;
}

void encolar(TColaCaja *ColaCaja, int real,int teorico){
    TNodoColaCaja *Aux = (TNodoColaCaja*)malloc(sizeof(TNodoColaCaja));
    Aux->real = real;
    Aux->teorico = teorico;
    Aux->next = (*ColaCaja);
    (*ColaCaja) = Aux; 
}

void desencolar(TColaCaja *ColaCaja, int *real, int *teorico) {
    TNodoColaCaja *Aux, *Ult;
    if (!es_cola_vacia(*ColaCaja)) {
        Ult = NULL;
        Aux = (*ColaCaja);
        while (Aux->next) {
			Ult = Aux;
            Aux = Aux->next;
        }
        if (Ult == NULL) (*ColaCaja) = NULL;
        else Ult->next = NULL; 
        (*real) = Aux->real;
        (*teorico) = Aux->teorico;
		free(Aux);       
    }   
}

void clasificarFaja(TColaCaja *ColaCaja, TPilaProd *PilaProdC, TPilaProd *PilaProdD, TPilaProd *PilaProdE, int cant) {
	int cont = 0, quita = 0; 
	int real, teorico;
	while (!es_cola_vacia(*ColaCaja) && cont < cant) {
		desencolar(ColaCaja,&real,&teorico);
		if (real == teorico) {
			apilar(PilaProdC,real,teorico);
			quita++;
		} else encolar(ColaCaja,real,teorico);
		cont++;		
	}
	cont = 0;
	while (!es_cola_vacia(*ColaCaja) && cont < cant-quita) {
		desencolar(ColaCaja,&real,&teorico);
		if (real > teorico) {
			apilar(PilaProdE,real,teorico);
			quita++;
		} else encolar(ColaCaja,real,teorico);
		cont++;
	}
	cont = 0;
	while (!es_cola_vacia(*ColaCaja) && cont < cant-quita) {
		desencolar(ColaCaja,&real,&teorico);
		if (real < teorico) {
			apilar(PilaProdD,real,teorico);
			quita++;
		} else encolar(ColaCaja,real,teorico);
		cont++;
	}
}

void imprimePila(TPilaProd PilaProd) {
	TPilaProd  Aux;   
    if (PilaProd == NULL) return;  	
	Aux = PilaProd;
	PilaProd = PilaProd->next;
	imprimePila(PilaProd);
	printf("%d  %d ",Aux->real,Aux->teorico);
}

int main () {
	TColaCaja ColaCaja;
	TPilaProd PilaProdC, PilaProdD, PilaProdE;
	int cant = 7;
	crearPila(&PilaProdC);
	crearPila(&PilaProdD);
	crearPila(&PilaProdE);
	crearCola(&ColaCaja);
	encolar(&ColaCaja, 15,15);
    encolar(&ColaCaja, 10,15);
    encolar(&ColaCaja, 17,15);
    encolar(&ColaCaja, 16,15);
    encolar(&ColaCaja, 16,16); 
    encolar(&ColaCaja, 18,18);
    encolar(&ColaCaja, 19,18);
    clasificarFaja(&ColaCaja,&PilaProdC,&PilaProdD,&PilaProdE,cant);
    imprimePila(PilaProdC);
    printf("\n");
    imprimePila(PilaProdD);
    printf("\n");
    imprimePila(PilaProdE);
	return 0;
}
