# include <stdio.h>
# include <math.h>

int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int T, i, N, K, S;
	scanf("%d", &T);
	for(i=1 ; i<=T ; i++) {
		scanf("%d%d%d", &N, &K, &S);
		printf("Case #%d: %d\n", i, K-1+min(N+1, abs(K-S)+N-S+1));
	}
	return 0;
}
