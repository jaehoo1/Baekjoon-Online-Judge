# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int n, i, dp[100001]={-1, -1, 1, -1, 2, 1};
	scanf("%d", &n);
	for(i=6 ; i<=n ; i++)
		if(dp[i-5]!=-1&&dp[i-2]!=-1)
			dp[i]=min(dp[i-5], dp[i-2])+1;
		else if(dp[i-5]==-1)
			dp[i]=dp[i-2]+1;
		else if(dp[i-2]==-1)
			dp[i]=dp[i-5]+1;
	printf("%d", dp[n]);
	return 0;
}