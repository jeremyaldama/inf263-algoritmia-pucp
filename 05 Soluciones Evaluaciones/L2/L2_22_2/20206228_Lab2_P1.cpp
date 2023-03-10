//Estrategia: recursion
#include <iostream>
#include <vector>

using namespace std;


void colocar_en_anaquel(vector<vector<int>> &anaquel, int columna,
				 	int productos, int productos_fila_1, int fila_i, int col_i){
	if (productos == 0){
		return;
	}

	for (int j = col_i; j < col_i + productos_fila_1; j++){
		if (anaquel[fila_i][j] == 0 && productos > 0){
			anaquel[fila_i][j] = 5;
			productos--;
			cout<<productos<<" ";
		}
	}
	
	colocar_en_anaquel(anaquel, columna, productos, 
					productos_fila_1 + 2 > columna ? columna : productos_fila_1 + 2,
					fila_i + 1,
					col_i - 1 > 0 ? col_i - 1 : 0);
}

int main(){
	int fila, columna, productos;
	
	cout<<"Ingrese el numero de filas: ";
	cin>>fila;

	cout<<"Ingrese el numero de columnas: ";
	cin>>columna;

	cout<<"Ingrese el numero de productos: ";
	cin>>productos;

	vector<vector<int>> anaquel(fila);

	/* 	COPIAR Y PEGAR LOS NUMEROS EN EL TERMINAL
		Anaquel 5x5
		0 0 0 0 0
		0 0 0 0 0
		0 0 0 1 0
		0 1 0 0 0
		0 0 0 0 0

		Anaquel 6x6
		0 0 0 0 0 0
		0 0 0 0 0 0
		0 0 0 1 0 0
		0 1 0 0 0 0
		0 0 0 0 1 0
		0 0 0 0 0 0
	*/

	for (int i = 0; i < fila; i++){
		anaquel[i].resize(columna);
		for (int j = 0; j < columna; j++){
			cout<<"Ingrese el valor de la posicion ["<<i<<"]["<<j<<"]: ";
			cin>>anaquel[i][j];
		}
	}
	cout<<endl;
	// Imprimir Anaquel
	for (int i = 0; i < fila; i++){
		for (int j = 0; j < columna; j++){
			cout<<anaquel[i][j]<<" ";
		}
		cout<<endl;
	}

	int productos_fila_1 = columna % 2 == 0 ? 2 : 1;
	int col_i = productos_fila_1 == 1? columna/2 : columna/2 - 1;
	cout<<col_i<<endl;

	colocar_en_anaquel(anaquel, columna, productos, productos_fila_1, 0, col_i);
	
	cout<<"Anaquel con productos"<<endl;

	for (int i = 0; i < fila; i++){
		for (int j = 0; j < columna; j++){
			cout<<anaquel[i][j]<<" ";
		}
		cout<<endl;
	}
}
