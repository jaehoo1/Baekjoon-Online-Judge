# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

vector<int> G[100001];
bool visited[100001];
int order[100001], cou;

void dfs(int node) {
	order[node]=++cou;
	visited[node]=true;
	sort(G[node].begin(), G[node].end());
	for(int i=G[node].size()-1 ; i>=0 ; i--)
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
	dfs(R);
	for(int i=1 ; i<=N ; i++)
		printf("%d\n", order[i]);
	return 0;
}