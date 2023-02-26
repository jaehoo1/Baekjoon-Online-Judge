# include <stdio.h>
# include <math.h>

int main(void) {
	double a, b, c;
	int n;
	scanf("%d", &n);
	while(n--) {
		scanf("%lf%lf%lf", &a, &b, &c);
		printf("%.3lf, %.3lf\n", (-b+sqrt(pow(b, 2)-4*a*c))/2/a, (-b-sqrt(pow(b, 2)-4*a*c))/2/a);
	}
	return 0;
}