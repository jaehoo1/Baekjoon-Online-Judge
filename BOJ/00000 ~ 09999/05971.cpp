# include <cstdio>
# include <vector>

using namespace std;

int N, P[1001], D[1001];
vector<int> G[1001];

void dfs(int node, int depth) {
	D[node]=depth;
	for(int i=0 ; i<G[node].size() ; i++)
		dfs(G[node][i], depth+1);
}
int lca(int a, int b) {
	while(D[a]!=D[b])
		if(D[a]>D[b])
			a=P[a];
		else
			b=P[b];
	while(a!=b) {
		a=P[a];
		b=P[b];
	}
	return a;
}
int main(void) {
	int M, B, J;
	scanf("%d%d", &N, &M);
	for(int i=2 ; i<=N ; i++) {
		scanf("%d", &P[i]);
		G[P[i]].push_back(i);
	}
	dfs(1, 0);
	while(M--) {
		scanf("%d%d", &B, &J);
		printf("%d\n", lca(B, J));
	}
	return 0;
}