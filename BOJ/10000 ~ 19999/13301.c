# include <stdio.h>

int main(void) {
	long long dp[80]={1, 1};
	int N, i;
	scanf("%d", &N);
	for(i=2 ; i<N ; i++)
		dp[i]=dp[i-1]+dp[i-2];
	if(N==1)
		puts("4");
	else
		printf("%lld", 2*dp[N-1]+2*(dp[N-1]+dp[N-2]));
	return 0;
}