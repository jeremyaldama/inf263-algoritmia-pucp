#include <stdio.h>

void merge(int A[],int ini,int med,int fin){
	int t1,t2,i,p,q;
	t1 = med-ini+1;
	t2 = fin-med;
	
	int P[t1];
	int Q[t2];
	
	for (i=ini;i<=med;i++)
		P[i-ini]=A[i];
		
	for (i=med+1;i<=fin;i++)
		Q[i-med-1]=A[i];
			
	P[t1]=9999999; Q[t2]=9999999;
	p=q=0;
	for (i=ini;i<=fin;i++)
		if (P[p]<Q[q])
			A[i] = P[p++];
		else
			A[i] = Q[q++];
}

void mergeSort(int A[], int ini,int fin){
	if (ini==fin) return;
	int med = (ini+fin)/2;
	
	mergeSort(A,ini,med);
	mergeSort(A,med+1,fin);
	merge(A,ini,med,fin);
}

int main(){
	int A[] = {11,2,7,1,6,3,2,9};
	int n=8,i;
	
	mergeSort(A,0,n-1);
	for (i=0;i<n;i++)
	printf("%d ",A[i]);
	return 0;
}
