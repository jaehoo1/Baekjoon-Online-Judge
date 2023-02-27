# include <stdio.h>

int main(void) {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	if(A+B==C||A+C==B||B+C==A)
		puts("1");
	else if(A*B==C||A*C==B||B*C==A)
		puts("2");
	else
		puts("3");
	return 0;
}