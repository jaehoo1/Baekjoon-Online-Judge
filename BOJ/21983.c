# include <stdio.h>
# include <math.h>

int main(void) {
	double a;
	scanf("%lf", &a);
	printf("%.7lf", sqrt(((a/6)/sqrt(3))*4)*6);
	return 0;
}
