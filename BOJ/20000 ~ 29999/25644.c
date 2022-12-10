# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }
int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int N, arr[200000], dp[200000], i, res=0;
	scanf("%d%d", &N, &arr[i]);
	dp[0]=arr[0];
	for(i=1 ; i<N ; i++) {
		scanf("%d", &arr[i]);
		dp[i]=min(arr[i], dp[i-1]);
	}
	for(i=1 ; i<N ; i++)
		res=max(res, arr[i]-dp[i]);
	printf("%d", res);
	return 0;
}