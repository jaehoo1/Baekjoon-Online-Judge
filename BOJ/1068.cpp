# include <cstdio>
# include <vector>

using namespace std;

int N, cou, erase;
vector<int> G[51];
bool visited[51];

void dfs(int n) {
	if(n==erase)
		return;
	visited[n]=true;
	if(!G[n].size())
		cou++;
	if(G[n].size()==1)
		if(G[n][0]==erase)
			cou++;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]])
			dfs(G[n][i]);
}

int main(void) {
	int parent, root;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &parent);
		if(parent==-1) {
			root=i;
			continue;
		}
		G[parent].push_back(i);
	}
	scanf("%d", &erase);
	dfs(root);
	printf("%d", cou);
	return 0;
}
