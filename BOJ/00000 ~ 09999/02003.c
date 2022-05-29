# include <stdio.h>

int main(void) {
	int N, M, arr[10000], start=0, end=0, sum=0, cou=0, i;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	while(end<=N) {
		if(sum>=M)
			sum-=arr[start++];
		else if(sum<M)
			sum+=arr[end++];
		if(sum==M)
			cou++;
	}
	printf("%d", cou);
	return 0;
}
