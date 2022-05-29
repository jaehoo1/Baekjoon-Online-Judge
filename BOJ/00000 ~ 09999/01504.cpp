# include <cstdio>
# include <vector>
# include <queue>
# define	INF	2147483647

using namespace std;

int N;
vector<pair<int, int>> G[801];

int dijkstra(int s, int e) {
	int D[N+1];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D+1, D+N+1, INF);
	D[s]=0;
	pq.push({0, s});
	while(!pq.empty()) {
		int dist=pq.top().first;
		int cur=pq.top().second;
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
	return D[e];
}

int main(void) {
	int E, a, b, c, v1, v2, res1=INF, res2=INF;
	scanf("%d%d", &N, &E);
	while(E--) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	scanf("%d%d", &v1, &v2);
	a=dijkstra(1, v1);
	b=dijkstra(v1, v2);
	c=dijkstra(v2, N);
	if(a!=INF&&b!=INF&&c!=INF)
		res1=a+b+c;
	a=dijkstra(1, v2);
	b=dijkstra(v2, v1);
	c=dijkstra(v1, N);
	if(a!=INF&&b!=INF&&c!=INF)
		res2=a+b+c;
	if(res1==INF&&res2==INF)
		puts("-1");
	else
		printf("%d", res1<res2?res1:res2);
	return 0;
}
