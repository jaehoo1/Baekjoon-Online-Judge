# include <cstdio>
# include <vector>
# include <queue>
# define	INF	1e9

using namespace std;

vector<pair<int, int>> G[5001];
int N;

int dijkstra(int begin, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int D[5002];
	fill(D, D+N+1, INF);
	D[begin]=0;
	pq.push({0, begin});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<cost)
			continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i].first;
			int dist=cost+G[cur][i].second;
			if(dist<D[next]) {
				pq.push({dist, next});
				D[next]=dist;
			}
		}
	}
	return D[end];
}

int main(void) {
	int M, a, b, c, s, t;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	scanf("%d%d", &s, &t);
	printf("%d", dijkstra(s, t));
	return 0;
}
