# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[21];
bool visited[21];
int depth[21];

void dfs(int n, int dth) {
	visited[n]=true;
	depth[n]=dth;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]])
			dfs(G[n][i], dth+1);
}

int main(void) {
	int n, num, root;
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++) {
		scanf("%d", &num);
		if(num==-1)
			root=i;
		else {
			G[i].push_back(num);
			G[num].push_back(i);
		}
	}
	dfs(root, 0);
	for(int i=1 ; i<=n ; i++)
		printf("%d\n", depth[i]);
	return 0;
}
