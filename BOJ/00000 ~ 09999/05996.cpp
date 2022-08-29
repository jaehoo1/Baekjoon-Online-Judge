# include <cstdio>
# include <vector>
# include <queue>
# define	INF	1e9

using namespace std;

int T, Ts, Te;
vector<pair<int, int>> G[2501];

int dijkstra(void) {
	int D[2501];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i=1 ; i<=T ; i++)
		D[i]=INF;
	D[Ts]=0;
	pq.push({0, Ts});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i].first;
			int nextcost=cost+G[cur][i].second;
			if(nextcost<D[next]) {
				D[next]=nextcost;
				pq.push({nextcost, next});
			}
		}
	}
	return D[Te];
}

int main(void) {
	int C, a, b, c;
	scanf("%d%d%d%d", &T, &C, &Ts, &Te);
	while(C--) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	printf("%d", dijkstra());
	return 0;
}