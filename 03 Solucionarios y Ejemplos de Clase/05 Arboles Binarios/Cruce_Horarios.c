#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

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

int busca_cruce(TArbol Arbol, TInfo cod, TInfo dia, TInfo ini, TInfo fin) {
	if (Arbol == NULL) return 0;
	else {
		if (Arbol->dia == dia && Arbol->ini == ini && Arbol->fin == fin) {
			printf("Hay cruce de horarios entre: %d %d %d %d y ",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
			return 1;
		} else {
			if ((Arbol->dia == dia && Arbol->ini <= ini && Arbol->fin > ini) ||
				(Arbol->dia == dia && Arbol->ini < fin && Arbol->fin >= fin)) {
				printf("Hay cruce de horarios entre: %d %d %d %d y ",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
				return 1;	
			}
			if (Arbol->dia > dia || Arbol->dia == dia && Arbol->ini > ini) Arbol = Arbol->izq;
			else Arbol = Arbol->der;
			return(busca_cruce(Arbol,cod,dia,ini,fin));
		}
	}
}

void en_orden(TArbol Arbol) {
	if (Arbol != NULL) {
		en_orden(Arbol->izq);
		printf("%10d       %02d       %02d         %02d\n",Arbol->cod,Arbol->dia,Arbol->ini,Arbol->fin);
		en_orden(Arbol->der);		
	}
}

void horario_docente(TArbol Arbol, TInfo codigo) {
	if (Arbol != NULL) {
		horario_docente(Arbol->izq,codigo);
		if (Arbol->cod == codigo) printf("  %02d       %02d         %02d\n",Arbol->dia,Arbol->ini,Arbol->fin);
		horario_docente(Arbol->der,codigo);		
	} 
}

void main () {
	printf("Ingreso de Horarios para su respectiva evaluacion...\n\n");
	FILE *arch;
	arch = fopen("datos.txt","r");
	TArbol Horarios;
	crearArbol(&Horarios);
	int cod, dia, ini, fin, codigo;
	while (1) {
		fscanf(arch,"%d %d %d %d",&cod,&dia,&ini,&fin);
		if(feof(arch)) break;
		int hay_cruce = busca_cruce(Horarios,cod,dia,ini,fin);
		if(hay_cruce) printf("%d %d %d %d\n",cod,dia,ini,fin);
		else insertarRec(&Horarios,cod,dia,ini,fin);
	}
	printf("\nCod. Docente    Dia    Hora ini.  Hora fin\n");
	printf("===================================================\n");
	en_orden(Horarios);
	printf("===================================================\n");
	printf("\nIngrese el codigo de docente a buscar: ");
	scanf("%d",&codigo);
	printf("\n Dia     Hora ini.  Hora fin\n");
	printf("==============================\n");
	horario_docente(Horarios,codigo);
	fclose(arch);
}
