# include <stdio.h>

int main(void) {
	int N, A[1000], dp[1000], parent[1000], i, j, max=0, p;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &A[i]);
		dp[i]=1;
		parent[i]=i;
	}
	for(i=1 ; i<N ; i++)
		for(j=0 ; j<i ; j++)
			if(A[i]>A[j]&&dp[i]<dp[j]+1) {
				dp[i]=dp[j]+1;
				parent[i]=j;
			}
	for(i=0 ; i<N ; i++)
		if(dp[i]>max) {
			max=dp[i];
			p=i;
		}
	printf("%d\n", max);
	for(i=0 ; i<max ; i++) {
		dp[i]=p;
		p=parent[p];
	}
	for(i=max-1 ; i!=-1 ; i--)
		printf("%d ", A[dp[i]]);
	return 0;
}
