# include <stdio.h>

int main(void) {
	int X, N, a, b, sum=0;
	scanf("%d%d", &X, &N);
	while(N--) {
		scanf("%d%d", &a, &b);
		sum+=a*b;
	}
	puts(sum==X?"Yes":"No");
	return 0;
}