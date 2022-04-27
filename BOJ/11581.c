# include <stdio.h>
# define	INF	-1

int main(void) {
	int N, M, C, G[101][101], i, j, k;
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			G[i][j]=INF;
	for(i=1 ; i<N ; i++) {
		scanf("%d", &M);
		while(M--) {
			scanf("%d", &C);
			G[i][C]=1;
		}
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]!=INF&&G[k][j]!=INF)
					G[i][j]=1;
	for(i=1 ; i<=N ; i++)
		if(G[1][i]!=INF&&G[i][i]!=INF) {
			puts("CYCLE");
			return 0;
		}
	puts("NO CYCLE");
	return 0;
}
