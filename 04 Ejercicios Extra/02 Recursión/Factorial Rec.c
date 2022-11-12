#include <stdio.h>

int factorial(int num){
	if (num==0) return 1;
	int res = factorial(num-1);
	return num*res;
}

int main(){
	int num=5;
	printf("EL FACTORIAL ES: %d",factorial(num));
}
