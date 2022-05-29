# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[10001];
int in[10002], D[10001], parent[10001];

void init(int N) {
	for(int i=1 ; i<=N ; i++)
		G[i].clear();
	fill(in+1, in+1+N, 0);
}
int findroot(int N) {
	for(int i=1 ; i<=N ; i++)
		if(!in[i])
			return i;
}
void dfs(int n, int depth) {
	D[n]=depth;
	for(int i=0 ; i<G[n].size() ; i++) {
		dfs(G[n][i], depth+1);
		parent[G[n][i]]=n;
	}
}
int lca(int a, int b) {
	while(D[a]!=D[b])
		if(D[a]<D[b])
			b=parent[b];
		else
			a=parent[a];
	while(a!=b) {
		a=parent[a];
		b=parent[b];
	}
	return a;
}

int main(void) {
	int T, N, A, B, root;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		init(N);
		for(int i=0 ; i<N-1 ; i++) {
			scanf("%d%d", &A, &B);
			G[A].push_back(B);
			in[B]++;
		}
		root=findroot(N);
		dfs(root, 0);
		scanf("%d%d", &A, &B);
		printf("%d\n", lca(A, B));
	}
	return 0;
}
