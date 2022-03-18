# include <cstdio>
# include <vector>

using namespace std;

bool bipartite, colors[20002], visited[20002];
vector<int> G[20001];

void dfs(int node, bool color) {
	visited[node]=true;
	colors[node]=color;
	for(int i=0 ; i<G[node].size() ; i++) {
		if(visited[G[node][i]]&&color==colors[G[node][i]])
			bipartite=false;
		if(!visited[G[node][i]])
			dfs(G[node][i], !color);
	}
}

int main(void) {
	int K, V, E, u, v;
	scanf("%d", &K);
	while(K--) {
		bipartite=true;
		scanf("%d%d", &V, &E);
		for(int i=1 ; i<=V ; i++)
			G[i].clear();
		fill(colors, colors+V+1, false);
		fill(visited, visited+V+1, false);
		while(E--) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1 ; i<=V ; i++)
			if(!visited[i])
				dfs(i, false);
		puts(bipartite?"YES":"NO");
	}
	return 0;
}
