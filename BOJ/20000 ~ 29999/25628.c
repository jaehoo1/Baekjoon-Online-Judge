# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	printf("%d", min(A/2, B));
	return 0;
}