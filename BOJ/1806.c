# include <stdio.h>

int main(void) {
	int N, S, arr[100000], start=0, end=0, sum=0, min=100001, i;
	scanf("%d%d", &N, &S);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	while(end<=N)
		if(sum>=S) {
			if(end-start<min)
				min=end-start;
			sum-=arr[start++];
		}
		else if(sum<S)
			sum+=arr[end++];
	if(min!=100001)
		printf("%d", min);
	else
		puts("0");
	return 0;
}
