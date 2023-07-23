#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void PopulateGameBoard(int t, char tablero[t][t]){
	int i, j;
	char letter;
	for (i=0; i<t; i++){
		for (j=0; j<t; j++){
			letter = 'A' + (rand() % ('Z' - 'A' + 1) );
			tablero [i][j] = letter;
		}
	}
}

void ShowGameBoard(int t, char tablero[][t]){
	int i, j;
	for (i = 0; i<t ; i++){
		for(j=0; j<t; j++){
			if (j !=0) printf(" | ");
			printf("%c", tablero[i][j]);
		}
		printf("\n");
	}
}

void SearchWord(char palabra[], int t, char tablero[][t], char rpta_f[]){
	int pos[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

	for(int x = 0; x<t;x++){
		for(int y=0;y<t;y++){
			//Hasta aqui fijamos la posicion
			for(int i = 0; i < 4;i++){
				//Aqui vemos cada una de las posibilidades

				//Al inicio es verdadero
				int rpta = 1;
				if(tablero[x][y]==palabra[0]){
					for(int j = 1;j<strlen(palabra);j++){
						if((x+j*pos[i][0]>=0) &&(x+j*pos[i][0]<t) && (y+j*pos[i][1]>=0) && (y+j*pos[i][1]<t)){
							if(tablero[x+j*pos[i][0]][y+j*pos[i][1]]==palabra[j]){
								continue;
							}else{
								rpta =0; break;
							}
						}else{
							rpta = 0;
							break;//es falso
						}
					}
				}else continue;

				if(rpta==1){
					rpta_f[0] = '1' + x;
					rpta_f[1] = '1' + y;
					if(i==0){
						rpta_f[2] = 'D';
					}else if(i==1){
						rpta_f[2] = 'R';
					}else if(i==2){
						rpta_f[2] = 'U';
					}else {
						rpta_f[2] = 'L';
					}
					return;
				}

			}
		}
	}
	rpta_f[0] = -1;
	rpta_f[1] = -1;
	rpta_f[2] = -1;
}

int main(){
	srand(time(NULL));

	int t,n;

	printf("Ingrese el tamaño de la cuadricula:\n");
	scanf("%d",&t);

	char tablero[t][t];
	char palabra[t][t],arr[t][3];


	PopulateGameBoard(t,tablero);
	printf("Bienvenido al juego de sopa de letras\n");
	ShowGameBoard(t,tablero);

	printf("Ingrese la cantidad de palabras a buscar:\n");
	scanf("%d",&n);

	for(int i = 0;i<n;i++){
		printf("Palabra %d: ",i+1);
		scanf("%s",palabra[i]);
		SearchWord(palabra[i],t,tablero,arr[i]);
	}

	for(int i =0;i<n;i++){
		printf("Palabra %d - ",i+1);
		if(arr[i][0]!=-1){
			printf("%s encontrada en (%c,%c) - ",palabra[i],arr[i][0],arr[i][1]);
			if(arr[i][2]=='L') printf("izquierda\n");
			if(arr[i][2]=='R') printf("derecha\n");
			if(arr[i][2]=='U') printf("arriba\n");
			if(arr[i][2]=='D') printf("abajo\n");
		}else{
			printf("%s no encontrada\n",palabra[i]);
		}
	}

	return 0;
}