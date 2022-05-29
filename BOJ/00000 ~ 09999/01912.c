# include <stdio.h>

int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int n, i, arr[100000], dp[100000], res;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		scanf("%d", &arr[i]);
	res=dp[0]=arr[0];
	for(i=1 ; i<n ; i++) {
		dp[i]=max(dp[i-1]+arr[i], arr[i]);
		if(dp[i]>res)
			res=dp[i];
	}
	printf("%d", res);
	return 0;
}
