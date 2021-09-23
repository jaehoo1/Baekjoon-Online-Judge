# include <stdio.h>

int main(void) {
	int N, i;
	long long arr[33333]={0, 2};
	scanf("%d", &N);
	for(i=2 ; i<N ; i++)
		arr[i]=(arr[i-1]*3)%1000000009;
	printf("%lld", arr[N-1]);
	return 0;
}
