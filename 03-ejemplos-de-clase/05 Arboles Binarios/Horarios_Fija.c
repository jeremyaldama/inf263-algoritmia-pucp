#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

// 20180146

typedef int TInfo;

typedef struct Nodo {
	TInfo cod;
	TInfo dia;
	TInfo ini;
	TInfo fin;
	struct Nodo *izq;
	struct Nodo *der;
} TNodo;

typedef TNodo *TArbol;

void crearArbol(TArbol *Arbol) {
	(*Arbol) = NULL;
}

void insertarRec(TArbol *Arbol, TInfo cod, TInfo dia, TInfo ini, TInfo fin) {	
	if ((*Arbol) == NULL) {
		TNodo *ptrNuevo = (TNodo *)malloc(sizeof(TNodo));
		ptrNuevo->cod = cod;
		ptrNuevo->dia = dia;
		ptrNuevo->ini = ini;
		ptrNuevo->fin = fin;
		ptrNuevo->izq = ptrNuevo->der = NULL;
		(*Arbol) = ptrNuevo;
	} else {
		if ((*Arbol)->dia > dia || (*Arbol)->dia == dia && (*Arbol)->ini > ini) insertarRec(&((*Arbol)->izq),cod,dia,ini,fin);
		else insertarRec(&((*Arbol)->der),cod,dia,ini,fin);
	}
}

void en_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		en_orden(Arbol->izq);
		printf("%10d       %02d       %02d         %02d\n",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
		en_orden(Arbol->der);		
	}
}

int busca_cruce(TArbol Arbol, TInfo cod, TInfo dia, TInfo ini, TInfo fin) {
	if (Arbol == NULL) return 0;
	else {
		if (Arbol->dia == dia && Arbol->ini == ini && Arbol->fin == fin) {
			//printf("Hay cruce de horarios entre: %d %d %d %d y ",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
			return 1;
		} else {
			if ((Arbol->dia == dia && Arbol->ini <= ini && Arbol->fin > ini) ||
				(Arbol->dia == dia && Arbol->ini < fin && Arbol->fin >= fin)) {
				//printf("Hay cruce de horarios entre: %d %d %d %d y ",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
				return 1;	
			}
			if (Arbol->dia > dia || Arbol->dia == dia && Arbol->ini > ini) Arbol = Arbol->izq;
			else Arbol = Arbol->der;
			return(busca_cruce(Arbol,cod,dia,ini,fin));
		}
	}
}

TArbol buscaMenor(TArbol Arbol){
    if(Arbol == NULL) return NULL;
    else {
        if(Arbol->izq != NULL) return(buscaMenor(Arbol->izq));
        else return(Arbol);
    }     
}


TArbol borraNodo(TArbol Arbol, TInfo cod, TInfo dia, TInfo ini, TInfo fin) {
	if (Arbol == NULL) return Arbol;
	if (dia < Arbol->dia || Arbol->dia == dia && ini < Arbol->ini) Arbol->izq = borraNodo(Arbol->izq,cod,dia,ini,fin);
	else {
		if (dia > Arbol->dia || Arbol->dia == dia && ini > Arbol->ini) Arbol->der = borraNodo(Arbol->der,cod,dia,ini,fin);
		else {
			if (Arbol->izq == NULL) {
				TArbol temp = Arbol->der;
				free(Arbol);
				return temp;
			} else if (Arbol->der == NULL) {
				TArbol temp = Arbol->izq;
				free(Arbol);
				return temp;
			}
			TArbol temp = buscaMenor(Arbol->der);
			Arbol->cod = temp->cod;
			Arbol->dia = temp->dia;
			Arbol->ini = temp->ini;
			Arbol->fin = temp->fin;
			Arbol->der = borraNodo(Arbol->der,temp->cod,temp->dia,temp->ini,temp->fin);
		}
	}
	return Arbol;
}

// funcion que busca el k-esimo nodo menor de un arbol

TArbol kthminNode(TArbol Arbol, TInfo k, TInfo *i) {
	if (Arbol == NULL) return NULL;
	TNodo *ptrAux = kthminNode(Arbol->izq,k,i);
	if (ptrAux != NULL) return ptrAux;
	(*i)++;
	if((*i) == k) return Arbol;
	return kthminNode(Arbol->der,k,i);
	
}

void juntarHorarios(TArbol *Arbol1, TArbol *Arbol2) {	
	TNodo *aux, *temp;
	aux = *Arbol2;
	int k = 1;
	while (1) {
		int i = 0;
		temp = kthminNode(aux,k,&i);
		if (temp == NULL) break;
		if (busca_cruce(*Arbol1,temp->cod,temp->dia,temp->ini,temp->fin)) {
			k++;
		} else {
			insertarRec(Arbol1,temp->cod,temp->dia,temp->ini,temp->fin);
			aux = borraNodo(aux,temp->cod,temp->dia,temp->ini,temp->fin);
		}
	}
}

void main () {
	printf("\n                HORARIOS 2020\n\n");
	FILE *arch1, *arch2;
	arch1 = fopen("horario1.txt","r");
	arch2 = fopen("horario2.txt","r");
	TArbol Horario1, Horario2;
	crearArbol(&Horario1);
	crearArbol(&Horario2);
	int cod, dia, ini, fin, codigo;
	while (1) {
		fscanf(arch1,"%d %d %d %d",&cod,&dia,&ini,&fin);
		if(feof(arch1)) break;
		insertarRec(&Horario1,cod,dia,ini,fin);
	}
	fclose(arch1);
	while (1) {
		fscanf(arch2,"%d %d %d %d",&cod,&dia,&ini,&fin);
		if(feof(arch2)) break;
		insertarRec(&Horario2,cod,dia,ini,fin);
	}
	fclose(arch2);
	printf("\nCod. Docente    Dia    Hora ini.  Hora fin\n");
	printf("===================================================\n");
	en_orden(Horario1);
	printf("\nCod. Docente    Dia    Hora ini.  Hora fin\n");
	printf("===================================================\n");
	en_orden(Horario2);
	juntarHorarios(&Horario1,&Horario2);
	printf("\n\n           HORARIO FINAL 2020\n\n");
	printf("\nCod. Docente    Dia    Hora ini.  Hora fin\n");
	printf("===================================================\n");
	en_orden(Horario1);
	printf("\nCod. Docente    Dia    Hora ini.  Hora fin\n");
	printf("===================================================\n");
	en_orden(Horario2);
}
