#include <stdio.h>
#include <stdlib.h>

int a[][3]={ {0,1,5},
			 {1,2,3},
			 {2,4,-1},			 
			 {3,-1,-1},
			 {4,-1,-1},
			 {5,6,7},
			 {6,-1,-1},
			 {7,-1,-1}			 			 			 			 
			};

int first_ext(int c){
	return a[c][1];
}

int next_ext(int c){
	return a[c][2];
}

int bt (int c, int n){
	int act;
	if (c == n){
		printf("%d", c);
		return 1;
	} else {
		if (c==-1) return 0;
		else printf("%d", c);

		act = first_ext(c);
		if (bt(act, n) == 1) return 1;

		act = next_ext(c);
		if (bt(act, n) == 1) return 1;
	}
	return 0;
}


int main(){
	bt(0, 7);
	printf("\n");
	return 0;
}			