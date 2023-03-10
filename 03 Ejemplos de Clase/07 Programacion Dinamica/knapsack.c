#include <stdio.h>

int max(int v1, int v2);
void knapsackDP(int n, int w[n], double v[n], double V[n+1][n+2]);

int main(){
	int i, j, n = 4;
	int w[]={2, 1, 3, 2};
	double v[]={12, 10, 20, 15};

	double V[n+1][n+2];

	knapsackDP(n, w, v, V);

	printf ("Máximo valor: %.2lf\n", V[n][n+1]);

	for (i=0; i<n+1; i++){
		for (j=0; j<n+2; j++){
			printf("%.2lf ", V[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void knapsackDP(int n, int w[n], double v[n], double V[n+1][n+2]){
	int i, j;

	for (j=0; j<n+2; j++) V[0][j] = 0;
	for (i=0; i<n+1; i++) V[i][0] = 0;		

	for (j=1; j<n+2; j++){
		for (i=1; i<n+1; i++){
			if (j - w[i-1] >= 0)
				V[i][j] = max(V[i-1][j], v[i-1] + V[i-1][j - w[i-1]]);
			else
				V[i][j] = V[i-1][j];
		}
	}
}

int max(int v1, int v2){
	return (v1 > v2 ? v1 : v2);
}