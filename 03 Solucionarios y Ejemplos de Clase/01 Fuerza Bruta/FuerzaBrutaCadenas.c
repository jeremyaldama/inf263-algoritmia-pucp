

/* 
 * File:   main.c
 * Author: Rony
 *
 * Created on 19 de agosto de 2018, 07:55 AM
 */

#include <stdio.h>
#include <stdlib.h>


int bus_coincidencia (char T[],char P[],int n, int m )
{ int i,j;

i=0;
for (i=0;i<=n-m;i++)
{
    j=0;
    while (j<m && P[j]==T[i+j])
    {
        j++;
    }
    if (j==m)
        return(i);
}
return(-1);
}


void ord_burbuja_cadena (char arr[],int largo )
{ int i,j,temp;

    for (i=0;i<largo-1;i++)
    {
        for (j=0;j<largo-2-i;j++)
        {
            if(arr[j+1]<arr[j])
            {temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
}

void ord_seleccion_cadena (char arr[],int largo )
{ int i,j,minimo,temp;

    for (i=0;i<largo-1;i++)
    {
        minimo=i;
        for (j=i+1;j<largo;j++)
        {
            if(arr[j]<arr[minimo])
                minimo=j;
        }
        temp=arr[i];
        arr[i]=arr[minimo];
        arr[minimo]=temp;
    }
}

int main() {
    int i,valor;
        
    char T[]="DIME QUE NO VAS";
    char P[]="NO";

    for(i=0;i<15;i++)
    { printf("%c",T[i]);
    }
    printf("\n");

    printf("String Matching:");
    valor=bus_coincidencia(T,P,15,2);
    printf("%i \n",valor);

    printf("Orden:");
    
    ord_seleccion_cadena(T,15);
    
    for(i=0;i<15;i++)
    { printf("%c ",T[i]);
    }
    printf("\n");
           
    return (0);
}
