#include <stdio.h>

void WriteBinary(int x){
	// A pensar 9 -> 1001
	// 8 / 2 Resto: 0 -> 4 /2 Resto: 0 -> 2/2 Resto: 0 -> 1/2 -> 0 Resto: 1
	if (x != 0){
		WriteBinary(x/2);
		printf("%d", x%2);
	}
}

int main(){
	int num;	
	printf("Ingrese un numero entero: ");
	scanf("%d", &num);
	WriteBinary(num);
	printf("\n");
	return 0;
}

