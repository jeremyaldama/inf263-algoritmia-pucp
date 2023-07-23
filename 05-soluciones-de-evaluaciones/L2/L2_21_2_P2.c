#include <stdio.h>

int hallarPesoMaximoDeTodasLasRutas(int lado,int almacen[][6], int filaIni, int colIni, int ladoX, int ladoY){
	if (ladoX==1) return 0;
	
	int i, puntajeTotal=0;
	for (i=0; i<ladoX; i++){
		puntajeTotal += almacen[filaIni][i];
	}	
	
	for (i=filaIni+1; i<lado; i++){
		puntajeTotal += almacen[i][ladoY-1];
	}
	int puntajeMayor;
	
	puntajeMayor = hallarPesoMaximoDeTodasLasRutas(lado,almacen, filaIni+1, colIni-1, ladoX-1, ladoY-1);
	
	if (puntajeTotal>puntajeMayor) return puntajeTotal;
	else return puntajeMayor; 
}

int buscarPeso(int peso, int *pesosBuscar, int numProductosPedido){
	if (numProductosPedido==0) return 0;
	
	int hayPeso=0;
	if (peso == pesosBuscar[numProductosPedido-1]) hayPeso = 1;
	
	int hayPesoRec;
	hayPesoRec = buscarPeso(peso, pesosBuscar, numProductosPedido-1);
	if (hayPesoRec || hayPeso){
		return 1;	
	}
	else return 0;
}

int verificarPedidoParaAtender(int lado,int almacen[][6], int filaIni, 
							   int colIni, int ladoX, int ladoY, 
							   int numProductosPedido, int *pedido){
	if (ladoX==1) return 0;
	
	int i, puntajeTotal=0, hayPeso, numPesos=0;
	
	for (i=0; i<ladoX; i++){
		hayPeso = buscarPeso(almacen[filaIni][i], pedido, numProductosPedido);
		if (hayPeso){
			numPesos++;	
		}
	}
	
	for (i=filaIni+1; i<lado; i++){
		hayPeso = buscarPeso(almacen[i][ladoY-1], pedido, numProductosPedido);
		if (hayPeso){
			numPesos++;	
		}
	}
	printf("NUM PESOS. %d\n",numPesos);
	int hayPesoRec;
	hayPesoRec = verificarPedidoParaAtender(lado,almacen, filaIni+1, colIni-1, ladoX-1, ladoY-1, numProductosPedido, pedido);
	printf("Hay pesRec %d y ultimo %d\n",hayPesoRec,numPesos==numProductosPedido);
	if (hayPesoRec || numProductosPedido==numPesos) return 1;
	else return 0;
}

int main(){
	int lado;
	lado = 6;
	
	int almacen[][6] = { {1,2,9,1,2,3},
						 {5,1,7,0,2,1},
						 {0,7,0,3,8,1},
						 {1,2,6,1,2,2},
						 {0,6,9,5,0,5},
						 {0,0,4,0,9,0}};
	
	int pesoMaximo;
	pesoMaximo = hallarPesoMaximoDeTodasLasRutas(lado,almacen, 0, lado-1, lado, lado);
	printf("Peso maximo: %d\n", pesoMaximo);
	
	int numProductosPedido = 3;
	int pedido[3] = {2,7,22};
	int hayProductos;
	
	hayProductos = verificarPedidoParaAtender(lado,almacen, 0, lado-1, lado, lado, numProductosPedido, pedido);
	if (hayProductos) printf("SI HAY PROD\n");
	else printf("NO HAY PROD\n");
	return 0;
}
