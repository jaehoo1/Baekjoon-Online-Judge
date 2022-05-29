# include <stdio.h>

int main(void) {
	int N, K, i, arr[100000], sum=0, start=0, end, max=-10000001;
	scanf("%d%d", &N, &K);
	end=K;
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	for(i=0 ; i<K ; i++)
		sum+=arr[i];
	if(sum>max)
		max=sum;
	while(end!=N) {
		sum-=arr[start++];
		sum+=arr[end++];
		if(sum>max)
			max=sum;
	}
	printf("%d", max);
	return 0;
}
