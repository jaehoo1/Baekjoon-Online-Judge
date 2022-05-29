# include <stdio.h>
# define	INF	1e9

typedef struct { int s, d, c; }edge;

int D[501], N, M, W;
edge G[5200];

int bellmanford(int start) {
	int i, j, cur, negative=0;
	for(i=1 ; i<=N ; i++)
		D[i]=INF;
	D[start]=0;
	for(i=1 ; i<=N ; i++)
		for(j=0 ; j<2*M+W ; j++) {
			cur=G[j].s;
			if(D[cur]+G[j].c<D[G[j].d]) {
				D[G[j].d]=D[cur]+G[j].c;
				if(i==N)
					negative=1;
			}
		}
	return negative;
}

int main(void) {
	int TC, i, S, E, T;
	scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &N, &M, &W);
		for(i=0 ; i<2*M ; i+=2) {
			scanf("%d%d%d", &S, &E, &T);
			G[i].s=S;	G[i+1].s=E;
			G[i].d=E;	G[i+1].d=S;
			G[i].c=G[i+1].c=T;
		}
		for( ; i<2*M+W ; i++) {
			scanf("%d%d%d", &S, &E, &T);
			G[i].s=S;
			G[i].d=E;
			G[i].c=-T;
		}
		puts(bellmanford(1)?"YES":"NO");
	}
	return 0;
}
