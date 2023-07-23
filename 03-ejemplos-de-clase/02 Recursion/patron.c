#include <stdio.h>

void patron(int n, int i){// T(n) = 2T(n/2) + 1 = O(n)
    if(n == 0) return;

    int j;

    patron(n/2, i);
    for(j = 0; j< i; j++) printf("   ");
    for(j = 0; j < n; j++)printf(" * ");
    printf("\n");
    patron(n/2, n/2 + i);
}

void main(void){
    patron(8,0);
}
