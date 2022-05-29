# include <cstdio>
# include <vector>

using namespace std;

int N, dp[100001];
vector<int> G[100001];
bool visited[1000001];

int dfs(int node) {
	int vertex=0;
	visited[node]=true;
	for(int i=0 ; i<G[node].size() ; i++) {
		if(visited[G[node][i]])
			continue;
		vertex+=dfs(G[node][i]);
	}
	return dp[node]=vertex+1;
}

int main(void) {
	int R, Q;
	scanf("%d%d%d", &N, &R, &Q);
	for(int i=0 ; i<N-1 ; i++) {
		int U, V;
		scanf("%d%d", &U, &V);
		G[U].push_back(V);
		G[V].push_back(U);
	}
	dfs(R);
	while(Q--) {
		int U;
		scanf("%d", &U);
		printf("%d\n", dp[U]);
	}
	return 0;
}
