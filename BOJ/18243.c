# include <stdio.h>
# define	INF	2147483647

int main(void) {
	int G[101][101], N, K, i, j, k, A, B, flag=1;
	scanf("%d%d", &N, &K);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			G[i][j]=INF;
	while(K--) {
		scanf("%d%d", &A, &B);
		G[A][B]=1;
		G[B][A]=1;
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]!=INF&&G[k][j]!=INF&&G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	for(i=1 ; i<=N ; i++) {
		for(j=1 ; j<=N ; j++)
			if(G[i][j]>6) {
				flag=0;
				break;
			}
		if(!flag)
			break;
	}
	puts(flag?"Small World!":"Big World!");
	return 0;
}
