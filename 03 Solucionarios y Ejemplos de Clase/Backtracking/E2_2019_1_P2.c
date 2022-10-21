/* Tildes omitidas intencionalmente */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h> 

#define MAX_LENGTH 96
#define ACCOUNT_LENGTH 20
#define MTI_BITMAP_LENGTH 6

/* Defina la estructura solicitada*/


/* Funcion que copia los valores del arreglo src al arreglo dest, ambos de tamanho size */
void my_str_copy(int size, char src[size], char dest[size]){
	int i;
	for (i=0; i< size; i++){
		dest[i] = src[i];
	}
}

/* Funcion que extrae una subcadena de tamanho length del arreglo str de tamanho size
 * desde la posicion position, el resultado lo almacena en el arreglo str_dest. */
void sub_str(int size, char str[size], int position, int length, char str_dest[]){
	int i=0;
	while ( i< length ){
		str_dest[i] = str[position+i];
		i++;
	}
}


/* Funcion que verifica si una operacion en formato ALG 6969 es una peticion de bloqueo. */
int is_blocking(char alg6969_datum[MAX_LENGTH]){
	char mti_bitmap[MTI_BITMAP_LENGTH];
	char mti_bitmap_blocking [MTI_BITMAP_LENGTH] = {'2','9','0','2','4','2'};
	int i;
	sub_str(MAX_LENGTH, alg6969_datum, 0, MTI_BITMAP_LENGTH, mti_bitmap);

	for (i=0; i < MTI_BITMAP_LENGTH; i++)
		if (mti_bitmap[i] != mti_bitmap_blocking[i]){
			return 0;
		}
	return 1;
}


/* Funcion que convierte un arreglo str de digitos de tamanho size a double, considerando que los dos
 * ultimos digitos corresponde a la parte decimal */
double str_to_double(int size, char str[size]) {
	int i=0, cifra, exp=0;
	double res=0.0f;

	for (i=size-3; i>=0; i--){
		cifra = str[i] - '0';
		res += cifra * pow(10, exp++);
	}
	exp = 0;
	for (i=size-2; i<size; i++){
		cifra = str[i] - '0';
		res += cifra * pow(10, --exp);
	}
	return res;
}

/* Funcion que retorna el monto de la operacion del arreglo con los caracteres en formato ALG 6969 */
double get_amount(char alg6969_datum[MAX_LENGTH]){
	double amount = 0.0;
	char str_amount[12];
	sub_str(MAX_LENGTH, alg6969_datum, 34, 12, str_amount);
	amount = str_to_double(12, str_amount);
	return amount;
}

/* Funcion que compara dos arreglos de operaciones en formato ALG 6969 en base a los montos de cada uno
 * Retorna negativo si el monto del primero es menor que el segundo, cero si son iguales y positivo si
 * el monto de la primera operacion es mayor que el monto de la segunda operacion. */
double ALG6969_compare(char P[], char Q[]){
	double p_amount = get_amount(P);
	double q_amount = get_amount(Q);
	return p_amount - q_amount;
}

/* Funcion que fusiona ambas partes ordenadas de un arreglo de operaciones en formato ALG 6969
 * ini es el indice del primer elemento del arreglo de la izquierda,
 * med es el indice del elemento medio del arrego de operaciones,
 * fin es el indice del último elemento del arreglo de la derecha,
 * alg6969_data es el arreglo de operaciones en formato ALG 6969  */
void merge(int ini, int med, int fin, char alg6969_data[fin+1][MAX_LENGTH]){
	int l1 = med - ini + 1;
	int l2 = fin - med;

	char P[l1][MAX_LENGTH];
	char Q[l2][MAX_LENGTH];

	int i=0;
	for (i = ini; i<=med; i++)
		my_str_copy(MAX_LENGTH, alg6969_data[i], P[i-ini]);

	for (i = med+1; i<=fin; i++)
		my_str_copy(MAX_LENGTH, alg6969_data[i], Q[i - med - 1]);

	int p = 0;
	int q = 0;

	for (i= ini ; i<= fin; i++){
		if (p<l1 && q<l2) {
			if (ALG6969_compare(P[p], Q[q]) < 0) my_str_copy(MAX_LENGTH, P[p++], alg6969_data[i]);
			else my_str_copy(MAX_LENGTH, Q[q++], alg6969_data[i]);
		} else {
			if (p == l1) my_str_copy(MAX_LENGTH, Q[q++], alg6969_data[i]);
			else my_str_copy(MAX_LENGTH, P[p++], alg6969_data[i]);
		}
	}
}

