# include <cstdio>
# include <vector>
# include <queue>
# define	INF	2147483647

using namespace std;

int N, D[300001];
vector<pair<int, int>> G[300001];

void dijkstra(int s) {
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
}

int main(void) {
	int M, K, X, A, B, flag=0;
	scanf("%d%d%d%d", &N, &M, &K, &X);
	while(M--) {
		scanf("%d%d", &A, &B);
		G[A].push_back({B, 1});
	}
	dijkstra(X);
	for(int i=1 ; i<=N ; i++) {
		if(D[i]==K) {
			printf("%d\n", i);
			if(!flag)
				flag=1;
		}
	}
	if(!flag)
		puts("-1");
	return 0;
}
