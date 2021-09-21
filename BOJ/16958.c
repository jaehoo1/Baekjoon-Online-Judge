# include <stdio.h>
# define	INF	1e9

typedef struct {
	int s, x, y;
}node;

int Abs(int x) {
	if(x<0)return -x;
	return x;
}
int dist(node a, node b, int T) {
	int taxi=Abs(a.x-b.x)+Abs(a.y-b.y);
	if(a.s&&b.s&&T<taxi)
		return T;
	return taxi;
}

int main(void) {
	node arr[1001];
	int N, T, M, A, B, i, j, k, G[1001][1001];
	scanf("%d%d", &N, &T);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++)
			G[i][j]=i==j?0:INF;
	for(i=1 ; i<=N ; i++)
		scanf("%d%d%d", &arr[i].s, &arr[i].x, &arr[i].y);
	for(i=1 ; i<=N ; i++)
		for(j=i+1 ; j<=N ; j++)
			G[i][j]=G[j][i]=dist(arr[i], arr[j], T);
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	scanf("%d", &M);
	while(M--) {
		scanf("%d%d", &A, &B);
		printf("%d\n", G[A][B]);
	}
	return 0;
}
