/* 
 * File:   main.c
 * Author: Rony
 *
 * Created on 16 de agosto de 2018, 11:39 PM
 */

#include <stdio.h>
#include <stdlib.h>

int bus_secuencial (int arr[],int largo,int k )
{ int i,j,temp;
i=0;
while (i<largo && arr[i]!=k )
    {
        i++;
    }
if (i<largo)
    return(i);
else
    return(-1);
}

void ord_burbuja (int arr[],int largo )
{ int j,temp;

    for (int i=0;i<=largo-2;i++)
    {
        for (j=0;j<=largo-2-i;j++)
        {
            if(arr[j+1]<arr[j])
            {temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
}

void ord_seleccion (int arr[],int largo )
{ int i,j,minimo,temp;

    for (i=0;i<=largo-2;i++)
    {
        minimo=i;
        for (j=i+1;j<=largo-1;j++)
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
    int cont,valor,n=8;
    int arreglo[]={3,2,1,4,2,7,9,5};
    
	printf("Busqueda:");
   	valor=bus_secuencial(arreglo,5,4);
   	printf("%i \n",valor);

    printf("Orden:");
    ord_burbuja(arreglo,n);
    
    for(cont=0;cont<n;cont++)
    { printf("%i ",arreglo[cont]);
    }
    printf("\n");
           
    return (0);
}

