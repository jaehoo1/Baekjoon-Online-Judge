# include <stdio.h>

int main(void) {
	int G[101][101]={0, }, N, M, i, j, k, A, B, cou;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &A, &B);
		G[A][B]=1;
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]&&G[k][j])
					G[i][j]=1;
	for(i=1 ; i<=N ; i++) {
		cou=-1;
		for(j=1 ; j<=N ; j++)
			if(!G[i][j]&&!G[j][i])
				cou++;
		printf("%d\n", cou);
	}
	return 0;
}
