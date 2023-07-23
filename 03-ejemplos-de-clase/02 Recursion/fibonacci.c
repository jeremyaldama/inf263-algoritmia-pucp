#include <stdio.h>

int fibonacci(int n){
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else{
    	int resul = fibonacci(n-2)+fibonacci(n-1);
    	printf("%d n=%d\n", resul,n);
    	return resul;
	}
}

int main(){

    int n = 6;
    printf("\nEl %d-esimo termino de la serie es %d\n", n, fibonacci(n));
    
    return 0;
}
