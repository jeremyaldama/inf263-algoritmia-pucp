/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: cueva
 *
 * Created on 22 de junio de 2020, 11:50 AM
 */

#include <stdio.h>
#include <stdlib.h>

//int A[][3]={{0,1,4},{1,2,3},{2,-1,-1},{3,-1,-1},{4,-1,-1}};
int A[][3]={{0,1,5},{1,2,3},{2,4,-1},{3,-1,-1},{4,-1,-1},{5,6,7},{6,-1,-1},{7,-1,-1}};
int izq(int x){
    return A[x][1];
    
}
int der(int x){
    return A[x][2];
    
}

int bt(int c,int n){
    int act;
    
    if(c==n){
        printf("%d ",c);
        return 1;
    }
    else{
        if(c==-1) return 0;
        else
            printf("%d ",c);
        
        act = der(c);
        if(bt(act,n))
            return 1;
                
        act = izq(c);
        if(bt(act,n))
            return 1;

    }
        
}

int empaca(int i,int n,int peso,int p[] ){
    int valor;
    if(i==n || peso<0)
        return 0;
    if(p[i]==peso){
        printf("\nResultado:%d\n",p[i]);
        return 1;
    }
    printf("%d %d %d %d\n",i,p[i],peso,peso-p[i]);
    valor = empaca(i+1,n,peso-p[i],p);
    printf("valor:%d\n",valor);
    if(valor)
    {
        printf("\nResultado:%d\n",p[i]);
        return 1;
    }
    else
        return(empaca(i+1,n,peso,p)); //Back
    
}


int main(int argc, char** argv) {
   /* 3, 4 = 10-7 = 3
    3, 4, 6 = 3 - 6 =-3  
    3, 4, 8 = 3 - 8 =-5
    3, 6 = 10 - 9 = 1
    3, 6, 8 = 1 - 8 = -7        
    3, 8 = 10 - 11 = -1
    4 ,6 = 10 - 10 = 0
    */        
    int paq[] = {3,4,6,8};
    int n=4,peso = 10;
    if(empaca(0,n,peso,paq))
        printf("\nHay Solucion\n");
    else
        printf("\nNo hay Solucion\n");
    
    bt(0,6);  
  
    
    return (EXIT_SUCCESS);
}

