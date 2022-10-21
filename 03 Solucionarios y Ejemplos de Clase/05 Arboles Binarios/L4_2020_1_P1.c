#include <stdio.h>
#include <stdlib.h>

// 20180146

typedef int TInfo;

typedef struct Nodo {
	TInfo cod;
	TInfo dia;
	TInfo ini;
	TInfo fin;
	// estados : 1 = a tiempo  2 = retraso  3 = no llego
	TInfo estado; 
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
		ptrNuevo->estado = 0; // valor por defecto para inicializar mis estados de cada cita;
		ptrNuevo->izq = ptrNuevo->der = NULL;
		(*Arbol) = ptrNuevo;
	} else {
		if ((*Arbol)->dia > dia || (*Arbol)->dia == dia && (*Arbol)->ini > ini) insertarRec(&((*Arbol)->izq),cod,dia,ini,fin);
		else insertarRec(&((*Arbol)->der),cod,dia,ini,fin);
	}
}

int busca_cruce(TArbol Arbol, TInfo cod, TInfo dia, TInfo ini, TInfo fin) {
	if (Arbol == NULL) return 0;
	else {
		if (Arbol->dia == dia && Arbol->ini == ini && Arbol->fin == fin) {
			printf("Hay cruce de horario de cita entre: %d %d %d %d y ",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
			return 1;
		} else {
			if ((Arbol->dia == dia && Arbol->ini <= ini && Arbol->fin > ini) ||
				(Arbol->dia == dia && Arbol->ini < fin && Arbol->fin >= fin)) {
				printf("Hay cruce de horario de cita entre: %d %d %d %d y ",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
				return 1;	
			}
			if (Arbol->dia > dia || Arbol->dia == dia && Arbol->ini > ini) Arbol = Arbol->izq;
			else Arbol = Arbol->der;
			return(busca_cruce(Arbol,cod,dia,ini,fin));
		}
	}
}

int esta(TArbol Arbol, TInfo dia, TInfo ini) {
	TNodo *aux;
	aux = Arbol;
	while (aux != NULL) {
		if (aux->dia == dia && aux->ini == ini) 
			return 1;
		else if (dia < aux->dia || dia == aux->dia && ini < aux->ini) aux = aux->izq;
		else aux = aux->der;
	}
	return 0;
}

void actualizar_estado(TArbol *Arbol,TInfo dia, TInfo ini, TInfo estado) {
	TNodo *aux;
	aux = *Arbol;
	while (aux != NULL) {
		if (aux->dia == dia && aux->ini == ini) {
			aux->estado = estado;
			return;
		}
		else if (dia < aux->dia || dia == aux->dia && ini < aux->ini) aux = aux->izq;
		else aux = aux->der;
	}
}

void en_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		en_orden(Arbol->izq);
		printf("%10d       %02d       %02d         %02d",Arbol->cod,Arbol->dia,Arbol->ini,
		Arbol->fin);
		if (Arbol->estado == 1) printf("     A tiempo\n");
		else if (Arbol->estado == 2) printf("     retraso\n");
		else if (Arbol->estado == 3) printf("     no llego\n");
		else printf("        %02d\n",Arbol->estado);
		en_orden(Arbol->der);		
	}
}

// nota: inclui un campo fin que seria un ini + 1 puesto que se indica que la cita
// dura una hora (innecesario en realidad pero por cuestion de orden lo inclui)

int main () {
	FILE *arch;
	arch = fopen("datos3.txt","r");
	TArbol Horario;
	crearArbol(&Horario);
	int cod, dia, ini, fin;
	// verificamos si hay cruce de citas en el arbol y si no hay
	// insertamos, y si hay imprimimos los horarios de cita que se cruzan
	while (1) {
		fscanf(arch,"%d %d %d %d",&cod,&dia,&ini,&fin);
		if (feof(arch)) break;
		int hay_cruce = busca_cruce(Horario,cod,dia,ini,fin);
		if (hay_cruce) printf("%d %d %d %d\n",cod,dia,ini,fin);
		else insertarRec(&Horario,cod,dia,ini,fin);
	}
	fclose(arch);
	printf("\nCod. Paciente   Dia    Hora ini.  Hora fin   Estado\n");
	printf("===================================================\n");
	en_orden(Horario);
	printf("\nDia sabado ... Actualizando estados de citas...\n");
	FILE *archAux;
	archAux = fopen("datos4.txt","r");
	int estado;
	// leemos un archivo en el que se encuentran cada cita con los estados actualizados
	while (1) {
		fscanf(archAux,"%d %d %d",&dia,&ini,&estado);
		if (feof(archAux)) break;
		// si la cita existe (dia y hora ini) entonces actualizamos el estado
		if (esta(Horario,dia,ini)) actualizar_estado(&Horario,dia,ini,estado);
	}
	fclose(archAux);
	printf("\nCod. Paciente   Dia    Hora ini.  Hora fin   Estado\n");
	printf("===================================================\n");
	en_orden(Horario);
	return 0;
}
