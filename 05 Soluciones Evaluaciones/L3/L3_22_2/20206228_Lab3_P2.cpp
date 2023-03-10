//T�cnica aplicada: Divide y Vencer�s
#include <iostream>

using namespace std;

int calcular_potencia_mas_alta(int**terreno, int filas,
							int columna_inicio, int columna_fin, int *ubi){
	if (columna_inicio == columna_fin){
		int mayor = 0;
		for (int i=0; i<filas; i++){
			if (terreno[i][columna_inicio] > mayor){
				mayor = terreno[i][columna_inicio];
				ubi[0] = columna_inicio;
				ubi[1] = i;
			}
		}
		return mayor;
	}

	int columna_mid = (columna_inicio + columna_fin)/2;

	int izquierda = 0, derecha = 0;
	int ubi_der[2], ubi_izq[2];

	izquierda = calcular_potencia_mas_alta(terreno, filas, columna_inicio,
											columna_mid, ubi_izq);
	derecha = calcular_potencia_mas_alta(terreno, filas, columna_mid+1,
											columna_fin, ubi_der);
	
	if (izquierda > derecha){
		ubi[0] = ubi_izq[0];
		ubi[1] = ubi_izq[1];
		return izquierda;
	} 
	else{
		ubi[0] = ubi_der[0];
		ubi[1] = ubi_der[1];
		return derecha;
	}
}

int main(){
	int **terreno;
	int filas, columnas;
	cout<<"Ingrese columnas y filas: ";
	cin>>columnas>>filas;
	terreno = new int*[filas];
	int i,j;
	for (i=0; i<filas; i++){
		terreno[i] = new int[columnas];
		for (j=0; j<columnas; j++){
			cout<<"Terreno["<<i<<"]["<<j<<"]: "<<endl;
			cin>>terreno[i][j];
		}
	}
	//Copiar y pegar datos
	//1er cuadro: 
	/*7 10
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 1 1 1
	  0 0 0 0 1 2 2
	  0 0 0 0 1 2 8
	  0 0 0 0 1 2 2
	  0 0 0 0 1 1 1
	  0 0 0 0 0 0 0
	*/
	/*7 8
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 0 0 0 0 0 0
	  0 1 1 1 0 0 0
	  0 1 2 1 0 0 0
	  0 1 1 1 0 0 0
	  0 0 0 0 0 0 0 	
	*/

	// a) y b)
	
	int ubicacion[2];
	int potencia_mas_alta = calcular_potencia_mas_alta(terreno, filas,
							 							0, columnas-1, ubicacion);
	cout<<"\nPotencia mas alta: "<<potencia_mas_alta<<endl;
	cout<<"Columna: "<<ubicacion[0]<<"\nFila: "<<ubicacion[1]<<endl;
	return 0;
}