/* Funcion que aplica la tecnica del merge sort para el ordenamiento de las operaciones en formato ALG 6969, donde:
 * ini: es el indice de la posicion inicial
 * fin: es el indice de la posicion final
 * alg6969_data: es el arreglo de operaciones en formato ALG 6969 a ordenar. */
void merge_sort(int ini, int fin, char alg6969_data[fin+1][MAX_LENGTH]){
	if (ini == fin) return;
	int med = (ini+fin)/2;
	merge_sort(ini, med, alg6969_data);
	merge_sort(med+1, fin, alg6969_data);
	merge(ini, med, fin, alg6969_data);
}

/* Funcion que aplica el algoritmo de busqueda binaria para la busqueda de la posicion en la que se encuentra
 * la operacion cuyo monto es igual o inmediatamente superior al monto de busqueda. Donde:
 * trans_num: es el numero de transacciones u operaciones
 * alg6969_data: es el arreglo de operaciones en formato ALG 6969
 * amount: es el monto de busqueda
 * ini: es el indice de la posicion inicial en la que se aplicara el algoritmo de busqueda
 * fin: es el indice de la posicion final en la que se aplicara el algoritmo de busqueda */
int binary_search(int trans_num, char alg6969_data[trans_num][MAX_LENGTH], double amount, int ini, int fin){
    if(ini > fin) return -1;

    int med = (ini+fin)/2;
    char alg6969_datum[MAX_LENGTH];
    if(get_amount(alg6969_data[med]) >= amount && get_amount(alg6969_data[med-1]) < amount)
        return med;
    else if (get_amount(alg6969_data[med]) < amount && get_amount(alg6969_data[med+1]) >= amount)
    	return med+1;
    else if(get_amount(alg6969_data[med]) > amount)
        return binary_search(trans_num, alg6969_data, amount, ini, med-1);
    else
        return binary_search(trans_num, alg6969_data, amount, med+1, fin);
}


/* Funcion que separa en un arreglo de operaciones en formato ALG 6969 a partir de un arreglo de caracteres
 * que representa a una trama completa con todas las operaciones enviadas por un banco y que estan separadas
 * por comas. Donde:
 * size: es el tamanho total del arreglo de caracteres original
 * ALG6969_data_stream: es el arreglo de caracteres original con toda la trama completa de todas las operaciones.
 * n: es la cantidad de operaciones enviadas
 * ALG6969_data: es el arreglo de operaciones en formato ALG 6969 */
void split_data_stream(int size, char ALG6969_data_stream[], int n, char ALG6969_data[n][MAX_LENGTH]){
	int i=0, j=0, k=0;
	while (k < size){
		if ( ALG6969_data_stream[k] != ',') {
			ALG6969_data[i][j++] = ALG6969_data_stream[k];
		} else {
			i++;
			j=0;
		}
		k++;
	}
}


/* Funcion que obtiene la cuenta origen de la operacion */
void get_src_account(char alg6969_datum[MAX_LENGTH], char account[ACCOUNT_LENGTH+1]){
	sub_str(MAX_LENGTH, alg6969_datum, 8, 20, account);
	account[ACCOUNT_LENGTH] = 0; //'\0';
}

/* Funcion que obtiene la cuenta destino de la operacion */
void get_dest_account(char alg6969_datum[MAX_LENGTH], char account[ACCOUNT_LENGTH+1]){
	sub_str(MAX_LENGTH, alg6969_datum, 46, 20, account);
	account[ACCOUNT_LENGTH] = 0; //'\0';
}

/* Funcion que verifica si una operacion en formato ALG 6969 es un deposito */
int is_deposit(char alg6969_datum[MAX_LENGTH]){
	char mti_bitmap[MTI_BITMAP_LENGTH];
	char mti_bitmap_trans [MTI_BITMAP_LENGTH] = {'2','2','0','0','9','B'};
	int i;
	sub_str(MAX_LENGTH, alg6969_datum, 0, MTI_BITMAP_LENGTH, mti_bitmap);

	for (i=0; i < MTI_BITMAP_LENGTH; i++)
		if (mti_bitmap[i] != mti_bitmap_trans[i]){
			return 0;
		}
	return 1;
}


