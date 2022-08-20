# include <stdio.h>

int main(void) {
	int n, dp[41]={0, 1}, i;
	for(i=2 ; i<=40 ; i++)
		dp[i]=dp[i-1]+dp[i-2];
	scanf("%d", &n);
	printf("%d %d", dp[n], n-2);
	return 0;
}