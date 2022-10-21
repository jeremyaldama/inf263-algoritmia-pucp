#include <stdio.h>
#include <math.h>
#define max 500

/* solucion hecha por O.D.D */

/* abrir fiesta.txt y probar los test cases */

int esta_en_rango (int arr[max][3], int j, int *a, int *b) {
	if ((*a) < arr[j][1]) {
		if (arr[j][1] > (*b)) return 0;
		else {
			(*a) = arr[j][1];
			if ((*b) > arr[j][2]) (*b) = arr[j][2];
			return 1;
		}
	} else {
		if (arr[j][2] < (*a))
			return 0;
		else {
			if ((*b) > arr[j][2]) (*b) = arr[j][2];
			return 1;
		}		
	}
}

void cargaBin (int num, int cromo[max], int top) {
	int i = 0, j, res;
	for (j = 0; j < top; j++) cromo[j] = 0;
	while (num > 0) {
		res = num%2;
		num = num/2;
		cromo[i] = res;
		i++;
	}
}

int main () {
	int n ,i , j;
	int arr[max][3];
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	int cromo[max];
	int contador = 0;
	int A, B;
	for (i = 0; i < pow(2,n); i++) {
		cargaBin(i,cromo,n); /* decimal a binario */
		/* inicializamos el valor de los rangos */
		int a = 0;
		int b = 366;
		int contH = 0; /* contador de hombres */
		int contM = 0; /* contador de mujeres */
		int flag = 0;
		for (j = 0; j < n; j++) {
			if (cromo[j] == 1) {
				if (esta_en_rango(arr,j,&a,&b)) {
					if (arr[j][0] == 1) contH++;
					else contM++;
				} else flag = 1; /* esta bandera nos indicara si hubiese un amigo
									que no puede asistir en el rango de dias
									que los demas */
			}
		}
		/* verificamos que solo asistan en pareja y que todos puedan asistir
			los mismos dias (flag == 0) */
		if (contH == contM && contH+contM > contador && !flag) {
			contador = contH+contM;
			A = a;
			B = b;
		}
	}
	printf("\nTotal de amigos: %d\n",contador);
	printf("Rango de dias disponibles para ellos: [%d,%d]\n",A,B);
	return 0;
}
