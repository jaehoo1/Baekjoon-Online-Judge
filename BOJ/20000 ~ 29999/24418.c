# include <stdio.h>

int main(void) {
	int n, dp[16][16], i, j;
	scanf("%d", &n);
	for(i=0 ; i<=n ; i++)
		for(j=0 ; j<=n ; j++)
			if(!i||!j)
				dp[i][j]=1;
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
	printf("%d %d", dp[n][n], n*n);
	return 0;
}
