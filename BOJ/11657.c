# include <stdio.h>
# define	INF	9223372036854775807

typedef struct {
	int s, d, c;
}edge;

edge G[6000];
int N, M;
long long D[501];

int bellmanford(int start) {
	int i, j, cur, negative=0;
	for(i=1 ; i<=N ; i++)
		D[i]=INF;
	D[start]=0;
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++) {
			cur=G[j].s;
			if(D[cur]==INF)continue;
			if(D[cur]+G[j].c<D[G[j].d]) {
				D[G[j].d]=D[cur]+G[j].c;
				if(i==N-1)
					negative=1;
			}
		}
	return negative;
}

int main(void) {
	int i;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<M ; i++)
		scanf("%d%d%d", &G[i].s, &G[i].d, &G[i].c);
	if(bellmanford(1))
		puts("-1");
	else
		for(i=2 ; i<=N ; i++)
			printf("%lld\n", D[i]!=INF?D[i]:-1);
	return 0;
}
