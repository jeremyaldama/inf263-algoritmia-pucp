#include <stdio.h>

int main(){
	int largo=4, ancho=3, alt=2;
	int meteorito[][ancho][largo] = {
									 {
									  {0,0,0,0},
									  {0,0,0,0},
									  {0,0,0,0}},
									  
									 {{0,0,0,0},
									  {0,0,1,0},
									  {0,0,0,0}}
									    };
	printf("METEORITO %d\n",meteorito[1][1][2]); 
	return 0;
}
