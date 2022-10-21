#include <stdio.h>

void hanoi(int n, char P1, char P2, char P3){
    if(n == 0)
        return;
    
    hanoi(n-1, P1, P3, P2);
    printf("Mover un disco de %c a %c\n", P1, P3);
    hanoi(n-1, P2, P1, P3);
}

int main(){

    hanoi(6, 'A','B','C');
    return 0;
}