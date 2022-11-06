# include <stdio.h>

int main(void) {
	int n, k, r, i;
	double sum=0, max, min;
	scanf("%d%d", &n, &k);
	for(i=0 ; i<k ; i++) {
		scanf("%d", &r);
		sum+=r;
	}
	max=sum+3*(n-k);
	min=sum-3*(n-k);
	printf("%lf %lf", min/n, max/n);
	return 0;
}