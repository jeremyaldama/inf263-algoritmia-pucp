/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 30 de mayo de 2023, 18:56
 */

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct nodo{
    struct nodo *i;
    int bit;
    int elemento;
    struct nodo *d;
} Nodo;

typedef Nodo* ABB;

void CreaNodo(int bin, int el, ABB&a){
    a = new Nodo;
    a->bit = bin;
    a->elemento = el;
    a->i = a->d = nullptr;
}

void CrearCombinaciones(int*arreglo, int ini, int n, ABB&ai, ABB&ad) {
    if (n == ini) return;
    CreaNodo(0, arreglo[ini], ai);
    CreaNodo(1, arreglo[ini], ad);
    
    CrearCombinaciones(arreglo, ini+1, n, ai->i, ai->d);
    CrearCombinaciones(arreglo, ini+1, n, ad->i, ad->d);
}

void GenerarArbol(int*arreglo, int n, ABB &arbol) {
    arbol = new Nodo;
    arbol->bit = 0;
    arbol->elemento = 0;
    arbol->i = arbol->d = nullptr;
    
    CrearCombinaciones(arreglo, 0, n, arbol->i, arbol->d);
}

int cantidad = 0;

void CalcularCombinacionesPosibles(ABB&arbol, int target, int suma) {
    if (arbol->bit == 1) {
        suma += (arbol->elemento);
    }
    if (arbol->i == nullptr && arbol->d == nullptr) {
        cout << suma << endl;
        if (suma == target) {
            cantidad++;
        }
        return;
    }
    CalcularCombinacionesPosibles(arbol->i, target, suma);
    CalcularCombinacionesPosibles(arbol->d, target, suma);
}

void ImprimirArbol(ABB &arbol) {
    if (arbol == nullptr) return;
    ImprimirArbol(arbol->i);
    cout << "NODO: " << arbol->bit << " " << arbol->elemento << endl;
    ImprimirArbol(arbol->d);
}

int main(int argc, char** argv) {
    // a)
    int arreglo[] = {10, 50};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    ABB arbol;
    GenerarArbol(arreglo, n, arbol);
    
    // b)
    int pesos[] = {10, 50, 20, 30, 40};
    int target = 70, num = sizeof(pesos)/sizeof(pesos[0]), suma = 0;
    ABB arbolPesos;
    GenerarArbol(pesos, num, arbolPesos);
    CalcularCombinacionesPosibles(arbolPesos, target, suma);
    cout << "LA CANTIDAD DE POSIBLES COMBINACIONES ES: " << cantidad << endl;
    
//    ImprimirArbol(arbolPesos);
    return 0;
}

