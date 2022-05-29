# include <stdio.h>

int main(void) {
	int N, A[1000], i, j, dp[2][1000];	//0행 :	넣은 수들의 최소값	1행 : 합
	int max, idx;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &A[i]);
	dp[0][0]=dp[1][0]=A[0];
	for(i=1 ; i<N ; i++) {
		max=0;
		for(j=0 ; j<i ; j++)
			if(dp[0][j]>A[i]&&dp[1][j]>max) {
				idx=j;
				max=dp[1][j];
			}
		dp[0][i]=A[i];
		dp[1][i]=max+A[i];
	}
	max=0;
	for(i=0 ; i<N ; i++)
		if(dp[1][i]>max)
			max=dp[1][i];
	printf("%d", max);
	return 0;
}
