# include <stdio.h>

int main(void) {
	int N;
	double q, y, sum=0;
	scanf("%d", &N);
	while(N--) {
		scanf("%lf%lf", &q, &y);
		sum+=q*y;
	}
	printf("%.4lf", sum);
	return 0;
}
