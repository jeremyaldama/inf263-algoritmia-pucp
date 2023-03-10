#include <stdio.h>
#include <stdlib.h>

/*Esta función busca en el arreglo A, entre las posiciones "ini" y "fin",
    el último elemento que no sea mayor a "val"

    Retorna la posición del elemento que cumple con la condición.
*/
int busqueda_binaria(int A[], int ini, int fin, int val){
    if(ini == fin){
        return ini;
    }

    int med = (ini + fin)/2;

    if(A[med] == val)
        return med;
    if(A[med] < val){
        if((med + 1) <= fin){
            if(A[med + 1] > val)
                return med;
            else
                return busqueda_binaria(A, med+1, fin, val);
        }else
            return busqueda_binaria(A, med+1, fin, val);
    }else if(A[med] > val){
        return busqueda_binaria(A, ini, med-1, val);
    }
}

/*
    La idea de emplear búsqueda binaria para este problema es que, para cada elemento en A,
    podemos encontrar el máximo elemento posible tal que la diferencia no sobrepase d.

    El número de tripletas que contienen al elemento analizado y el máximo posible según la condición
    puede calcularse entonces en O(1)

    El algoritmo tiene una complejidad total de O(n log n)

*/
long long count_triplets(int A[], int n, int d){
    int i;
    long long cont = 0;

    for(i = 0; i < n; i++){ //Para cada elemento del arreglo
        int j = busqueda_binaria(A, i, n-1, A[i] + d); //Busco el elemento que no sobrepase A[i] + d
        if(i != j) //Si existe un elemento máximo
            cont += ((j - i)*(j - i - 1))/2; //Sumamos todas las tripletas que pueden obtenerse entre i y j
            //Combinatoria de (j-i) elementos en grupos de 3
    }

    return cont;
}

int main(int argc, char* argv[]){
    int n,d;
    int A[100001];

    scanf("%d", &n);
    scanf("%d", &d);

    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    long long count = count_triplets(A, n, d);
    printf("%I64d\n", count);
    return 0;
}
