# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int N, arr[1000][3], dp[1000][3], i, j;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<3 ; j++)
			scanf("%d", &arr[i][j]);
	for(i=0 ; i<3 ; i++)
		dp[0][i]=arr[0][i];
	for(i=1 ; i<N ; i++)
		for(j=0 ; j<3 ; j++) {
			if(j==0)
				dp[i][j]=min(dp[i-1][1], dp[i-1][2]);
			else if(j==1)
				dp[i][j]=min(dp[i-1][0], dp[i-1][2]);
			else if(j==2)
				dp[i][j]=min(dp[i-1][0], dp[i-1][1]);
			dp[i][j]+=arr[i][j];
		}
	printf("%d", min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2])));
	return 0;
}
