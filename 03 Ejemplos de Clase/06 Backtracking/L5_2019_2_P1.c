
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void inicializaMatriz(int mat[MAX][MAX]){
    int i,j;
    for (i=0;i<MAX;i++)
        for (j=0;j<MAX;j++)
            mat[i][j]=-1;
}

int esValido(int cuadro, int x,int y,int piso[MAX][MAX],int w,int h){
    //Verifica limites y espacio vacio
    if (x<0 || x>=w || y<0 || y>=h || piso[x][y]>=0)
        return 0;
    //Cuadro 0 y 3 horizontal
    if (cuadro==0 || cuadro==3){
        if (x>=1  && (piso[x-1][y]==1 || piso[x-1][y]==2))
            return 0;
        if (x<w-1 && (piso[x+1][y]==1 || piso[x+1][y]==2))
            return 0;
    }
    //Cuadro 1 y 2 horizontal
    if (cuadro==1 || cuadro==2){
        if (x>=1  && (piso[x-1][y]==0 || piso[x-1][y]==3))
            return 0;
        if (x<w-1 && (piso[x+1][y]==0 || piso[x+1][y]==3))
            return 0;
    }
    //Cuadro 0 y 2 vertical
    if (cuadro==0 || cuadro==2){
        if (y>=1  && (piso[x][y-1]==1 || piso[x][y-1]==3))
            return 0;
        if (y<h-1 && (piso[x][y+1]==1 || piso[x][y+1]==3))
            return 0;
    }
    //Cuadro 1 y 3 vertical
    if (cuadro==1 || cuadro==3){
        if (y>=1  && (piso[x][y-1]==0 || piso[x][y-1]==2))
            return 0;
        if (y<h-1 && (piso[x][y+1]==0 || piso[x][y+1]==2))
            return 0;
    }
    //Paso todas las pruebas
    return 1;
}

void coordenadas(int num,int *x,int *y,int ancho){
    //x es horizontalmente. y es verticalmente
    *x = num % ancho;
    *y = num / ancho;
}

int ceramico(int pos,int cuadro,int piso[MAX][MAX],int w,int h,int* sol){
    int x,y,i;
    //Cuador no valido
    if (cuadro>=4)
        return 0;
    //Completo piso
    if (pos==w*h){
        (*sol)++;
        return 0;
    }
    //Saca coordenadas de posicion
    coordenadas(pos,&x,&y,w);
    //Si es posicion valida
    if (esValido(cuadro,x,y,piso,w,h)){
        //Marco colocado
        piso[x][y]=cuadro;
        //Coloca siguiente empezando por el 0
        if (ceramico(pos+1,0,piso,w,h,sol))
            return 1;
    }
    //Desmarca
    piso[x][y]=-1;
    //Prueba otro cuadro
    return ceramico(pos,cuadro+1,piso,w,h,sol);
}
int main(int argc, char** argv) {
    int w,h,sol=0;
    //parte a)
    
    //Matriz del piso
    int piso[MAX][MAX];
    inicializaMatriz(piso);
    
    //Obtiene dimensiones
    printf("Ingrese dimensiones w y h: ");
    scanf("%d %d",&w,&h);
    
    //parte b
    //Halla por backtracking
    ceramico(0,0,piso,w,h,&sol);
    //Imprime resultado
    printf("\nNumero de soluciones posibles: %d\n",sol);
    
    return (EXIT_SUCCESS);
}

