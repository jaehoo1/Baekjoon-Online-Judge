# include <stdio.h>

int main(void) {
	int T, N, G[10001], i, cur;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(i=1 ; i<=N ; i++)
			scanf("%d", &G[i]);
		for(cur=1, i=0 ; i<=10000&&cur!=N ; i++)
			cur=G[cur];
		printf("%d\n", cur==N?i:0);
	}
	return 0;
}