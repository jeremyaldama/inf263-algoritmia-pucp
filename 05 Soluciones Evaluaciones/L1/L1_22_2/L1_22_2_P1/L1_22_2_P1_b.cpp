// FUERZA BRUTA
#include <iostream>
#include <math.h>

using namespace std;

int n = 8;
int M = 4;
int P = 19;

void carga_bin(int *arreglo, int numero)
{
	int bit;
	for (bit = 0; bit < n; bit++)
	{
		arreglo[n - 1 - bit] = numero & 1;
		numero >>= 1;
	}
}

int main(){
	int costo_total, can_herr;
	// {precio, cant. a renovar}
	int herramientas[n][2];

	// Copiar y pegar en terminal: 4 3 5 2 4 1 2 1 6 3 3 3 4 2 1 4

	for (int i=0; i<n; i++){
		for (int j=0; j<2; j++){
			cout<<"herramientas["<<i<<"]["<<j<<"] = ";
			cin>>herramientas[i][j];
		}
		cout<<endl;
	}

	int cromo[n];
	int comb = (int)pow(2, n);
	int i, j, cant_tipos;
	int nsol = 0, soluciones[comb];

	for (i = 0; i < comb; i++){
		carga_bin(cromo, i);
		costo_total = 0;
		cant_tipos = 0;

		for (j = 0; j < n; j++){
			if (cromo[j])
			{
				costo_total += herramientas[j][0] * herramientas[j][1];
				cant_tipos++;
			}
		}

		if (cant_tipos <= M && costo_total <= P){
			soluciones[nsol] = i;
			nsol++;
		}
	}

	for (i = 0; i < nsol; i++){
		carga_bin(cromo, soluciones[i]);
		costo_total = cant_tipos = 0;
		for (j = 0; j < n; j++){

			if (cromo[j]){
				cout << j + 1 << " ";
				cant_tipos++;
				costo_total += herramientas[j][0] * herramientas[j][1];
			}

		}
		cout << endl;
		cout << "Monto Total: " << costo_total << endl;
		cout << "Cantidad de tipos de herramientas: " << cant_tipos << endl << endl;
	}

	return 0;
}
