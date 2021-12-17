# include <stdio.h>

int main(void) {
	int coin[]={1, 2, 5, 7}, dp[100001]={0}, N, i, j, min;
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++)
		dp[i]=100000;
	dp[1]=dp[2]=dp[5]=dp[7]=1;
	for(i=3 ; i<=N ; i++) {
		min=99999;
		for(j=0 ; j<4 ; j++)
			if(i-coin[j]>=1&&dp[i-coin[j]]<min)
				min=dp[i-coin[j]];
		dp[i]=dp[i]<min+1?dp[i]:min+1;
	}
	printf("%d", dp[N]);
	return 0;
}
