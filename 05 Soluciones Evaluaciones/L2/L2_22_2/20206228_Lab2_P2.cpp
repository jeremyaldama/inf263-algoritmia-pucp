//Estrategia: Recursion
#include <iostream>
#include <vector>

using namespace std;
#define NO_PUEDE_LLEGAR -1

/*Los movimientos del robot son:
	derecha: posX+1 posY
	abajo:   posX   posY+1
	diagonal:posX+1 posY+1
*/
int m[8][2];

void movimientos(){
	m[0][0] = -1; m[0][1] = -1;
	m[1][0] =  0; m[1][1] = -1;	
	m[2][0] =  1; m[2][1] = -1;	
	m[3][0] = -1; m[3][1] =  0;	
	m[4][0] =  1; m[4][1] =  0;
	m[5][0] = -1; m[5][1] =  1;
	m[6][0] =  0; m[6][1] =  1;
	m[7][0] =  1; m[7][1] =  1;				
}

void detectar_minas(int terreno[][5], char minas_detectadas[][5],
					int filas, int columnas,
					int pos_x, int pos_y, int i){
	//son 8 movimientos, con el indice 8 acaba
	if (i==8) return;
	int nuevo_x = pos_x, nuevo_y = pos_y;

	nuevo_x = pos_x + m[i][0];
	nuevo_y = pos_y + m[i][1];

	if (terreno[nuevo_y][nuevo_x]==1 && filas > nuevo_y && columnas > nuevo_x){
		minas_detectadas[nuevo_y][nuevo_x] = '*';
	}
	//recursividad para probar en los siguientes movimientos
	detectar_minas(terreno, minas_detectadas, filas, columnas, pos_x, pos_y, i+1);
}

int obtener_cantidad_minima_pasos(int terreno[][5], char minas_detectadas[][5],
								int filas, int columnas, int pos_x, int pos_y){
	// 0. Verificamos si ya hemos llegado a la meta
	if (pos_x == columnas-1 && pos_y == filas-1){
		return 0;
	}

	detectar_minas(terreno, minas_detectadas, filas, columnas, pos_x, pos_y, 0);

	int pasos_abajo, pasos_derecha, pasos_diagonal;
	// le damos valores grandes para que escoja al que sí llego a la meta final
	pasos_abajo = pasos_derecha = pasos_diagonal = 999999;
	// 1. Verificamos si puede avanzar hacia abajo
	if (pos_y+1 < filas){
		if (terreno[pos_y+1][pos_x] == 0){
			pasos_abajo = obtener_cantidad_minima_pasos(terreno, minas_detectadas,
												filas, columnas, pos_x, pos_y+1) + 1;
		}
	}
	// 2. Verificamos si puede avanzar en diagonal
	if (pos_y+1 < filas && pos_x+1 < columnas){
		if (terreno[pos_y+1][pos_x+1] == 0){
			pasos_diagonal = obtener_cantidad_minima_pasos(terreno, minas_detectadas,
												filas, columnas, pos_x+1, pos_y+1) + 1;
		}
	}
	// 3. Verificamos si puede avanzar hacia la derecha
	if (pos_x+1 < columnas){
		if (terreno[pos_y][pos_x+1] == 0){
			pasos_derecha = obtener_cantidad_minima_pasos(terreno, minas_detectadas,
												filas, columnas, pos_x+1, pos_y) + 1;
		}
	}

	// 4. Verificamos si ya llego al final
	if (pos_x == columnas-1 && pos_y == filas-1){
		return 0;
	}

	if (pasos_abajo == NO_PUEDE_LLEGAR && pasos_derecha == NO_PUEDE_LLEGAR && pasos_diagonal == NO_PUEDE_LLEGAR){
		return NO_PUEDE_LLEGAR;
	}
	else if (pasos_abajo == NO_PUEDE_LLEGAR && pasos_derecha == NO_PUEDE_LLEGAR){
		return pasos_diagonal;
	}
	else if (pasos_abajo == NO_PUEDE_LLEGAR && pasos_diagonal == NO_PUEDE_LLEGAR){
		return pasos_derecha;
	}
	else if (pasos_derecha == NO_PUEDE_LLEGAR && pasos_diagonal == NO_PUEDE_LLEGAR){
		return pasos_abajo;
	}
	else if (pasos_abajo == NO_PUEDE_LLEGAR){
		return min(pasos_derecha, pasos_diagonal);
	}
	else if (pasos_derecha == NO_PUEDE_LLEGAR){
		return min(pasos_abajo, pasos_diagonal);
	}
	else if (pasos_diagonal == NO_PUEDE_LLEGAR){
		return min(pasos_abajo, pasos_derecha);
	}
	else{
		return min(pasos_abajo, min(pasos_derecha, pasos_diagonal));
	}
}

int main(){
	int columnas=5, filas=9;
							//0 significa terreno libre
							//1 significa que hay mina en el terreno
	int terreno[][5] = {{0,0,0,0,1},
						{0,0,0,0,0},
						{0,0,1,0,0},
						{0,0,0,0,0},
						{0,1,1,0,1},
						{0,1,1,0,1},
						{1,1,0,1,0},
						{1,1,1,1,0},
						{1,0,0,0,0}};

	char minas_detectadas[][5] = {{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '}};
	movimientos();
					
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			cout << terreno[i][j] << " ";
		}
		cout << endl;
	}

	int pasos_minimos = obtener_cantidad_minima_pasos(terreno, minas_detectadas, filas, columnas, 0, 0);
	cout<<"Pasos minimos: "<<pasos_minimos<<endl;
	
	cout<<"-----------"<<endl;
	for (int i=0; i<filas; i++){
		cout<<"|";
		for (int j=0; j<columnas; j++){
			cout << minas_detectadas[i][j] << "|";
		}
		cout << endl;
		cout<<"-----------"<<endl;
	}
	return 0;
}
