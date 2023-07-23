
/* 
 * File:   main.c
 * Author: Gino
 *
 * Created on 12 de noviembre de 2021, 04:20 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"

/* Verifica si el arbol está balanceado*/
int esta_balanceado(TNodoArbol* nodo)
{
    int izq = altura(nodo->izq);
    int der = altura(nodo->der);
    if (izq > der)
        return ((izq - der) <= 1);
    return ((der - izq) <= 1);
}

/* Quita un nodo del lado que sea más alto y lo pone en el otro lado.
   Este proceso se repite hasta que las alturas sean iguales o
   la altura derecha sea uno más que la izquierda*/
void balancear_nodo(TArbol *arbol)
{
    int dif = altura((*arbol)->der) - altura((*arbol)->izq);
    while (dif != 0 && dif != 1)
    {
        TNodoArbol* aux = dif > 0 ? menor((*arbol)->der) : mayor((*arbol)->izq);

        int precio = aux->precio;
        char nombre = aux->nombre;

        *arbol = remover(*arbol, aux->precio);

        int precio_ = (*arbol)->precio;
        int nombre_ = (*arbol)->nombre;

        (*arbol)->precio = precio;
        (*arbol)->nombre = nombre;

        inserta_nodo(arbol, nombre_, precio_);

        dif = altura((*arbol)->der) - altura((*arbol)->izq);
    }
}
/* Balancea el arbol si no está balanceado.
   Luego balancea al hijo izqquierdo y derecho recursivamente*/
void balancear(TArbol *arbol)
{
    if (*arbol == NULL)
        return;
    
    if (!esta_balanceado(*arbol))
        balancear_nodo(arbol);
    
    balancear(&((*arbol)->izq));
    balancear(&((*arbol)->der));
}

/* Muestra en preorden los productos que tengan el precio
   menor o igual a precio. También se actualiza el contador*/
void pre_orden_filtrado(TArbol ptrArbol, int precio, int *cont)
{
    if (ptrArbol)
    {
        if (ptrArbol->precio <= precio)
        {
            printf("(%c - %d)  ", ptrArbol->nombre, ptrArbol->precio);
            (*cont)++;
        }
        pre_orden_filtrado(ptrArbol->izq, precio, cont);
        pre_orden_filtrado(ptrArbol->der, precio, cont);
    }
}

int main(int argc, char** argv)
{
    TArbol arbol = NULL;
    char nombre;
    int precio, cont = 0;
    
    while (1)
    {
        printf("Ingrese el nombre y precio (0 0 para terminar): ");

        scanf("%c %d", &nombre, &precio);
        if (precio == 0)
            break;
        inserta_nodo(&arbol, nombre, precio);
        scanf("%c", &nombre);
    }
    
    balancear(&arbol);
    
    printf("\nArbol balanceado en preorden:\n");
    pre_orden(arbol);
    
    printf("\n\nIngrese el precio a revisar: ");
    scanf("%d", &precio);
    
    pre_orden_filtrado(arbol, precio, &cont);
    printf("\n%d resultados encontrados\n", cont);

    return (EXIT_SUCCESS);
}

