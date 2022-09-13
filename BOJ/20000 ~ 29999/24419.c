# include <stdio.h>

int main(void) {
	int n, i, j;
	long long dp[1001][1001];
	scanf("%d", &n);
	for(i=0 ; i<=n ; i++)
		for(j=0 ; j<=n ; j++)
			if(!i||!j)
				dp[i][j]=1;
			else
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
	printf("%lld %d", dp[n][n], n*n);
	return 0;
}