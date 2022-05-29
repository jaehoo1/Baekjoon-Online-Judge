# include <stdio.h>
# define	INF	2147483647

int main(void) {
	int V, E, G[401][401]={0, }, i, j, k, min=INF, a, b, c;
	scanf("%d%d", &V, &E);
	for(i=1 ; i<=V ; i++)
		for(j=1 ; j<=V ; j++)
			G[i][j]=INF;
	while(E--) {
		scanf("%d%d%d", &a, &b, &c);
		G[a][b]=c;
	}
	for(k=1 ; k<=V ; k++)
		for(i=1 ; i<=V ; i++)
			for(j=1 ; j<=V ; j++)
				if(G[i][k]!=INF&&G[k][j]!=INF&&G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	for(i=1 ; i<=V ; i++)
		for(j=1 ; j<=V ; j++)
			if(G[i][j]!=INF&&G[j][i]!=INF) {
				k=G[i][j]+G[j][i];
				if(k<min)
					min=k;
			}
	printf("%d", min==INF?-1:min);
	return 0;
}
