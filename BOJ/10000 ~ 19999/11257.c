# include <stdio.h>

int main(void) {
	int N;
	char str[9];
	double a, b, c, A=(double)35*3/10, B=(double)25*3/10, C=(double)40*3/10;
	scanf("%d", &N);
	while(N--) {
		scanf("%s%lf%lf%lf", str, &a, &b, &c);
		printf("%s %d ", str, (int)(a+b+c));
		if(a>=A&&b>=B&&c>=C&&a+b+c>=55)
			puts("PASS");
		else
			puts("FAIL");
	}
	return 0;
}