# include <stdio.h>

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	printf("%d", N/2<M/2?N/2:M/2);
	return 0;
}
