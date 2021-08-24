# include <stdio.h>

int main(void) {
	int N, G[101][101], i, j, k;
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			scanf("%d", &G[i][j]);
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]&&G[k][j])
					G[i][j]=1;
	for(i=1 ; i<=N ; i++) {
		for(j=1 ; j<=N ; j++)
			printf("%d ", G[i][j]);
		puts("");
	}
	return 0;
}
