#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
#include "funciones.h"

void cargaLista(int*arr, int*prod, Lista*list, int n){
    construir_lista(list);
    
    for (int i=0; i<n; i++) if (arr[i]) insertar_al_final(list, prod[i]);
    
}
