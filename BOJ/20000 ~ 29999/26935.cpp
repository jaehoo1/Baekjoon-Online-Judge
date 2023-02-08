# include <cstdio>
# include <vector>

using namespace std;

int parent[21], depth[21];
vector<int> G[21];

int lca(int a, int b) {
	while(depth[a]!=depth[b])
		if(depth[a]<depth[b])
			b=parent[b];
		else
			a=parent[a];
	while(a!=b) {
		a=parent[a];
		b=parent[b];
	}
	return a;
}
void dfs(int node, int recurdepth) {
	depth[node]=recurdepth;
	for(int i=0 ; i<G[node].size() ; i++)
		dfs(G[node][i], recurdepth+1);
}

int main(void) {
	int N, M, node, ans;
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++) {
		scanf("%d", &node);
		parent[i]=node;
		G[node].push_back(i);
	}
	dfs(0, 0);
	scanf("%d", &ans);
	for(int i=1 ; i<M ; i++) {
		scanf("%d", &node);
		ans=lca(ans, node);
	}
	printf("%d", ans);
	return 0;
}