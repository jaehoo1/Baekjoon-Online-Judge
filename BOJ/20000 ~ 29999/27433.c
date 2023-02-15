# include <stdio.h>

long long fact(int n) {
	long long res=1, i;
	for(i=2 ; i<=n ; i++)
		res*=i;
	return res;
}

int main(void) {
	int N;
	scanf("%d", &N);
	printf("%lld", fact(N));
	return 0;
}