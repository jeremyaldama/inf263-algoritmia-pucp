#include "stdio.h"

int solve_sudoku(int [][9], int row, int col);
int es_viable(int [][9], int row, int col, int num);

int main (){
	int i, j;
	int sudoku[9][9]= { {3, 0, 6, 5, 0, 8, 4, 0, 0},
						{5, 2, 0, 0, 0, 0, 0, 0, 0},
						{0, 8, 7, 0, 0, 0, 0, 3, 1},
						{0, 0, 3, 0, 1, 0, 0, 8, 0},
						{9, 0, 0, 8, 6, 3, 0, 0, 5},
						{0, 5, 0, 0, 9, 0, 6, 0, 0},
						{1, 3, 0, 0, 0, 0, 2, 5, 0},
						{0, 0, 0, 0, 0, 0, 0, 7, 4},
						{0, 0, 5, 2, 0, 6, 3, 0, 0}
						};

	if (solve_sudoku(sudoku, 0, 0)){
		for (i=0; i<9; i++){
			for (j=0; j<9; j++)
				printf("%d ", sudoku[i][j]);
			printf("\n");
		}
	} else 
		printf("No se logró resolver el Sudoku!\n");					
	return 0;
}

int solve_sudoku(int sudoku[][9], int row, int col){
	int i;
	if (row<9 && col<9){
		if (sudoku[row][col] != 0){
			if ( (col+1) < 9 )
				return solve_sudoku(sudoku, row, col+1);
			else if ( (row+1) < 9)
				return solve_sudoku(sudoku, row+1, 0);
			else return 1;
		} else {
			for (i=0; i<9; i++){
				if (es_viable(sudoku, row, col, i+1)){
					sudoku[row][col] = i+1;

					if ( (col+1) < 9) {
						if (solve_sudoku(sudoku, row, col + 1 ))
							return 1;
						else 
							sudoku[row][col] = 0;
					} else if ( (row+1)<9 ){
						if (solve_sudoku(sudoku, row+1, 0))
							return 1;
						else 
							sudoku[row][col] = 0;						
					} else
						return 1;
				}
			}
		}
		return 0;
	} else {
		return 1;
	}	
}

int es_viable(int sudoku[][9], int row, int col, int num){
	int i, j;
	for (i=0; i<9; i++)
		if ((sudoku[row][i] == num) || (sudoku[i][col] == num) )
			return 0;

	int row_start = (row/3) * 3;
	int col_start = (col/3) * 3;

	for (i=row_start; i < (row_start+3); i++)
		for (j=col_start; j < (col_start+3); j++)
			if (sudoku[i][j] == num)
				return 0;

	return 1;		
}
