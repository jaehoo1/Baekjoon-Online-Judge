# include <stdio.h>

int main(void) {
	int N, M, arr[1001][1001]={0, }, dp[1001][1001]={0, }, i, j, temp;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=M ; j++)
			scanf("%d", &arr[i][j]);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=M ; j++) {
			temp=dp[i-1][j-1];
			if(temp<dp[i-1][j])
				temp=dp[i-1][j];
			if(temp<dp[i][j-1])
				temp=dp[i][j-1];
			dp[i][j]=temp+arr[i][j];
		}
	printf("%d", dp[N][M]);
	return 0;
}
