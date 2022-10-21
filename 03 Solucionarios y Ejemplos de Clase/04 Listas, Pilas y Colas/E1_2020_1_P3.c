#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
	int hora;
	char dia[20];
	struct Nodo* sig;
} TNodo;

typedef TNodo* TLista;

void crear_lista(TLista* L, TLista* F){
	*L = NULL;
	*F = NULL;
}

int listaVacia(TLista* L){
	if(*L == NULL)
		return 1;
	return 0;
}

void insertarFinal(TLista* L, TLista* F, int hora, char dia[20]){
	TNodo* nuevo = (TNodo*)malloc(sizeof(TNodo));
	nuevo->hora = hora;
	nuevo->sig = NULL;
	strcpy(nuevo->dia, dia);

	if(listaVacia(L)){
		*L = nuevo;
		*F = nuevo;
	}else{
		(*F)->sig = nuevo;
		*F = nuevo;
	}
}

void imprimir_lista(TLista L){
	if(L == NULL)
		return;

	printf("%d (%s)->", L->hora, L->dia);
	imprimir_lista(L->sig);
}

void finalizar_lista(TLista* L){
	while(*L != NULL){
		TLista aux = *L;
		*L = (*L)->sig;
		free(aux);
	}
}

void fusionar(TLista* L1_ini, TLista* L1_fin, TLista* L2_ini, TLista* L2_fin){
	if((*L1_fin)->hora < (*L2_ini)->hora){ //L1 contiene solo elementos menores a L2
		(*L1_fin)->sig = *L2_ini;
		*L1_fin = *L2_fin;
	}else if((*L2_fin)->hora < (*L1_ini)->hora){ //L2 contiene solo elementos menores a L1
		(*L2_fin)->sig = *L1_ini;
		*L1_ini = *L2_ini;
	}else{ //Hay que fusionar
		TLista F_ini, F_fin;
		F_ini = F_fin = NULL; 

		while((*L1_ini)!=NULL && (*L2_ini)!=NULL){
			if((*L1_ini)->hora <= (*L2_ini)->hora){ //Pasa L1
				if(F_ini==NULL){
					F_ini = *L1_ini;
					F_fin = *L1_ini;
				}else{
					F_fin->sig = *L1_ini;
					F_fin = *L1_ini;
				}
				*L1_ini = (*L1_ini)->sig;
			}else if((*L1_ini)->hora > (*L2_ini)->hora){
				if(F_ini==NULL){
					F_ini = *L2_ini;
					F_fin = *L2_ini;
				}else{
					F_fin->sig = *L2_ini;
					F_fin = *L2_ini;
				}
				*L2_ini = (*L2_ini)->sig;
			}
		}

		//Puede ser que alguna lista aun tenga elementos, repasamos ambas
		while((*L1_ini)!=NULL){
			if(F_ini==NULL){
					F_ini = *L1_ini;
					F_fin = *L1_ini;
				}else{
					F_fin->sig = *L1_ini;
					F_fin = *L1_ini;
				}
			*L1_ini = (*L1_ini)->sig;
		}

		while((*L2_ini)!=NULL){
			if(F_ini==NULL){
					F_ini = *L2_ini;
					F_fin = *L2_ini;
				}else{
					F_fin->sig = *L2_ini;
					F_fin = *L2_ini;
				}
				*L2_ini = (*L2_ini)->sig;
		}

		*L1_ini = F_ini;
		*L1_fin = F_fin;
	}
}

int main(){
	TLista LunesIni, LunesFin;
	TLista MartesIni, MartesFin;
	TLista MiercolesIni, MiercolesFin;
	TLista JuevesIni, JuevesFin;
	TLista ViernesIni, ViernesFin;

	crear_lista(&LunesIni, &LunesFin);
	crear_lista(&MartesIni, &MartesFin);
	crear_lista(&MiercolesIni, &MiercolesFin);
	crear_lista(&JuevesIni, &JuevesFin);
	crear_lista(&ViernesIni, &ViernesFin);

	int numLunes, numMartes, numMiercoles, numJueves, numViernes;
	
	printf("Ingrese el numero de datos de Lunes:");
	scanf("%d", &numLunes);

	printf("ingrese las horas de Lunes:");
	for(int i = 0; i < numLunes; i++){
		int hora;
		scanf("%d", &hora);
		insertarFinal(&LunesIni, &LunesFin, hora, "Lunes");
	}

	printf("Ingrese el numero de datos de Martes:");
	scanf("%d", &numMartes);
	printf("ingrese las horas de Martes:");
	for(int i = 0; i < numMartes; i++){
		int hora;
		scanf("%d", &hora);
		insertarFinal(&MartesIni, &MartesFin, hora, "Martes");
	}

	printf("Ingrese el numero de datos de Miercoles:");
	scanf("%d", &numMiercoles);
	printf("ingrese las horas de Miercoles:");
	for(int i = 0; i < numMiercoles; i++){
		int hora;
		scanf("%d", &hora);
		insertarFinal(&MiercolesIni, &MiercolesFin, hora, "Miercoles");
	}

	printf("Ingrese el numero de datos de Jueves:");
	scanf("%d", &numJueves);
	printf("ingrese las horas de Jueves:");
	for(int i = 0; i < numJueves; i++){
		int hora;
		scanf("%d", &hora);
		insertarFinal(&JuevesIni, &JuevesFin, hora, "Jueves");
	}

	printf("Ingrese el numero de datos de Viernes:");
	scanf("%d", &numViernes);
	printf("ingrese las horas de Viernes:");
	for(int i = 0; i < numViernes; i++){
		int hora;
		scanf("%d", &hora);
		insertarFinal(&ViernesIni, &ViernesFin, hora, "Viernes");
	}

	fusionar(&LunesIni, &LunesFin, &MartesIni, &MartesFin);
	fusionar(&LunesIni, &LunesFin, &MiercolesIni, &MiercolesFin);
	fusionar(&LunesIni, &LunesFin, &JuevesIni, &JuevesFin);
	fusionar(&LunesIni, &LunesFin, &ViernesIni, &ViernesFin);

	imprimir_lista(LunesIni);
	finalizar_lista(&LunesIni);



}