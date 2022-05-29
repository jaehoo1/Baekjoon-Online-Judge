# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[501];
bool visited[501];
int cou;

void dfs(int node, int depth) {
	if(!visited[node])
		cou++;
	visited[node]=true;
	for(int i=0 ; i<G[node].size() ; i++)
		if(depth<=1)
			dfs(G[node][i], depth+1);
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 0);
	printf("%d", cou-1);
	return 0;
}
