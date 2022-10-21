/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 17 de mayo de 2020, 07:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void divide(TLista ptrlista,TLista *ptrimpar,TLista *ptrpar)
{	int i=1,n;
		
	n=tamano(ptrlista);
	while(n>=i)
	{	
		if(i%2==1)
			insertar_final(ptrimpar,ptrlista->elem);
		else
			insertar_final(ptrpar,ptrlista->elem);
		i++;
		ptrlista=ptrlista->sig;	
	}	
	
}

void invierte(TLista *ptrLista)
{   TLista ptrrec,ptrant=NULL,ptrini;
    int i,j,n;
    
    n=tamano(*ptrLista);
    for(i=1;i<n;i++)
    {   ptrrec=*ptrLista;
        for(j=i;j<n;j++)
        {   ptrant=ptrrec; 
            ptrrec=ptrrec->sig;
        }
        if(i==1)
            ptrini=ptrrec;
        ptrrec->sig=ptrant;
    }
    if(i!=1)
        ptrant->sig=NULL;
    *ptrLista=ptrini;

}


int main(int argc, char** argv) {
    TLista ptrLista,ptrpar,ptrimpar;
    
    crear_lista(&ptrLista);
    insertar_final(&ptrLista, 19);
    invierte(&ptrLista);
    imprimir(ptrLista);
    insertar_final(&ptrLista, 20);
    insertar_final(&ptrLista, 16);
    insertar_final(&ptrLista, 26);
    imprimir(ptrLista);
    printf("Tamano:%d\n",tamano(ptrLista));
    crear_lista(&ptrpar);
    crear_lista(&ptrimpar);
    divide(ptrLista,&ptrimpar,&ptrpar);
    imprimir(ptrimpar);
    imprimir(ptrpar);
	
    invierte(&ptrLista);
    imprimir(ptrLista);
    finalizar_lista(ptrLista);
    
    return (EXIT_SUCCESS);
}

