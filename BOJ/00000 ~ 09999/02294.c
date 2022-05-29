# include <stdio.h>

int main(void) {
	int n, k, arr[100], i, j, dp[10001], min;
	for(i=0 ; i<=10000 ; i++)
		dp[i]=10001;
	scanf("%d%d", &n, &k);
	for(i=0 ; i<n ; i++) {
		scanf("%d", &arr[i]);
		if(arr[i]<=10000)
			dp[arr[i]]=1;
	}
	for(i=1 ; i<=k ; i++) {
		min=10001;
		for(j=0 ; j<n ; j++)
			if(i-arr[j]>=1&&dp[i-arr[j]]<min)
				min=dp[i-arr[j]]+1;
		dp[i]=min<dp[i]?min:dp[i];
	}
	printf("%d", dp[k]==10001?-1:dp[k]);
	return 0;
}
