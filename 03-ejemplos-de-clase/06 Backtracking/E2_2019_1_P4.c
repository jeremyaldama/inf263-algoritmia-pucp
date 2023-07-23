#include <stdio.h>
#define N 8

void solveBoard();
int solveBoardUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);
int isSafe(int x, int y, int sol[N][N]);
void print_solution(int sol[N][N]);

int main(){
	solveBoard();
	return 0;
}

void solveBoard(){
	int sol[N][N], x, y;
	for (x=0; x<N; x++){
		for (y=0; y<N; y++)
			sol[x][y] = -1;
	}

	int xMove[8]={2,1,-1,-2,-2,-1, 1, 2};
	int yMove[8]={1,2,2 ,1 ,-1,-2,-2,-1};

	sol[0][0] = 0;

	if (solveBoardUtil(0,0, 1, sol, xMove, yMove) == 0){
		printf("No hay solución\n");
	} else {
		print_solution(sol);
	}
}

int solveBoardUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]){
	int k, next_x, next_y;

	if (movei == N*N)
		return 1;

	for (k=0; k<8; k++){
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)){
			sol[next_x][next_y] = movei;
			if (solveBoardUtil(next_x, next_y, movei+1, sol, xMove, yMove) == 1)
				return 1;
			else
				sol[next_x][next_y] = -1; //backtracking
		}
	}
	return 0;
}

int isSafe(int x, int y, int sol[N][N]){
	return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

void print_solution(int sol[N][N]){
	int i, j;
	for (i=0; i<N; i++){
		for (j=0; j<N; j++)
			printf("%d ", sol[i][j]);
		printf("\n");
	}
}