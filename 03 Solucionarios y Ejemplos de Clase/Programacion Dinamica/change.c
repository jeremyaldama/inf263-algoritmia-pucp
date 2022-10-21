#include <stdio.h>
int change(int n, int* A,int tam){

    int c[n+1][tam+1];
    int i,j;

    //inicializar columna
    for(i=0;i<=n;i++)
        c[i][0]=0;
    //inicializar fila
    for(i=1;i<=tam;i++)
        c[0][i]=1;

    for(i=1;i<=n;i++){
        for(j=1;j<=tam;j++){
           if(i-A[j-1]>=0){
              c[i][j]=c[i][j-1]+c[i-A[j-1]][j];
           }
           else{
            c[i][j]=c[i][j-1];
           }

        }
    }

    for(i=0;i<=n;i++){
        for(j=0;j<=tam;j++){
           printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return c[n][tam];
}
void main(){
    int n=10;// quiero cambiar 10 soles
    int A[]={1,2,5};// en monedas de 1,2,5 soles
//    for(int i=0;i<3;i++){
//        printf("%d ",A[i]);
//    }
//    printf("%d\n");
//
//    printf("%d\n ",sizeof A/sizeof *A);




    int size=sizeof A/sizeof *A;
    printf("%d",change(n,A,size));

}

