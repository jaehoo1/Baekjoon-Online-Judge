# include <stdio.h>

int main(void) {
	int N;
	double P, C;
	scanf("%d", &N);
	while(N--) {
		scanf("%lf%lf", &P, &C);
		printf("%lf\n", P/(C+100)*100);
	}
	return 0;
}
