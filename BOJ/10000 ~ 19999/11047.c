# include <stdio.h>

int main(void) {
	int N, K, A[10], i, coin=0;
	scanf("%d%d", &N, &K);
	for(i=0 ; i<N ; i++)
		scanf("%d", &A[i]);
	for(i=N-1 ; i>=0&&K ; i--)
		if(K>=A[i]) {
			coin+=K/A[i];
			K%=A[i];
		}
	printf("%d", coin);
	return 0;
}