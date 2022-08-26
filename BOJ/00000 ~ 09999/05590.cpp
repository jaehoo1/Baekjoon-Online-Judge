# include <cstdio>
# include <queue>
# define	INF	1e9

using namespace std;

int G[101][101], n;

int dijkstra(int src, int dst) {
	int D[102];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D, D+n+1, INF);
	D[src]=0;
	pq.push({0, src});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		for(int i=1 ; i<=n ; i++) {
			if(G[cur][i]==INF)
				continue;
			if(cost+G[cur][i]<D[i]) {
				D[i]=cost+G[cur][i];
				pq.push({D[i], i});
			}
		}
	}
	return D[dst]==INF?-1:D[dst];
}

int main(void) {
	int k, a, b, c, d;
	scanf("%d%d", &n, &k);
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			G[i][j]=INF;
	while(k--) {
		scanf("%d", &a);
		if(a) {
			scanf("%d%d%d", &b, &c, &d);
			if(d<G[b][c])
				G[b][c]=G[c][b]=d;
		} else {
			scanf("%d%d", &b, &c);
			printf("%d\n", dijkstra(b, c));
		}
	}
	return 0;
}