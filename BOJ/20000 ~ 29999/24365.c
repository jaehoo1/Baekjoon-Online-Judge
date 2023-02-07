# include <stdio.h>
# define	avg	(A+B+C)/3

int main(void) {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	printf("%d", (avg-A)*2+avg-B);
	return 0;
}