# include <stdio.h>
# define	INF	1e9

int main(void) {
	int T, N, M, G[101][101], i, j, k, a, b, c, K, arr[100], min, sum=0, dest;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				G[i][j]=i==j?0:INF;
		while(M--) {
			scanf("%d%d%d", &a, &b, &c);
			G[a][b]=c;
			G[b][a]=c;
		}
		for(k=1 ; k<=N ; k++)
			for(i=1 ; i<=N ; i++)
				for(j=1 ; j<=N ; j++)
					if(G[i][k]+G[k][j]<G[i][j])
						G[i][j]=G[i][k]+G[k][j];
		min=INF;
		scanf("%d", &K);
		for(k=0 ; k<K ; k++)
			scanf("%d", &arr[k]);
		for(i=1 ; i<=N ; i++) {
			sum=0;
			for(k=0 ; k<K ; k++)
				sum+=G[arr[k]][i];
			if(sum<min) {
				min=sum;
				dest=i;
			}
		}
		printf("%d\n", dest);
	}
	return 0;
}
