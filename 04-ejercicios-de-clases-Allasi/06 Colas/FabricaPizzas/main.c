/* 
 * File:   main.c
 * Author: Danie
 *
 * Created on 21 de agosto de 2022, 22:27
 */

#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
#include "funciones.h"

int main(int argc, char** argv) {
    int n = 7;
    
    int arr1[] = {1,1,1,0,0,0,0};
    int prod1[] = {2,1,3,2,3,1,1};
    
    int arr2[] = {1,1,1,1,1,1,0};
    int prod2[] = {1,2,3,3,3,2,1};
    
    int arr3[] = {1,1,1,1,1,0,0};
    int prod3[] = {1,2,1,1,3,1,2};
    
    int arr4[] = {0,0,1,1,1,1,1};
    int prod4[] = {3,1,3,2,3,3,1};
    
    Lista list1, list2, list3, list4;
    
    cargaLista(arr1, prod1, &list1, n);
    imprime(list1);
    
    return (EXIT_SUCCESS);
}

