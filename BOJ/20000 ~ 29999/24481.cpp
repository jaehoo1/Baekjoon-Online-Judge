# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

vector<int> G[100001];
bool visited[100001];
int D[100002];

void dfs(int node, int depth) {
	visited[node]=true;
	D[node]=depth;
	sort(G[node].begin(), G[node].end());
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i]])
			dfs(G[node][i], depth+1);
}

int main(void) {
	int N, M, R, u, v;
	scanf("%d%d%d", &N, &M, &R);
	while(M--) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	fill(D, D+N+1, -1);
	dfs(R, 0);
	for(int i=1 ; i<=N ; i++)
		printf("%d\n", D[i]);
	return 0;
}