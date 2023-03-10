#include <stdio.h>
#include <math.h>

int max(int array[], int ini, int end){
	if (ini == end) return array[end]; else return (array[ini] > max(array, ini+1, end) ? array[ini] : max(array, ini+1, end));
	//{
		//int max_element_sub = max(array, ini+1, end); //La llamada recursiva
		//return (array[ini] > max_element_sub ? array[ini] : max_element_sub);
		
	//}
}

int main(){
	int array[] = {5, 4, 6, 20, 8, 1, 7};
	int size = 7;
	printf("El maximo elemento es %d\n.", max(array, 0, size-1));
	return 0;
}

