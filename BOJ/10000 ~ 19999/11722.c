# include <stdio.h>

int main(void) {
	int N, i, j, arr[1000], dp[1000]={1, }, max;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	for(i=1 ; i<N ; i++) {
		max=0;
		for(j=0 ; j<i ; j++)
			if(dp[j]>max&&arr[i]<arr[j])
				max=dp[j];
		dp[i]=max+1;
	}
	max=0;
	for(i=0 ; i<N ; i++)
		if(dp[i]>max)
			max=dp[i];
	printf("%d", max);
	return 0;
}
