
/* 
 * File:   main.c
 * Author: Rony
 *
 * Created on 25 de agosto de 2018, 10:33 PM
 */

#include <stdio.h>
#include <stdlib.h>

int  factorial(int n)
{
    if (n==0)
        return(1);
    else
        return (n*factorial(n-1));    
           
}

int fibonacci(int n)
{
    if(n==1)
        return(0);
    else
        if(n==2)
            return(1);
        else
            return(fibonacci(n-1) + fibonacci(n-2)); 
}

int main() {
    int valor;
    
    valor=5;
    
    //factorial
    printf("Factorial: %i \n",factorial(valor));

    //fibonacci
    printf("Fibonacci: %i",fibonacci(valor));
    

    return (0);
}

