# include <cstdio>
# include <vector>
# include <queue>
# define	INF	2147483647

using namespace std;
int D, d[10001];
vector<pair<int, int>> G[10001];

void dijkstra(int s) {
	fill(d, d+D+1, INF);
	d[s]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while(!pq.empty()) {
		int dist=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(d[cur]<dist)continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int cost=dist+G[cur][i].second;
			if(cost<d[G[cur][i].first]) {
				d[G[cur][i].first]=cost;
				pq.push({cost, G[cur][i].first});
			}
		}
	}
}

int main(void) {
	int N, a, b, c;
	scanf("%d%d", &N, &D);
	while(N--) {
		scanf("%d%d%d", &a, &b, &c);
		if(b>D||b-a<c)continue;
		G[a].push_back({b, c});
	}
	for(int i=0 ; i<D ; i++)
		G[i].push_back({i+1, 1});
	dijkstra(0);
	printf("%d", d[D]);
	return 0;
}
