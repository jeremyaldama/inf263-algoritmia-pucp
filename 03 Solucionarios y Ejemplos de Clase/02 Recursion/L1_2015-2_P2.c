#include <stdio.h>

void patron(int n, int i){
	int j;
    if(n == 0) return;
    patron(n/2, i);
    for(j = 0; j< i; j++) printf("   ");
    for(j = 0; j < n; j++)printf(" * ");
    printf("\n");
    patron(n/2, n/2 + i);
}

int main() {
    patron(8,0);
    return 0;
}
