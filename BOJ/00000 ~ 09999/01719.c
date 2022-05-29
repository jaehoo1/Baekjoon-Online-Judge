# include <stdio.h>
# define	INF	1e9

int main(void) {
	int n, m, i, j, k, G[201][201], route[201][201];
	scanf("%d%d", &n, &m);
	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=n ; j++)
			G[i][j]=i==j?0:INF;
	while(m--) {
		scanf("%d%d%d", &i, &j, &k);
		G[i][j]=k;
		G[j][i]=k;
		route[i][j]=j;
		route[j][i]=i;
	}
	for(k=1 ; k<=n ; k++)
		for(i=1 ; i<=n ; i++)
			for(j=1 ; j<=n ; j++)
				if(G[i][k]+G[k][j]<G[i][j]) {
					G[i][j]=G[i][k]+G[k][j];
					route[i][j]=route[i][k];
				}
	for(i=1 ; i<=n ; i++) {
		for(j=1 ; j<=n ; j++)
			if(i==j)
				printf("- ");
			else
				printf("%d ", route[i][j]);
		puts("");
	}
	return 0;
}
