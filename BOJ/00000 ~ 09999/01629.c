# include <stdio.h>
# define	LL	long long

LL C;

int power(LL x, const LL n) {
	x%=C;
	if(n==1)return x;
	if(n%2)return (x*power((x*x)%C, n/2))%C;
	return power((x*x)%C, n/2)%C;
}

int main(void) {
	LL A, B;
	scanf("%lld%lld%lld", &A, &B, &C);
	printf("%d", power(A, B)%C);
	return 0;
}
