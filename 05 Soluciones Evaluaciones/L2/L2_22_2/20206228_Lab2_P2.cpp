//Estrategia: Recursion
#include <stdio.h>
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

void detectarMinas(int terreno[][5], char minasDetec[][5], int filas, int columnas,
					int posX, int posY, int i){
	//son 8 movimientos, con el indice 8 acaba
	if (i==8) return;
	int nuevoX=posX, nuevoY=posY;
	nuevoX = posX+m[i][0];
	nuevoY = posY+m[i][1];
	if (terreno[nuevoY][nuevoX]==1 && nuevoX>=0 && nuevoX<columnas && nuevoY>=0 && nuevoY<filas){
		minasDetec[nuevoY][nuevoX] = '*';
	}
	//recursividad para probar en los siguientes movimientos
	detectarMinas(terreno, minasDetec, filas, columnas, posX, posY, i+1);
}

int obtenerCantidadMinimaDePasosInicioFinal(int terreno[][5], char minasDetec[][5], int filas, int columnas, int posX, int posY){
	if (posX==columnas-1 && posY==filas-1) return 0;//llegada
	
	int derecha=999999, abajo=999999, diagonal=999999;
	
	if (posX+1<columnas && !terreno[posY][posX+1]){
		detectarMinas(terreno, minasDetec, filas, columnas, posX+1, posY, 0);
		derecha = obtenerCantidadMinimaDePasosInicioFinal(terreno, minasDetec,filas, columnas,
													  posX+1, posY);
	}
	if (posY+1<filas && !terreno[posY+1][posX]){
		detectarMinas(terreno, minasDetec, filas, columnas, posX, posY+1, 0);
		abajo = obtenerCantidadMinimaDePasosInicioFinal(terreno, minasDetec, filas, columnas,
													  posX, posY+1);
	} 
	if (posX+1<columnas && posY+1<filas && !terreno[posY+1][posX+1]){
		detectarMinas(terreno, minasDetec, filas, columnas, posX+1, posY+1, 0);
		diagonal = obtenerCantidadMinimaDePasosInicioFinal(terreno, minasDetec, filas, columnas,
													  posX+1, posY+1);	
	}
	//con recursividad se obtiene los pasos de derecha, abajo y diagonal anteriores											  
	if (derecha<abajo && derecha<diagonal) return 1+derecha;
	else if (abajo<derecha && abajo<diagonal) return 1+abajo;
	else if (diagonal<=derecha && diagonal<=abajo)return 1+diagonal;
	else return NO_PUEDE_LLEGAR;
}

int main(){
	int columnas=5, filas=9;
	int numMinPasos;
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

	char minasDetectadas[][5] = {{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '},
							{' ',' ',' ',' ',' '}};
	movimientos();
					
	numMinPasos = obtenerCantidadMinimaDePasosInicioFinal(terreno, minasDetectadas, filas, columnas, 0, 0);
	
	
	if (numMinPasos==NO_PUEDE_LLEGAR){
		printf("No es posible llegar al punto final\n");
	}
	else{
		printf("Numero minimo de pasos del punto inicial al punto final: %d\n", numMinPasos);
	}
	
	int i,j;
	printf("Minas detectadas:\n");
	printf("-------------------\n");
	for (i=0; i<filas; i++){
		for (j=0; j<columnas; j++){
			printf("|%c| ", minasDetectadas[i][j]);
		}
		printf("\n");
		printf("-------------------\n");
	}
	return 0;
}
