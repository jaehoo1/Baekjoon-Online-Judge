# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int N, A[1000000], i, res=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &A[i]);
		if(A[i]>res)
			res=A[i];
	}
	for(i=1 ; i<N-1 ; i++)
		if(min(A[i-1], A[i+1])+A[i]>res)
			res=min(A[i-1], A[i+1])+A[i];
	printf("%d", res);
	return 0;
}
