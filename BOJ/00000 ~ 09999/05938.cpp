# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[251];
bool visited[251];

void dfs(int node) {
	visited[node]=true;
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i]])
			dfs(G[node][i]);
}

int main(void) {
	int N, M, c1, c2;
	bool flag=false;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &c1, &c2);
		G[c1].push_back(c2);
		G[c2].push_back(c1);
	}
	dfs(1);
	for(int i=1 ; i<=N ; i++)
		if(!visited[i]) {
			flag=true;
			printf("%d\n", i);
		}
	if(!flag)
		puts("0");
	return 0;
}