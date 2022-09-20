# include <cstdio>
# include <vector>

using namespace std;

int N;
long long max_dist;
vector<pair<int, int>> G[5001];
bool visited[5001];

void dfs(int node, long long cost) {
	visited[node]=true;
	if(cost>max_dist)
		max_dist=cost;
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i].first])
			dfs(G[node][i].first, cost+G[node][i].second);
}

int main(void) {
	int A, B, C;
	scanf("%d", &N);
	for(int i=0 ; i<N-1 ; i++) {
		scanf("%d%d%d", &A, &B, &C);
		G[A].push_back({B, C});
		G[B].push_back({A, C});
	}
	dfs(1, 0);
	printf("%lld", max_dist);
	return 0;
}