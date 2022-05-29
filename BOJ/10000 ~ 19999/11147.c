# include <stdio.h>
# define	INF	1e9
int main(void) {
	int T, N, arr[201], G[200][200], i, j, k, impossible, sum;
	scanf("%d", &T);
	while(T--) {
		sum=0;
		impossible=0;
		scanf("%d", &N);
		for(i=0 ; i<N ; i++)
			scanf("%d", &arr[i]);
		arr[i]=arr[0];
		for(i=0 ; i<N ; i++)
			for(j=0 ; j<N ; j++) {
				scanf("%d", &G[i][j]);
				if(G[i][j]==-1)
					G[i][j]=INF;
			}
		for(k=0 ; k<N ; k++)
			for(i=0 ; i<N ; i++)
				for(j=0 ; j<N ; j++)
					if(G[i][k]+G[k][j]<G[i][j])
						G[i][j]=G[i][k]+G[k][j];
		for(i=0 ; i<N ; i++) {
			if(G[arr[i]][arr[i+1]]==INF) {
				impossible=1;
				break;
			}
			sum+=G[arr[i]][arr[i+1]];
		}
		if(impossible)puts("impossible");
		else	printf("%d\n", sum);
	}
	return 0;
}
