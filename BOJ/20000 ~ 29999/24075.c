# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }
int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	printf("%d\n", max(A+B, A-B));
	printf("%d", min(A+B, A-B));
	return 0;
}