# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

vector<int> G[100001];
bool visited[100001];
int visitedturn[100001], turn;

void dfs(int node) {
	visited[node]=true;
	visitedturn[node]=++turn;
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i]])
			dfs(G[node][i]);
}

int main(void) {
	int N, M, R, u, v;
	scanf("%d%d%d", &N, &M, &R);
	while(M--) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1 ; i<=N ; i++)
		sort(G[i].begin(), G[i].end());
	dfs(R);
	for(int i=1 ; i<=N ; i++)
		printf("%d\n", visitedturn[i]);
	return 0;
}
