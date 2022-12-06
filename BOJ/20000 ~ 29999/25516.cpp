# include <cstdio>
# include <vector>

using namespace std;

vector<int> G[100000];
bool apple[100000];
int res, k;

void dfs(int node, int depth) {
	if(apple[node])
		res++;
	for(int i=0 ; i<G[node].size() ; i++)
		if(depth+1<=k)
			dfs(G[node][i], depth+1);
}

int main(void) {
	int n, p, c;
	scanf("%d%d", &n, &k);
	for(int i=1 ; i<n ; i++) {
		scanf("%d%d", &p, &c);
		G[p].push_back(c);
	}
	for(int i=0 ; i<n ; i++) {
		int is_apple;
		scanf("%d", &is_apple);
		apple[i]=is_apple?1:0;
	}
	dfs(0, 0);
	printf("%d", res);
	return 0;
}