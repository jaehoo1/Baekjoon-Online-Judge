# include <cstdio>
# include <queue>
# define	INF	1e9

using namespace std;

vector<pair<int, int>> G[10001];

int dijkstra(int N, int src, int dst) {
	int D[10001];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D, D+N+1, INF);
	D[src]=0;
	pq.push({0, src});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<cost)
			continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i].first;
			int nextcost=cost+G[cur][i].second;
			if(nextcost<D[next]) {
				D[next]=nextcost;
				pq.push({nextcost, next});
			}
		}
	}
	return D[dst];
}

int main(void) {
	int N, M, S, C, A, B, V;
	while(scanf("%d%d%d%d", &N, &M, &S, &C)) {
		if(!N&&!M&&!S&&!C)
			break;
		for(int i=1 ; i<=N ; i++)
			G[i]=vector<pair<int, int>>();
		while(M--) {
			scanf("%d%d%d", &A, &B, &V);
			G[A].push_back({B, V});
		}
		printf("%d\n", dijkstra(N, S, C));
	}
	return 0;
}