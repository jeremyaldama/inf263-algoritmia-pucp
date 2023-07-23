#include <stdio.h>
#include <string.h>

int palindromo(char C[], int ini, int fin){
    if(ini==fin)    return 1;
    if(ini > fin)   return 1;
    if(C[ini]!=C[fin])  return 0;
    return palindromo(C, ini+1, fin-1);
}

int main(){

    // Todo variable de arreglo ya es un puntero
    char cad[100]; 
    
    scanf("%s", cad);
    int n = strlen(cad);

    if(palindromo(cad, 0, n-1))
        printf("Palindromo\n");
    return 0;
}