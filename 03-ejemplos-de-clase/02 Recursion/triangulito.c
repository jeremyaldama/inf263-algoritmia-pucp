#include <stdio.h>

void  triangulo(int a, int b)
{	int i;
	if(a>b)
		return;
	if(a<=b)
	{
		for(i=0;i<a;i++)  //3
			printf(" * ");  
		printf("\n");
		triangulo(a+1,b);	//4
		for(i=0;i<a;i++)  //  3
			printf(" * ");  
		printf("\n");

	}

}



int main()
{	
	triangulo(3,5);
	
}
