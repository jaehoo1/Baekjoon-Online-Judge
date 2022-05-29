# include <stdio.h>

int main(void) {
	long long dp[1000000]={1, 2, 4};
	int T, n, i;
	for(i=3 ; i<1000000 ; i++)
		dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n-1]);
	}
	return 0;
}
