#include <stdio.h>
#include <math.h>

int karatsuba(int num1, int num2){
	if (num1<10 || num2<10) return num1*num2;
	int a, b, c, d, ac, bd, ad_mas_bc;
	char str1[20], str2[20];
	int n1 = log10(num1)+1;
	int n2 = log10(num2)+1;
	int mid = n1>n2? n1/2: n2/2; 
	a = num1 / pow(10, mid);
	b = num1 % (int)pow(10, mid);
	c = num2 / pow(10, mid);
	d = num2 % (int)pow(10, mid);
	ac = karatsuba(a, c);
	bd = karatsuba(b, d);
	ad_mas_bc = karatsuba(a+b, c+d)-ac-bd;
	return ac * (pow(10, 2*mid)) + ad_mas_bc * pow(10, mid) + bd;
}

int main(){
	int a, b;
	printf("Ingrese a: ");
	scanf("%d", &a);
	printf("Ingrese b: ");
	scanf("%d", &b);
	printf("La multiplicacion es %d\n", karatsuba(a, b));
}
