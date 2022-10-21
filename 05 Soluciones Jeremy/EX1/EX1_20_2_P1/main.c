/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 22:44
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcAux.h"

int main(int argc, char** argv) {
    Cola productos = obtenerProductos();
    mostrarCola(productos);
    
    Cola productosPorCodigo = generarNuevaCola(&productos);
    return (EXIT_SUCCESS);
}

