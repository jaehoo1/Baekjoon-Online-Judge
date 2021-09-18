# include <cstdio>
# include <vector>
# include <queue>
# define	INF	1e9

using namespace std;

int N, D[1002];
vector<pair<int, int>> G[1001];

void dijkstra(int start) {
	fill(D+1, D+1+N, INF);
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
				pq.push({dist, G[cur][i].first});
				D[G[cur][i].first]=dist;
			}
		}
	}
}

int main(void) {
	int M, X, A, B, T, time[1001], max=0;
	scanf("%d%d%d", &N, &M, &X);
	while(M--) {
		scanf("%d%d%d", &A, &B, &T);
		G[A].push_back({B, T});
	}
	for(int i=1 ; i<=N ; i++) {
		dijkstra(i);
		time[i]=D[X];
	}
	dijkstra(X);
	for(int i=1 ; i<=N ; i++)
		time[i]+=D[i];
	for(int i=1 ; i<=N ; i++)
		if(time[i]>max)
			max=time[i];
	printf("%d", max);
	return 0;
}
