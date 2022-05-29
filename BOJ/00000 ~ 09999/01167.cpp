# include <cstdio>
# include <vector>

using namespace std;

vector<pair<int, int>> G[100001];
bool visited[100002];
int res, farthest;

void dfs(int node, int cost) {
	if(cost>res) {
		res=cost;
		farthest=node;
	}
	visited[node]=true;
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i].first])
			dfs(G[node][i].first, cost+G[node][i].second);
}

int main(void) {
	int V, N, A, B;
	scanf("%d", &V);
	for(int i=0 ; i<V ; i++) {
		scanf("%d", &N);
		while(scanf("%d", &A)) {
			if(A==-1)
				break;
			scanf("%d", &B);
			G[N].push_back({A, B});
		}
	}
	dfs(1, 0);
	fill(visited, visited+1+V, false);
	dfs(farthest, 0);
	printf("%d", res);
	return 0;
}
