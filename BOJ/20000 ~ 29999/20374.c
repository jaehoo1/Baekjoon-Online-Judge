# include <stdio.h>

int main(void) {
	int dec, point, sum2=0;
	long long sum1=0;
	while(~scanf("%d.%d", &dec, &point)) {
		sum1+=dec;
		sum2+=point;
	}
	sum1+=sum2/100;
	sum2%=100;
	printf("%lld.", sum1);
	if(sum2<10)
		printf("0");
	printf("%d", sum2);
	return 0;
}