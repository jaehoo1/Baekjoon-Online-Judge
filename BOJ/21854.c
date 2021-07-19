# include <stdio.h>

long long power(long long x, long long n) {
	if(!n)return 1;
	else if(n==1)return x;
	else if(n%2)return (x*power((x*x)%1000000007, n/2))%1000000007;
	return power((x*x)%1000000007, n/2)%1000000007;
}

int main(void) {
	int N, K;
	long long sum=0;
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &K);
		sum+=power(2, K);
		sum%=1000000007;
	}
	printf("%lld", sum);
	return 0;
}