/* Funcion que verifica si el que participa en la operacion es VIP */
int is_VIP(char alg6969_datum[MAX_LENGTH]) {
	int res = 0;
	if (alg6969_datum[MAX_LENGTH-1] == '2')
		res =  1;
	return res;
}

/* Funcion que muestra la cuenta destino y el monto de cada una de los depositos */
void show_deposits(int trans_num, char alg6969_data[trans_num][MAX_LENGTH]){
	int i;
	char dest_account[ACCOUNT_LENGTH+1];
	printf("\nDepositos realizados:\n");
	printf("    Cuenta destino \t| Monto transferido\n");

	for (i=0; i<trans_num; i++){
		if (is_deposit(alg6969_data[i])){
			get_dest_account(alg6969_data[i], dest_account);
			printf("%s \t| S/. %.2f\n", dest_account, get_amount(alg6969_data[i]));
		}
	}
}

int main(){
	int transactions_number=36, size=3491;
	int i,j;
	char data[] = "22009B020000000000000000000000000000000010000054321543215432154321000000000000070611305200000001,22009B020000000000000000000000000000000010010054321543215432154321000000000000070612305200000001,22009B020000000000000000000000000000000010020054321543215432154321000000000000070613305200000001,22009B020000000000000000000000000000000010030054321543215432154321000000000000070613315200000001,22009B020000000000000000000000000000000010040054321543215432154321000000000000070613325200000001,22009B020000000000000000000000000000000010050054321543215432154321000000000000070613335200000001,22009B020000000000000000000000000000000010000054321543215432154322000000000000070611305200000002,22009B020000000000000000000000000000000010000054321543215432154322000000000000070612305200000002,22009B020000000000000000000000000000000010000054321543215432154322000000000000070613305200000002,22009B020000000000000000000000000000000010000054321543215432154322000000000000070613315200000002,22009B020000000000000000000000000000000010000054321543215432154322000000000000070613325200000002,22009B020000000000000000000000000000000010000054321543215432154322000000000000070613335200000002,22009B020000000000000000000000000000000010000054321543215432154323000000000000070611305200000001,22009B020000000000000000000000000000000010010054321543215432154323000000000000070612305200000001,22009B020000000000000000000000000000000010020054321543215432154323000000000000070613305200000001,22009B020000000000000000000000000000000010030054321543215432154323000000000000070613315200000001,22009B020000000000000000000000000000000010040054321543215432154323000000000000070613325200000001,22009B020000000000000000000000000000000010050054321543215432154323000000000000070613335200000001,22009B020000000000000000000000000000000009999954321543215432154324000000000000070611305200000002,22009B020000000000000000000000000000000009999954321543215432154324000000000000070612305200000002,22009B020000000000000000000000000000000009999954321543215432154324000000000000070613305200000002,22009B020000000000000000000000000000000009999954321543215432154324000000000000070613315200000002,22009B020000000000000000000000000000000009999954321543215432154324000000000000070613325200000002,22009B020000000000000000000000000000000009999954321543215432154324000000000000070613335200000002,22009B020000000000000000000000000000000010000054321543215432154325000000000000070611305200000001,22009B020000000000000000000000000000000010010054321543215432154325000000000000070612305200000001,22009B020000000000000000000000000000000010020054321543215432154325000000000000070613305200000001,22009B020000000000000000000000000000000010030054321543215432154325000000000000070613315200000001,22009B020000000000000000000000000000000010040054321543215432154325000000000000070613325200000001,22009B020000000000000000000000000000000010050054321543215432154325300000000000070613335200000001,22009B020000000000000000000000000000000009999954321543215432154326000000000000070611305200000002,22009B020000000000000000000000000000000009999954321543215432154326000000000000070612305200000002,22009B020000000000000000000000000000000009999954321543215432154326000000000000070613305200000002,22009B020000000000000000000000000000000009999954321543215432154326000000000000070613315200000002,22009B020000000000000000000000000000000009999954321543215432154326000000000000070613325200000002,22009B020000000000000000000000000000000009999954321543215432154326000000000000070613335200000002";
	char alg6969_data[transactions_number][MAX_LENGTH];
	char src_account[ACCOUNT_LENGTH+1];
	char operation[MAX_LENGTH];

	/* Separacion de la trama completa de operaciones en un arreglo de operaciones. */
	split_data_stream(size, data, transactions_number, alg6969_data);

	/* Programe aqui lo correspondiente al main */
	
	return 0;
}

