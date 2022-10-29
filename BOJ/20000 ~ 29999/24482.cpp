# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

vector<int> G[100001];
bool visited[100001];
int node_depth[100002];

bool cmp(const int &a, const int &b) { return a>b; }
void dfs(int node, int depth) {
	visited[node]=true;
	node_depth[node]=depth;
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
	for(int i=1 ; i<=N ; i++)
		sort(G[i].begin(), G[i].end(), cmp);
	fill(node_depth, node_depth+N+1, -1);
	dfs(R, 0);
	for(int i=1 ; i<=N ; i++)
		printf("%d\n", node_depth[i]);
	return 0;
}