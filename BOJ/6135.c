# include <stdio.h>
# define	INF	1e9

int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int N, M, T, G[301][301], S, E, H, A, B, i, j, k;
	scanf("%d%d%d", &N, &M, &T);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			G[i][j]=i==j?0:INF;
	while(M--) {
		scanf("%d%d%d", &S, &E, &H);
		G[S][E]=H;
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(max(G[i][k], G[k][j])<G[i][j])
					G[i][j]=max(G[i][k], G[k][j]);
	while(T--) {
		scanf("%d%d", &A, &B);
		printf("%d\n", G[A][B]==INF?-1:G[A][B]);
	}
	return 0;
}
