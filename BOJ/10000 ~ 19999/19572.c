# include <stdio.h>

int main(void) {
	int d1, d2, d3, sum;
	double a, b, c;
	scanf("%d%d%d", &d1, &d2, &d3);
	sum=d1+d2+d3;
	a=((double)sum-2*d3)/2;
	b=((double)sum-2*d2)/2;
	c=((double)sum-2*d1)/2;
	if(a>0&&b>0&&c>0)
		printf("1\n%.1lf %.1lf %.1lf", a, b, c);
	else
		puts("-1");
	return 0;
}
