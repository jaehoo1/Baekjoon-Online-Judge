# include <stdio.h>

int main(void) {
	int A, B, C, D, P, M, N, max, arr[2][999], i, j;
	scanf("%d%d%d%d%d%d%d", &A, &B, &C, &D, &P, &M, &N);
	max=P;
	if(M>max)max=M;
	if(N>max)max=N;
	for(i=0 ; i<max ; i++) {
		for(j=i ; j<A+i&&j<max ; j++)
			arr[0][j]=1;
		i=j;
		for(j=i ; j<B+i&&j<max ; j++)
			arr[0][j]=0;
		i=j-1;
	}
	for(i=0 ; i<max ; i++) {
		for(j=i ; j<C+i&&j<max ; j++)
			arr[1][j]=1;
		i=j;
		for(j=i ; j<D+i&&j<max ; j++)
			arr[1][j]=0;
		i=j-1;
	}
	printf("%d\n%d\n%d", arr[0][P-1]+arr[1][P-1], arr[0][M-1]+arr[1][M-1], arr[0][N-1]+arr[1][N-1]);
	return 0;
}
