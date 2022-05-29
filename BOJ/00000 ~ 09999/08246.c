# include <stdio.h>

int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int A, B, K;
	scanf("%d%d%d", &A, &B, &K);
	printf("%d", (A/K)*(B/K)-max(0, A/K-2)*max(0, B/K-2));
	return 0;
}
