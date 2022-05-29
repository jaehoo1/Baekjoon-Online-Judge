# include <stdio.h>

int main(void) {
	int N, i, max=1, arr[100000], dp1[100000]={1, }, dp2[100000]={1, };
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	for(i=1 ; i<N ; i++) {
		dp1[i]=arr[i]>=arr[i-1]?dp1[i-1]+1:1;
		if(dp1[i]>max)
			max=dp1[i];
	}
	for(i=1 ; i<N ; i++) {
		dp2[i]=arr[i]<=arr[i-1]?dp2[i-1]+1:1;
		if(dp2[i]>max)
			max=dp2[i];
	}
	printf("%d", max);
	return 0;
}
