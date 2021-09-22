# include <cstdio>
# include <vector>
# include <queue>
# define	INF	9223372036854775807

using namespace std;

int N;
long long D[100001];
bool ward[100000];
vector<pair<int, int>> G[100000];

void dijkstra(int start) {
	fill(D, D+N, INF);
	D[start]=0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, start});
	while(!pq.empty()) {
		long long cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<cost)continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			if(ward[G[cur][i].first])
				continue;
			long long dist=cost+G[cur][i].second;
			if(dist<D[G[cur][i].first]) {
				D[G[cur][i].first]=dist;
				pq.push({dist, G[cur][i].first});
			}
		}
	}
}

int main(void) {
	int M, a, b, t;
	scanf("%d%d", &N, &M);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &ward[i]);
	ward[N-1]=false;
	while(M--) {
		scanf("%d%d%d", &a, &b, &t);
		G[a].push_back({b, t});
		G[b].push_back({a, t});
	}
	dijkstra(0);
	if(D[N-1]==INF)puts("-1");
	else	printf("%lld", D[N-1]);
	return 0;
}
