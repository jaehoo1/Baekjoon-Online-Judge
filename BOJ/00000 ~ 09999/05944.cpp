# include <cstdio>
# include <vector>
# include <queue>
# define	INF	1e9

using namespace std;

int P;
vector<pair<int, int>> G[100001];

int dijkstra(int src, int dst) {
	int D[100002];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D, D+P+1, INF);
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
	int C, PB, PA1, PA2, P1, P2, D;
	scanf("%d%d%d%d%d", &C, &P, &PB, &PA1, &PA2);
	while(C--) {
		scanf("%d%d%d", &P1, &P2, &D);
		G[P1].push_back({P2, D});
		G[P2].push_back({P1, D});
	}
	printf("%d", min(dijkstra(PB, PA1)+dijkstra(PA1, PA2), dijkstra(PB, PA2)+dijkstra(PA2, PA1)));
	return 0;
}