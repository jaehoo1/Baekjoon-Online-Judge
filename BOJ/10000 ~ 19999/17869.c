# include <stdio.h>

int main(void) {
	long long n;
	int cou=0;
	scanf("%lld", &n);
	while(n!=1) {
		if(n%2)n++;
		else	n/=2;
		cou++;
	}
	printf("%d", cou);
	return 0;
}
