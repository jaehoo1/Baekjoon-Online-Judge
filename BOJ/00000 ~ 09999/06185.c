# include <stdio.h>

int main(void) {
	int N, M, arr[10000], G[101][101], sum=0, i, j, k;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<M ; i++)
		scanf("%d", &arr[i]);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			scanf("%d", &G[i][j]);
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	for(i=1 ; i<M ; i++)
		sum+=G[arr[i-1]][arr[i]];
	printf("%d", sum);
	return 0;
}