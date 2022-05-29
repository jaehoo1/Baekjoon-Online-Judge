# include <stdio.h>

int main(void) {
	long a, b;
	scanf("%ld%ld", &a, &b);
	if(a%2&&b%2)
		printf("%ld", a<b?a:b);
	else
		puts("0");
	return 0;
}
