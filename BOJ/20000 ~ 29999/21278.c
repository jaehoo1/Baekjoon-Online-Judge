# include <stdio.h>
# define	INF	1e9

int main(void) {
	int N, M, G[101][101], i, j, k, A, B, sum, min=INF;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			G[i][j]=i==j?0:INF;
	while(M--) {
		scanf("%d%d", &A, &B);
		G[A][B]=1;
		G[B][A]=1;
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	for(i=1 ; i<=N-1 ; i++)
		for(j=i+1 ; j<=N ; j++) {
			sum=0;
			for(k=1 ; k<=N ; k++)
				sum+=G[k][i]+G[i][k]<G[k][j]+G[j][k]?G[k][i]+G[i][k]:G[k][j]+G[j][k];
			if(sum<min) {
				min=sum;
				A=i;
				B=j;
			}
		}
	printf("%d %d %d", A, B, min);
	return 0;
}
