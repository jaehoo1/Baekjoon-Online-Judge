# include <cstdio>
# include <vector>
# include <queue>
# define	INF	2147483647

using namespace std;

int V, D[20001];
vector<pair<int, int>> G[20001];

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D+1, D+V+1, INF);
	D[s]=0;
	pq.push({0, s});
	while(!pq.empty()) {
		int dist=pq.top().first;	//비용 
		int cur=pq.top().second;	//목적지 
		pq.pop();
		if(D[cur]<dist)continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int cost=dist+G[cur][i].second;
			if(cost<D[G[cur][i].first]) {
				D[G[cur][i].first]=cost;
				pq.push({cost, G[cur][i].first});
			}
		}
	}
}

int main(void) {
	int E, start;
	scanf("%d%d%d", &V, &E, &start);
	while(E--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
	}
	dijkstra(start);
	for(int i=1 ; i<=V ; i++)
		if(D[i]==INF)puts("INF");
		else	printf("%d\n", D[i]);
	return 0;
}
