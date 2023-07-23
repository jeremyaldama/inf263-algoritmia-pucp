/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 26 de mayo de 2020, 02:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Colas.h"


void ordenacola(TCola *ptrcola,int n)
{	int menor,i,j,aux;
		
	j=n;	
	while(j>0)
	{	
		i=1;
		menor=desencolar(ptrcola);
		while(i<j)
		{	aux=desencolar(ptrcola);
			if(aux<menor)
			{
				encolar(ptrcola,menor);
				menor=aux;		
			}	
			else
				encolar(ptrcola,aux);
			i++;
		}
		for(i=j;i<n;i++)
		{
			aux=desencolar(ptrcola);		
			encolar(ptrcola,aux);
		}
		encolar(ptrcola,menor);
		imprimecola(*ptrcola);
		printf("\n");
		j--;
	}
}


int main(int argc, char** argv) {

    TCola ptrCola;
    int n;
	
    crea_cola(&ptrCola);
    encolar(&ptrCola, 15);
    encolar(&ptrCola, 10);
    encolar(&ptrCola, 17);
    encolar(&ptrCola, 16);
    encolar(&ptrCola, 13);
    encolar(&ptrCola, 18);
    encolar(&ptrCola, 19);
    imprimecola(ptrCola);
    printf("\n");
    ordenacola(&ptrCola,7);
    printf("\n");
    imprimecola(ptrCola);
 
    return (EXIT_SUCCESS);
}

