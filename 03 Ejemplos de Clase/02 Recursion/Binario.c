/* 
 * File:   main.c
 * Author: Rony
 *
 * Created on 26 de agosto de 2018, 10:29 AM
 */

#include <stdio.h>
#include <stdlib.h>


void Binario( int x)
{ 
    if ( x != 0 )
    { 
    Binario(x/2);
    printf("%d", x%2);
    } 
}  

int main()
{  
 int    num; 

printf("\n Introduzca un numero entero: ");
scanf("%d", &num);

Binario(num);

scanf("%d", &num);

return 0;
} 
