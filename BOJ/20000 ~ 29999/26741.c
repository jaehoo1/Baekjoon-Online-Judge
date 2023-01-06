# include <stdio.h>

int main(void) {
	int X, Y, A, B;
	scanf("%d%d", &X, &Y);
	B=(Y-2*X)/2;
	A=X-B;
	printf("%d %d", A, B);
	return 0;
}