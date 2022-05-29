# include <stdio.h>

int main(void) {
	double k;
	scanf("%lf", &k);
	k=k*0.01+25;
	if(k>2000)k=2000;
	if(k<100)k=100;
	printf("%.2lf", k);
	return 0;
}
