# include <stdio.h>

int main(void) {
	int N, i, j, arr[1000], dp[1000], max=0, temp, idx;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	dp[0]=arr[0];
	for(i=1 ; i<N ; i++) {
		temp=0;
		for(j=0 ; j<i ; j++)
			if(dp[j]>temp&&arr[i]>arr[j]) {
				temp=dp[j];
				idx=j;
			}
		dp[i]=temp+arr[i];
	}
	for(i=0 ; i<N ; i++)
		if(dp[i]>max)
			max=dp[i];
	printf("%d", max);
	return 0;
}
