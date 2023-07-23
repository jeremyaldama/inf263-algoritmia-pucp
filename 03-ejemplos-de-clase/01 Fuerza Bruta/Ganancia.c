
//El programa tiene complejidad n^3

#include <stdio.h>
#include <stdlib.h>
#define N 10
#include <math.h>

void convertirBinario(int binario[],int i,int n){
    int residuo;
    int f=0,d;
    
    //Inicializamos binario
    for(d=0;d<n;d++)
        binario[d]=0;
    
    while(i>0){
        residuo=i%2;
        i=i/2;
        binario[f]=residuo;
        f++;
    }
}

int main(int argc, char** argv) {
    
    int costo[N];
    int ganancia[N];
    int predecesores[N][3];
    int binario[N];
    int presupuesto;
    int n;
    
    int i,j,d,k;
    int gananciaTotal,costoTotal, sePuede,gananciaMax,mejorCombinacion,costoRpta;
   
/*
    int n=4;
    int presupuesto=250;
    int costo[4]={80, 20, 100, 100};
    int ganancia[4]={150, 80,300,150};
    int predecesores[4][3]={{0,0,0},{0,0,0},{1,2,0},{0,0,0}};
    int binario[4];
*/
        
    //Ingreso de Datos
    printf("Ingrese Numero de Proyectos y Presupuesto: ");
    scanf("%d %d",&n,&presupuesto);
    for(i=0;i<n;i++){
        printf("Ingrese el costo y la ganancia del proyecto %d: ",i+1);
        scanf("%d %d",&costo[i],&ganancia[i]);
        printf("Ahora Ingrese los predecesores: ");
        for(j=0;j<3;j++){
            //Tiene que ingresar siempre 3 datos y en los que no haya se ingresa 0
            //Por ejemplo si tiene de predecesor al proyecto 1 y 2, debe poner 1, luego 2 y luego 0
            //si no tiene predecesores tiendra que poner tres Ceros
            scanf("%d",&predecesores[i][j]);
        }
    }
    
    gananciaMax=0;
    int comb=pow(2,n);
    for(i=0;i<comb;i++)
	{
        gananciaTotal=0;
        costoTotal=0;
        sePuede=1;
        convertirBinario(binario,i,n);
        
        //Ahora recorremos el arreglo binario, si es 1 es porque el proyecto se va a hacer
        for(d=0;d<n;d++){
            if(binario[d]==1){
            	sePuede = 1;
                //Ahora tenemos que revisar si sus predecesores tambien son 1
                for(k=0;k<3;k++){
                    if(predecesores[d][k]!=0)
                        if(binario[predecesores[d][k]-1]==0)
                            sePuede=0;
                }
                if(sePuede==0)
					break;
				else{
						gananciaTotal+=ganancia[d];
                		costoTotal+=costo[d];
				}
            }
        }
        
        if(sePuede == 1 &&  costoTotal<=presupuesto && gananciaTotal>gananciaMax)
		{
            gananciaMax=gananciaTotal;
            costoRpta=costoTotal;
            mejorCombinacion=i;
        }
        
    }
    
    convertirBinario(binario,mejorCombinacion,n);
    printf("Mejor Combinacion:\n");
    for(i=0;i<n;i++){
        printf("%d ",binario[i]);
    }
    printf("\n Ganancia= %d Costo= %d\n",gananciaMax,costoRpta);
   
    return 0;
}

