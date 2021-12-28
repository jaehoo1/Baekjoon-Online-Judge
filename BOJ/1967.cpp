# include <cstdio>
# include <vector>

using namespace std;

int Max;
vector<pair<int, int>> G[10001];
bool visited[10002];

void dfs(int node, int weight) {
	visited[node]=true;
	if(weight>Max)
		Max=weight;
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i].first])
			dfs(G[node][i].first, weight+G[node][i].second);
}

int main(void) {
	int n, a, b, c;
	scanf("%d", &n);
	for(int i=1 ; i<n ; i++) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	for(int i=1 ; i<=n ; i++) {
		fill(visited, visited+1+n, false);
		dfs(i, 0);
	}
	printf("%d", Max);
	return 0;
}
