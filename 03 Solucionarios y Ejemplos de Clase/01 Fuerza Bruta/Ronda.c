#include <stdio.h>

int main(){

    int n = 8, a = 1, b = 4;

    a = a - 1;
    b = b - 1;

    int nivel = 1;

    while(n != 1){
        a = a/2;
        b = b/2;
        n = n/2;
        if(a == b)
            break;
        nivel++;
    }

    if(n==1)
        printf("FINAL!\n");
    else
        printf("%d\n", nivel);



    return 0;
}