# include <stdio.h>

int main(void) {
	long long k, a, b, c, d;
	scanf("%lld%lld%lld%lld%lld", &k, &a, &b, &c, &d);
	if(a*k+b==c*k+d)
		printf("Yes %lld", a*k+b);
	else
		puts("No");
	return 0;
}