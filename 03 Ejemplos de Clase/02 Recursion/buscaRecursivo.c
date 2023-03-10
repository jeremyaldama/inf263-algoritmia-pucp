#include <stdio.h>
//T(1) = 1
int buscar(int A[], int ini, int fin, int key){ //T(n) = 1 + T(n-1) , T(n) es O(n)
    if(ini > fin)   return -1;
    if(A[ini] == key)   return ini;
    return buscar(A, ini+1, fin, key);
}

int main(){
    int A[8] = {8, 12, 3, 5, 12, 7, 6, 14};
    int n = 8;
    int k = 12;

    int val = buscar(A, 0, n-1, k);
    printf("%d\n", val);
    return 0;
}