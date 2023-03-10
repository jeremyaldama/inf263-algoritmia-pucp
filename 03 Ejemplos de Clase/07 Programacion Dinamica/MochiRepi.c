#include <stdio.h>
int mochiRepi(int* P,int* V, int W, int n){
    int c[W+1];
    int i,j,max,aux;
    c[0]=0;
    for(j=1;j<=W;j++){
        max=0;
        for(i=0;i<n;i++){
           if(j>=P[i]){
             aux=V[i]+c[j-P[i]];
           }
           else{
              aux=0;
           }
           if(aux>=max)
                max=aux;
        }
        c[j]=max;
    }
    for(i=0;i<=W;i++){
        printf("%d ",c[i]);
    }
    return c[W];
}
void main(){
    int P[]={2,1,3};
    int V[]={12,10,20};
    int W=5;//capacidad max
    int n=3;//cant valores de pesos


    printf("\n%d",mochiRepi(P,V,W,n));
}
