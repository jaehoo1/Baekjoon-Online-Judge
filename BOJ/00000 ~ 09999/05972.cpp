# include <cstdio>
# include <vector>
# include <queue>
# define	INF	1e9

using namespace std;

int N;
vector<pair<int, int>> G[50001];

int dijkstra(int start) {
	int D[50002];
	fill(D, D+N+1, INF);
	D[start]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<cost)continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int dist=cost+G[cur][i].second;
			if(dist<D[G[cur][i].first]) {
				D[G[cur][i].first]=dist;
				pq.push({dist, G[cur][i].first});
			}
		}
	}
	return D[N];
}

int main(void) {
	int M, A, B, C;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d%d", &A, &B, &C);
		G[A].push_back({B, C});
		G[B].push_back({A, C});
	}
	printf("%d", dijkstra(1));
	return 0;
}
