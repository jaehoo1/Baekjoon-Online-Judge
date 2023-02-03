# include <stdio.h>

int main(void) {
	int N, H, B, K, cost=0;
	scanf("%d", &N);
	while(N--) {
		scanf("%d%d%d", &H, &B, &K);
		cost+=B>H?K*(B-H):0;
	}
	printf("%d", cost);
	return 0;
}