# include <stdio.h>
# include <math.h>
# define	PI	3.141592653589793

int main(void) {
	double S;
	scanf("%lf", &S);
	printf("%.7lf", 2*sqrt(S/PI)*PI);
	return 0;
}
