# include <cstdio>
# include <vector>
# include <queue>
# define	INF	2000000001

using namespace std;

int N;
vector<pair<int, int>> G[100001];

long long dijkstra(int s, int e, int n) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	long long D[100002];
	fill(D, D+N+1, INF);
	D[s]=0;
	pq.push({0, s});
	while(!pq.empty()) {
		long long cur_cost=pq.top().first;
		int cur_node=pq.top().second;
		pq.pop();
		if(D[cur_node]<cur_cost)
			continue;
		for(int i=0 ; i<G[cur_node].size() ; i++) {
			int next=G[cur_node][i].first;
			long long dist=cur_cost+G[cur_node][i].second;
			if(next==n)
				continue;
			if(dist<D[next]) {
				D[next]=dist;
				pq.push({dist, next});
			}
		}
	}
	return D[e];
}

int main(void) {
	int M, X, Y, Z;
	scanf("%d%d", &N, &M);
	while(M--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
	}
	scanf("%d%d%d", &X, &Y, &Z);
	long long temp1=dijkstra(X, Y, 0), temp2=dijkstra(Y, Z, 0), temp3=dijkstra(X, Z, Y);
	if(temp1==INF||temp2==INF)
		printf("-1 ");
	else
		printf("%lld ", temp1+temp2);
	printf("%lld", temp3==INF?-1:temp3);
	return 0;
}
