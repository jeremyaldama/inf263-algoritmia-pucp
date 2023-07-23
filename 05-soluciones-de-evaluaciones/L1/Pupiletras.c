#include <stdio.h>
#define MAXC 6
#define MAXF 4

int m[8][2];

void cargaMovimientos(){
	m[0][0] = -1 ; m[0][1] = -1;
	m[1][0] =  0 ; m[1][1] = -1;
	m[2][0] =  1 ; m[2][1] = -1;
	m[3][0] = -1 ; m[3][1] =  0;
	m[4][0] =  1 ; m[4][1] =  0;
	m[5][0] = -1 ; m[5][1] =  1;
	m[6][0] =  0 ; m[6][1] =  1;
	m[7][0] =  1 ; m[7][1] =  1;
}

void busca(char tablero[MAXF][MAXC], char palabra[], int size, int i, int j, char resultados[MAXF][MAXC]){
	int i2, j2;
	int nuevoPosI, nuevoPosJ, encontre;
	for (i2=0; i2<8; i2++){
		nuevoPosI = i + m[i2][0];
		nuevoPosJ = j + m[i2][1];
		if (nuevoPosI>=0 && nuevoPosI<MAXF && nuevoPosJ>=0 && nuevoPosJ<MAXC){
			if (tablero[nuevoPosI][nuevoPosJ]==palabra[1]){
				encontre = 1;
				for (j2=2; j2<size; j2++){
					nuevoPosI += m[i2][0];
					nuevoPosJ += m[i2][1];
					if (nuevoPosI>=0 && nuevoPosI<MAXF && nuevoPosJ>=0 && nuevoPosJ<MAXC){
						if (tablero[nuevoPosI][nuevoPosJ]!=palabra[j2]){
							encontre = 0;
							break;
						}
					}
				}
				if (encontre){
					printf("COORDENADAS INI: %d %d\n", i, j);
					printf("DIRECCION: %d %d\n",m[i2][0], m[i2][1]);
					int x, y;
					x = i;
					y = j;
					for (j=0; j<size; j++){
						resultados[x][y] = tablero[x][y];
						x += m[x][0];
						y += m[x][1];
					}
				}
			}		
		}
	}
}

void buscarPalabra(char tablero[MAXF][MAXC], char palabra[], int size, char resultados[MAXF][MAXC]){
	int i, j;
	
	for (i=0; i<MAXF; i++){
		for (j=0; j<MAXC; j++){
			if (tablero[i][j]==palabra[0]){
				busca(tablero, palabra, size, i, j, resultados);
			}
		}
	}
}

void imprimeResultados(char resultados[MAXF][MAXC]){
	int i, j;
	for (i=0; i<MAXF; i++){
		for (j=0; j<MAXC; j++){
			printf("%c", resultados[i][j]);
		}
		printf("\n");
	}
}

int main(){
	char tablero[MAXF][MAXC] = {{'H','A','R','G','S','T'},
								{'B','C','O','G','Z','T'},
								{'D','L','N','Z','M','P'},
								{'H','G','O','L','R','T'}};
	char resultados[MAXF][MAXC] = {{' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' '}
									};
	char palabra[3] = {'G','O','L'};
	int size=3;
	cargaMovimientos();
	buscarPalabra(tablero, palabra, size, resultados);
	imprimeResultados(resultados);
	return 0;
}
