# include <stdio.h>
# include <math.h>

int main(void) {
	int N;
	double res;
	scanf("%d", &N);
	res=pow(0.5, N);
	printf("%.*lf\n", N, res);
	return 0;
}
