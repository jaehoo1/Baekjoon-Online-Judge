# include <stdio.h>

int main(void) {
	int A, B, C, N, a, b, c, i, sum, max=0;
	scanf("%d%d%d%d", &A, &B, &C, &N);
	while(N--) {
		sum=0;
		for(i=0 ; i<3 ; i++) {
			scanf("%d%d%d", &a, &b, &c);
			sum+=a*A;
			sum+=b*B;
			sum+=c*C;
		}
		if(sum>max)
			max=sum;
	}
	printf("%d", max);
	return 0;
}
