# include <cstdio>
# include <vector>

using namespace std;

vector<pair<int, int>> G[1001];
int D[1001], parent[1001];
bool visited[1001];

void dfs(int node, int depth) {
	visited[node]=true;
	D[node]=depth;
	for(int i=0 ; i<G[node].size() ; i++) {
		if(visited[G[node][i].first])
			continue;
		parent[G[node][i].first]=node;
		dfs(G[node][i].first, depth+1);
	}
}
int parent_edge_len(int node) {
	for(int i=0 ; i<G[node].size() ; i++)
		if(parent[node]==G[node][i].first)
			return G[node][i].second;
}
int lca_len(int a, int b) {
	int len=0;
	while(D[a]!=D[b])
		if(D[a]<D[b]) {
			len+=parent_edge_len(b);
			b=parent[b];
		} else {
			len+=parent_edge_len(a);
			a=parent[a];
		}
	while(a!=b) {
		len+=parent_edge_len(a);
		a=parent[a];
		len+=parent_edge_len(b);
		b=parent[b];
	}
	return len;
}

int main(void) {
	int N, Q, A, B, L, p1, p2;
	scanf("%d%d", &N, &Q);
	for(int i=1 ; i<N ; i++) {
		scanf("%d%d%d", &A, &B, &L);
		G[A].push_back({B, L});
		G[B].push_back({A, L});
	}
	dfs(1, 0);
	while(Q--) {
		scanf("%d%d", &p1, &p2);
		printf("%d\n", lca_len(p1, p2));
	}
	return 0;
}