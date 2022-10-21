//Recursion
#include <stdio.h>

int producto(int x, int y){
	if(x==0 || y==0) return 0;
	else 
		return (y+producto(x-1,y));
}

int main(){
	int x, y; 
	printf("Ingreso x e y:");
	scanf("%d %d", &x, &y);
	printf("%d", producto(x, y));
	return 0;
}
