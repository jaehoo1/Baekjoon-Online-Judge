# include <stdio.h>
# define	INF	1e9

int main(void) {
	int N, i, j, k, A, B, G[51][51], min=INF, cou=0, score[51];
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			G[i][j]=i==j?0:INF;
	while(scanf("%d%d", &A, &B)) {
		if(A==-1&&B==-1)break;
		G[A][B]=1;
		G[B][A]=1;
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	for(i=1 ; i<=N ; i++) {
		score[i]=0;
		for(j=1 ; j<=N ; j++) {
			if(score[i]<G[i][j])score[i]=G[i][j];
			if(score[i]<G[j][i])score[i]=G[j][i];
		}
		if(score[i]<min)
			min=score[i];
	}
	for(i=1 ; i<=N ; i++)
		if(score[i]==min)
			cou++;
	printf("%d %d\n", min, cou);
	for(i=1 ; i<=N ; i++)
		if(score[i]==min)
			printf("%d ", i);
	return 0;
}
