# include <stdio.h>
# define	INF	9999

int main(void) {
	int N, M, A, B, dp[101][101], i, j, k, min=INF, idx, sum;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			dp[i][j]=i==j?0:INF;
	while(M--) {
		scanf("%d%d", &A, &B);
		dp[A][B]=1;
		dp[B][A]=1;
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(dp[i][k]+dp[k][j]<dp[i][j])
					dp[i][j]=dp[i][k]+dp[k][j];
	for(i=1 ; i<=N ; i++) {
		sum=0;
		for(j=1 ; j<=N ; j++)
			sum+=dp[i][j];
		if(sum<min) {
			min=sum;
			idx=i;
		}
	}
	printf("%d", idx);
	return 0;
}
