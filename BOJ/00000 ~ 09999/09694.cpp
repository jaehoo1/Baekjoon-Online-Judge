# include <cstdio>
# include <queue>
# include <algorithm>
# define	INF	1e9

using namespace std;

vector<pair<int, int>> G[20];
int M;

void dijkstra(void) {
	int D[21], parent[20];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D, D+M+1, INF);
	D[0]=0;
	parent[0]=0;
	pq.push({0, 0});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<cost)
			continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i].first;
			int nextdist=G[cur][i].second+cost;
			if(nextdist<D[next]) {
				D[next]=nextdist;
				parent[next]=cur;
				pq.push({nextdist, next});
			}
		}
	}
	if(D[M-1]==INF)
		puts("-1");
	else {
		vector<int> v;
		int node=M-1;
		while(parent[node]!=node) {
			v.push_back(node);
			node=parent[node];
		}
		v.push_back(node);
		reverse(v.begin(), v.end());
		for(int i=0 ; i<v.size() ; i++)
			printf("%d ", v[i]);
		puts("");
	}
}

int main(void) {
	int T, N, x, y, z;
	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++) {
		scanf("%d%d", &N, &M);
		for(int i=0 ; i<M ; i++)
			G[i].clear();
		while(N--) {
			scanf("%d%d%d", &x, &y, &z);
			G[x].push_back({y, z});
			G[y].push_back({x, z});
		}
		printf("Case #%d: ", t);
		dijkstra();
	}
	return 0;
}