# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

vector<int> G[10001];
int visit[10001], num;
bool isarticulationpoint[10001];

int dfs(int node, bool isroot) {
	visit[node]=++num;
	int ret=visit[node];
	
	int child=0;
	for(int i=0 ; i<G[node].size() ; i++) {
		int next=G[node][i];
		if(!visit[next]) {
			child++;
			int low=dfs(next, false);
			if(!isroot&&low>=visit[node])
				isarticulationpoint[node]=true;
			ret=min(ret, low);
		} else
			ret=min(ret, visit[next]);
	}
	if(isroot)
		isarticulationpoint[node]=child>=2;
	return ret;
}

int main(void) {
	int V, E, A, B, cou=0;
	scanf("%d%d", &V, &E);
	while(E--) {
		scanf("%d%d", &A, &B);
		G[A].push_back(B);
		G[B].push_back(A);
	}
	for(int i=1 ; i<=V ; i++)
		if(!visit[i])
			dfs(i, true);
	for(int i=1 ; i<=V ; i++)
		if(isarticulationpoint[i])
			cou++;
	printf("%d\n", cou);
	for(int i=1 ; i<=V ; i++)
		if(isarticulationpoint[i])
			printf("%d ", i);
	return 0;
}