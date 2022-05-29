# include <stdio.h>

int main(void) {
	int N;
	double a, b, c;
	scanf("%d", &N);
	while(N--) {
		scanf("%lf%lf%lf", &a, &b, &c);
		if(a+b==c||a-b==c||b-a==c||a*b==c||a/b==c||b/a==c)
			puts("Possible");
		else
			puts("Impossible");
	}
	return 0;
}
