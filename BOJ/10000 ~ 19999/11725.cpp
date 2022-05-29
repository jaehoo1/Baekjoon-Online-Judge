# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[100001];
bool visited[100001];
int parent[100001];

void dfs(int n) {
	visited[n]=true;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]]) {
			parent[G[n][i]]=n;
			dfs(G[n][i]);
		}
}

int main(void) {
	int N, a, b;
	scanf("%d", &N);
	for(int i=1 ; i<N ; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1);
	for(int i=2 ; i<=N ; i++)
		printf("%d\n", parent[i]);
	return 0;
}
