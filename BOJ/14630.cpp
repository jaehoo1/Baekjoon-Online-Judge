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
	int A, B;
	char str[1001][101];
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++)
		scanf("%s", str[i]);
	for(int i=1 ; i<=N-1 ; i++)
		for(int j=i+1 ; j<=N ; j++) {
			int cost=0;
			for(int k=0 ; str[i][k] ; k++)
				cost+=(str[i][k]-str[j][k])*(str[i][k]-str[j][k]);
			G[i].push_back({j, cost});
			G[j].push_back({i, cost});
		}
	scanf("%d%d", &A, &B);
	dijkstra(A);
	printf("%d", D[B]);
	return 0;
}
