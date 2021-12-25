# include <vector>
# include <iostream>

using namespace std;

vector<int> G[2000];
bool visited[2000];

void dfs(int node, int depth) {
	if(depth==4) {
		puts("1");
		exit(0);
	}
	visited[node]=true;
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i]])
			dfs(G[node][i], depth+1);
	visited[node]=false;
}

int main(void) {
	int N, M, a, b;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0 ; i<N ; i++)
		dfs(i, 0);
	puts("0");
	return 0;
}
