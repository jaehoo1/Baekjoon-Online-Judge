# include <cstdio>
# include <vector>
# include <queue>
# define	INF	1e9

using namespace std;

int n, cou, D[10002], max_;
vector<pair<int, int>> G[10001];

void dijkstra(int start) {
	bool visited[10001]={false, };
	cou=0;	max_=0;
	fill(D, D+n+1, INF);
	D[start]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	visited[start]=true;
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
				visited[G[cur][i].first]=true;
			}
		}
	}
	for(int i=1 ; i<=n ; i++) {
		if(visited[i])
			cou++;
		if(D[i]>max_&&visited[i])
			max_=D[i];
	}
}

int main(void) {
	int T, d, c, a, b, s;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &d, &c);
		for(int i=1 ; i<=n ; i++)
			G[i].clear();
		while(d--) {
			scanf("%d%d%d", &a, &b, &s);
			G[b].push_back({a, s});
		}
		dijkstra(c);
		printf("%d %d\n", cou, max_);
	}
	return 0;
}
