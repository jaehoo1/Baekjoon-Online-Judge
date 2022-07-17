# include <stdio.h>

int main(void) {
	int n;
	char op;
	long long a, b, pre=1;
	scanf("%d", &n);
	while(n--) {
		scanf("%lld %c %lld", &a, &op, &b);
		if(op=='+')
			pre=a+b-pre;
		else if(op=='-')
			pre=(a-b)*pre;
		else if(op=='*')
			pre=a*b*a*b;
		else if(op=='/')
			if(a%2)
				pre=(a+1)/2;
			else
				pre=a/2;
		printf("%lld\n", pre);
	}
	return 0;
}