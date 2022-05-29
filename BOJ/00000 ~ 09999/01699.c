# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int N, i, j, dp[100001];
	scanf("%d", &N);
	for(i=0 ; i<=N ; i++)
		dp[i]=i;
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j*j<=i ; j++)
			dp[i]=min(dp[i], dp[i-j*j]+1);
	printf("%d", dp[N]);
	return 0;
}
