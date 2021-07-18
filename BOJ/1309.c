# include <stdio.h>

int main(void) {
	int dp[100001]={0, 3, 7}, N, i;
	scanf("%d", &N);
	for(i=3 ; i<=N ; i++)
		dp[i]=(dp[i-2]+(dp[i-1]*2)%9901)%9901;
	printf("%d", dp[N]);
	return 0;
}
