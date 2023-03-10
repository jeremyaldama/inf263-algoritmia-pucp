#include <stdio.h>

void hanoi(int n, char ori, char aux, char dest){
	if (n==0) return;
	
	hanoi(n-1, ori, dest, aux);
	printf("Mover %d de %c a %c\n", n, ori, dest);
	hanoi(n-1, aux, ori, dest);
}

int main(){
	hanoi(3, 'A', 'B','C');
	return 0;
}
