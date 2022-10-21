/* 
 * File:   funcAux.h
 * Author: Danie
 *
 * Created on 14 de octubre de 2022, 23:18
 */

#ifndef FUNCAUX_H
#define FUNCAUX_H
#include "cola.h"
#include "pila.h"

int ObtenerHash(int, int , int );
char ObtenerCalidad(int );
int ObtenerCodigo(int );
int ObtenerCantidad(int );
Cola obtenerProductos();
void mostrarCola( Cola );
Cola generarNuevaCola(Cola*productos);
void insertar_orden(Cola *tad,ElementoCola dato);
#endif /* FUNCAUX_H */

