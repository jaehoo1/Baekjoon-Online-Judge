# include <stdio.h>

int G[150], K, visited[150], cou;

void dfs(int node, int depth) {
	visited[node]=1;
	if(node==K) {
		cou=depth;
		return;
	}
	if(!visited[G[node]])
		dfs(G[node], depth+1);
}

int main(void) {
	int N, i;
	scanf("%d%d", &N, &K);
	for(i=0 ; i<N ; i++)
		scanf("%d", &G[i]);
	dfs(0, 0);
	printf("%d", visited[K]?cou:-1);
	return 0;
}
