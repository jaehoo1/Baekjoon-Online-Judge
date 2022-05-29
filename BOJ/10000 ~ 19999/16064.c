# include <stdio.h>
# define	INF	1e9

int main(void) {
	int dp[1001][1001], n, m, s, t, c, i, j, k, max=0;
	scanf("%d%d", &n, &m);
	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=n ; j++)
			dp[i][j]=INF;
	while(m--) {
		scanf("%d%d%d", &s, &t, &c);
		if(dp[s][t]==INF)
			dp[s][t]=c;
		else if(c>dp[s][t])
			dp[s][t]=c;
	}
	for(k=1 ; k<=n ; k++)
		for(i=1 ; i<=n ; i++)
			for(j=1 ; j<=n ; j++)
				if(dp[i][k]!=INF&&dp[k][j]!=INF)
					if(dp[i][j]==INF)
						dp[i][j]=dp[i][k]+dp[k][j];
					else if(dp[i][j]<dp[i][k]+dp[k][j])
						dp[i][j]=dp[i][k]+dp[k][j];
	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=n ; j++)
			if(dp[i][j]!=INF&&dp[i][j]>max)
				max=dp[i][j];
	printf("%d", max);
	return 0;
}
