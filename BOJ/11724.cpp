# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[1001];
bool visited[1001];

void dfs(int n) {
	visited[n]=true;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]])
			dfs(G[n][i]);
}

int main(void) {
	int N, M, cou=0;
	scanf("%d%d", &N, &M);
	while(M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1 ; i<=N ; i++)
		if(!visited[i]) {
			dfs(i);
			cou++;
		}
	printf("%d", cou);
	return 0;
}
