#include <stdio.h>

void rombo(int a, int b) {
	int i, cursor = a-1;
	if (a < b) {		
		for (i = 1; i <= 2*b-1; i++) {
			if (i >= b-cursor && i <= b+cursor) printf(" * ");
			else printf("   ");
		}
		printf("\n");
		rombo(a+1,b);		
		for (i = 1; i <= 2*b-1; i++) {
			if (i >= b-cursor && i <= b+cursor) printf(" * ");
			else printf("   ");
		}
		printf("\n");
	} else if (a == b) {
		for (i = 1; i <= 2*b-1; i++) {
			if (i >= b-cursor && i <= b+cursor) printf(" * ");
			else printf("   ");
		}
		printf("\n");
	} else 	return;	
}

int main () {
	rombo(3,5);
}

