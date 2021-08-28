# include <stdio.h>

int main(void) {
	int G[501][501], N, M, i, j, k, A, B, C;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			scanf("%d", &G[i][j]);
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	while(M--) {
		scanf("%d%d%d", &A, &B, &C);
		if(G[A][B]<=C)
			puts("Enjoy other party");
		else
			puts("Stay here");
	}
	return 0;
}
