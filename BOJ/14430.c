# include <stdio.h>

int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int N, M, i, j, arr[300][300], dp[300][300]={0, }, res=0;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			scanf("%d", &arr[i][j]);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			if(!i&&!j)
				dp[i][j]=arr[i][j];
			else if(!i)
				dp[i][j]=dp[i][j-1]+arr[i][j];
			else if(!j)
				dp[i][j]=dp[i-1][j]+arr[i][j];
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1])+arr[i][j];
	for(i=0 ; i<M ; i++)
		if(dp[N-1][i]>res)
			res=dp[N-1][i];
	printf("%d", res);
	return 0;
}
