# include <stdio.h>

int main(void) {
	int N, i;
	long long dp[91]={0, 1, 1};
	scanf("%d", &N);
	for(i=3 ; i<=N ; i++)
		dp[i]=dp[i-1]+dp[i-2];
	printf("%lld", dp[N]);
	return 0;
}
