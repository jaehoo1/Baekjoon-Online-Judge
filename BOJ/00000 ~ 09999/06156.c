# include <stdio.h>

int main(void) {
	int N, M, G[101][101]={0, }, A, B, i, j, k, cou=0, temp;
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
		temp=0;
		for(j=1 ; j<=N ; j++)
			if(G[i][j]||G[j][i])
				temp++;
		if(temp==N-1)
			cou++;
	}
	printf("%d", cou);
	return 0;
}
