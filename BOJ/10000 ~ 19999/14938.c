# include <stdio.h>
# define	INF	1e9

int main(void) {
	int n, m, r, t[101], G[101][101], i, j, k, a, b, l, sum, max=0;
	scanf("%d%d%d", &n, &m, &r);
	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=n ; j++)
			G[i][j]=i==j?0:INF;
	for(i=1 ; i<=n ; i++)
		scanf("%d", &t[i]);
	while(r--) {
		scanf("%d%d%d", &a, &b, &l);
		if(l<G[a][b])G[a][b]=l;
		if(l<G[b][a])G[b][a]=l;
	}
	for(k=1 ; k<=n ; k++)
		for(i=1 ; i<=n ; i++)
			for(j=1 ; j<=n ; j++)
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	for(i=1 ; i<=n ; i++) {
		sum=0;
		for(j=1 ; j<=n ; j++)
			if(G[i][j]<=m)
				sum+=t[j];
		if(sum>max)
			max=sum;
	}
	printf("%d", max);
	return 0;
}
