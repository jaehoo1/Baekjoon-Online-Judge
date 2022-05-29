# include <cstdio>
# include <vector>
# include <queue>
# define	INF	1e9

using namespace std;

int V;
vector<pair<int, int>> G[5001];

int dijkstra(int s, int e) {
	int D[5002];
	fill(D, D+V+1, INF);
	D[s]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
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
	return D[e];
}

int main(void) {
	int E, P, a, b, c;
	scanf("%d%d%d", &V, &E, &P);
	while(E--) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	if(dijkstra(1, V)==dijkstra(1, P)+dijkstra(P, V))
		puts("SAVE HIM");
	else
		puts("GOOD BYE");
	return 0;
}
