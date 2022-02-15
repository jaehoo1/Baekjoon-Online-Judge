# include <stdio.h>

int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int N, i, arr[300], dp[300];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	dp[0]=arr[0];
	dp[1]=arr[0]+arr[1];
	dp[2]=max(arr[0], arr[1])+arr[2];
	for(i=3 ; i<N ; i++)
		dp[i]=max(dp[i-3]+arr[i-1], dp[i-2])+arr[i];
	printf("%d", dp[N-1]);
	return 0;
}
