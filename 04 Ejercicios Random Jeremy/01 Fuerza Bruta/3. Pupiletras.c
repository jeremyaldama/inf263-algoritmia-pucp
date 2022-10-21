#include <stdio.h>
#define MAXCOL 8
#define MAXFIL 4

int m[8][2];//se puede tener 8 movimientos, y cada mov tiene una coordenada

void movimientos(){
	m[0][0] = -1 ; m[0][1] = -1;
	m[1][0] =  0 ; m[1][1] = -1;
	m[2][0] =  1 ; m[2][1] = -1;
	m[3][0] = -1 ; m[3][1] =  0;
	m[4][0] =  1 ; m[4][1] =  0;
	m[5][0] = -1 ; m[5][1] =  1;
	m[6][0] =  0 ; m[6][1] =  1;
	m[7][0] =  1 ; m[7][1] =  1;
}

int buscar(char tabla[][MAXCOL],char palabra[],int row,int col, int n){
	if (tabla[row][col]!=palabra[0]) return 0;
	//si la encontró, buscamos la que sigue
	int i,j,nrow,ncol;
	
	for(i=0;i<MAXCOL;i++){
		nrow = row + m[i][0];
		ncol = col + m[i][1];
		
		for (j=1;j<n;j++){
			if (nrow>=MAXFIL || nrow<0 ||
				ncol>=MAXCOL || ncol<0) break;
			
			if (tabla[nrow][ncol]!=palabra[j]) break;
			nrow = nrow + m[i][0];
			ncol = ncol + m[i][1];
		}
		if (j==n){
			
			return 1;	
		}
	}
	return 0;
}

void buscarPalabras(char tabla[][MAXCOL],char palabra[],int m){
	int i,j;
	
	for (i=0;i<MAXFIL;i++){
		for (j=0;j<MAXCOL;j++){
			if (buscar(tabla,palabra,i,j,m))
				printf("La palabra esta en: %d %d\n",i,j);
		}
	}
}

int main(){
	int m=3;
	char tabla[][MAXCOL] = {{'H','J','A','S','S'},
							{'S','G','G','O','L'},
							{'A','O','J','K','E'},
							{'J','L','D','G','G'}};
	char resultado[][MAXCOL] = {{' ',' ',' ',' '},{' ',' ',' ',' '}
								{' ',' ',' ',' '},{' ',' ',' ',' '}};
	
	char palabra[] = {'G','O','L'};
	movimientos();//se cargan los datos
	buscarPalabras(tabla,palabra,m);
	return 0;
}
