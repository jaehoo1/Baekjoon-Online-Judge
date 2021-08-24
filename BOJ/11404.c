# include <stdio.h>
# define	INF	2147483647
int main(void) {
	int n, m, a, b, c, dp[101][101];
	scanf("%d%d", &n, &m);
	for(a=1 ; a<=n ; a++)
		for(b=1 ; b<=n ; b++)
			dp[a][b]=a==b?0:INF;
	while(m--) {
		scanf("%d%d%d", &a, &b, &c);
		if(dp[a][b]>c)
			dp[a][b]=c;
	}
	for(c=1 ; c<=n ; c++)
		for(a=1 ; a<=n ; a++)
			for(b=1 ; b<=n ; b++)
				if(dp[a][c]!=INF&&dp[c][b]!=INF&&dp[a][c]+dp[c][b]<dp[a][b])
					dp[a][b]=dp[a][c]+dp[c][b];
	for(a=1 ; a<=n ; a++) {
		for(b=1 ; b<=n ; b++)
			printf("%d ", dp[a][b]==INF?0:dp[a][b]);
		puts("");
	}
	return 0;
}
