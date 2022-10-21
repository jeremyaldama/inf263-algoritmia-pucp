#include <stdio.h>
char A[4];

void binary(int n){
	if (n < 1){
		printf("%s",A);
	}
	else{
		A[n-1] = 0;
		binary(n-1);
		A[n-1] = 1;
		binary(n-1);
	}
}

int main(){
	binary(100);
}
