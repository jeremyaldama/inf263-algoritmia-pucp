#include <stdio.h>

void triangulo(int a, int b) {
	int i;
	if (a <= b) {
		for (i = 0; i < a; i++) printf(" * ");
		printf("\n");
		triangulo(a+1,b);
		for (i = 0; i < a; i++) printf(" * ");
		printf("\n");
	}
	return;	
}

int main () {
	triangulo(3,5);
	return 0;
}
