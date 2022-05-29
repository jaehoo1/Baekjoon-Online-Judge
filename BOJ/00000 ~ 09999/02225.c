# include <stdio.h>

int N, K;
long long dp[201][201];

long long dfs(int depth, int sum) {
	int i;
	long long cnt=0;
	if(depth==K)
		return sum==N?1:0;
	if(dp[depth][sum])
		return dp[depth][sum];
	for(i=0 ; i<=N ; i++)
		if(sum+i<=N)
			cnt=(cnt+dfs(depth+1, sum+i))%1000000000;
	return dp[depth][sum]=cnt;
}

int main(void) {
	scanf("%d%d", &N, &K);
	printf("%lld", dfs(0, 0));
	return 0;
}
