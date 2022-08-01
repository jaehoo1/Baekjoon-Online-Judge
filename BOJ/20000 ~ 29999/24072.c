# include <stdio.h>

int main(void) {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	if(C>=A&&C<B)
		puts("1");
	else
		puts("0");
	return 0;
}