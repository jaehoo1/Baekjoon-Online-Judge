# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[14];
bool istree=true, in[14], node[14], visited[14];

void init(void) {
	for(int i=1 ; i<=13 ; i++) {
		G[i].clear();
		in[i]=node[i]=visited[i]=false;
	}
	istree=true;
}
int findroot(void) {
	for(int i=1 ; i<=13 ; i++)
		if(node[i]&&!in[i])
			return i;
	return 0;
}
void dfs(int node) {
	visited[node]=true;
	for(int i=0 ; i<G[node].size() ; i++)
		if(visited[G[node][i]]) {
			istree=false;
			return;
		} else
			dfs(G[node][i]);
}
bool treecheck() {
	int root=findroot();
	if(!root) {
		for(int i=1 ; i<=13 ; i++)
			if(node[i])
				return false;
		return true;
	}
	dfs(root);
	for(int i=1 ; i<=13 ; i++)
		if(node[i]&&!visited[i])
			return false;
	return istree&&true;
}

int main(void) {
	int u, v, k=1;
	while(scanf("%d%d", &u, &v)) {
		if(!u&&!v) {
			printf("Case %d is ", k++);
			if(!treecheck())
				printf("not ");
			puts("a tree.");
			init();
			continue;
		}
		if(u==-1&&v==-1)
			return 0;
		G[u].push_back(v);
		if(in[v])
			istree=false;
		in[v]=true;
		node[u]=node[v]=true;
	}
	return 0;
}
