# include <stdio.h>

int main(void) {
	int N, A[1000], dp[1000], i, j, max=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &A[i]);
		dp[i]=1;
	}
	for(i=1 ; i<N ; i++) {
		for(j=0 ; j<i ; j++)
			if(A[i]>A[j]&&dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
	}
	for(i=0 ; i<N ; i++)
		if(dp[i]>max)
			max=dp[i];
	printf("%d", max);
	return 0;
}
