#include <stdio.h>
#include <stdlib.h>

#define num1 4
#define num2 5

/* ex1 2018_2 p4 */

int cont = 0;

int es_valido(int num) {
	while (num > 0) {
		if ((num % 10 != num1) && (num % 10 != num2))
            return 0;
        num /= 10;
	}
	return 1;
}

int buscar_oficinas(int num, int dig, int cant) {
	if (dig > cant) 
		return 0;
	int num_max = 0, i;
	for (i = 0; i < dig; i++)
        num_max = num_max * 10 + num2;
    if (num > num_max)
    	return buscar_oficinas(num,dig+1,cant);
	if (!es_valido(num))
		return buscar_oficinas(num+1,dig,cant);
	else {
		printf("%d ",num);
		cont++;
	}
	if (buscar_oficinas(num+1,dig,cant))
		return 1;	
}

void main () {
	int n = 4;
	buscar_oficinas(1,1,n);
	printf("\nSoluciones: %d",cont);
}
