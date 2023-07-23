#include <stdio.h>

void encontrarNoRepetido(int *entrada, int ini, int fin){
	int med = (ini+fin)/2;
	if (ini==fin) {
		printf("El elemento que aparece una sola vez es %d\n",
			entrada[ini]);
			return;
	}
	
	if (med%2!=0){
		if (entrada[med]!=entrada[med-1]){
			encontrarNoRepetido(entrada, ini, med-1);
		}
		else{
			encontrarNoRepetido(entrada, med+1, fin);
		}
	}
	else{
		if (entrada[med]==entrada[med+1]){
			encontrarNoRepetido(entrada, med+2, fin);
		}
		else{
			encontrarNoRepetido(entrada, ini, med);
		}
	}
}

int main(){
	int entrada[] = {1,1,3,3,4,4,5,5,7,7,8,8,9};
	int n = 13;
	encontrarNoRepetido(entrada, 0, n-1);
	return 0;
}
