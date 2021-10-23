# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[50001];
int N, parent[50001], D[50001];
bool visited[50001];

void dfs(int n, int depth) {
	visited[n]=true;
	D[n]=depth;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]]) {
			parent[G[n][i]]=n;
			dfs(G[n][i], depth+1);
		}
}
int LCA(int a, int b) {
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
	int M, A, B;
	scanf("%d", &N);
	for(int i=0 ; i<N-1 ; i++) {
		scanf("%d%d", &A, &B);
		G[A].push_back(B);
		G[B].push_back(A);
	}
	dfs(1, 0);
	scanf("%d", &M);
	while(M--) {
		scanf("%d%d", &A, &B);
		printf("%d\n", LCA(A, B));
	}
	return 0;
}
