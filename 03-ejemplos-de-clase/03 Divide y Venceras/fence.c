#include <stdio.h>

int fence(int A[], int ini, int fin){
    if(ini > fin)
        return 0;
    
    int min = A[ini];
    int pos = ini;

    for(int i = ini+1; i <=fin; i++){
        if(A[i] < min){
            min = A[i];
            pos = i;
        }
    }

    for(int i = ini; i<=fin; i++)
        A[i] = A[i] - min;
    
    int val = min + fence(A, ini, pos-1) + fence(A, pos+1, fin);

    if(val < (fin-ini+1))
        return val;
    else
        return fin-ini+1;

}

int main(){
    int A[20] = {2, 2, 1, 2, 1};
    int n = 5;

    int val = fence(A, 0, n-1);
    printf("El minimo es %d\n", val);
}