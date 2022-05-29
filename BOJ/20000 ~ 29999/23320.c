# include <stdio.h>

int main(void) {
	int N, A[100], X, Y, i, cou=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &A[i]);
	scanf("%d%d", &X, &Y);
	for(i=0 ; i<N ; i++)
		if(A[i]>=Y)
			cou++;
	printf("%d %d", N*X/100, cou);
	return 0;
}
