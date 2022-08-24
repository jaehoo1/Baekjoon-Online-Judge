# include <stdio.h>

int main(void) {
	int T, n, N, M;
	scanf("%d", &T);
	for(n=1 ; n<=T ; n++) {
		scanf("%d%d", &N, &M);
		printf("Case %d: %d\n", n, M-N+1);
	}
	return 0;
}