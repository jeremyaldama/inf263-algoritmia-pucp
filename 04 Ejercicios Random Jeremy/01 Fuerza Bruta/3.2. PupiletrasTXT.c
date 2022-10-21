#include <stdio.h>
#include <stdlib.h>
#define MAXCOL 13
#define MAXFIL 13

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
		if (j==n) return 1;
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
	char tabla[13][MAXCOL];
	
	char palabra[] = {'T','E','O'};
	char car;
	int i=0,j=0;
	FILE *arch = fopen("SopaDeLetras.txt","r");
	while (1){
		fscanf(arch," %c",&car);
		if (feof(arch)) break;
		tabla[i][j] = car;
		j++;
		if (fgetc(arch)=='\n'){
			i++;
			j = 0;
		}
	}
	for (i=0;i<13;i++){
		for (j=0;j<13;j++) printf("%c ",tabla[i][j]);
		fputc('\n',stdout);
	}
	
	movimientos();//se cargan los datos
	buscarPalabras(tabla,palabra,m);
	return 0;
}
