# include <stdio.h>

int N, G[10][10], min=10001, visited[10];

void dfs(int depth, int node, int time) {
	int i;
	if(depth==N) {
		if(time<min)
			min=time;
		return;
	}
	for(i=0 ; i<N ; i++)
		if(!visited[i]&&i!=node) {
			visited[i]=1;
			dfs(depth+1, i, time+G[node][i]);
			visited[i]=0;
		}
}

int main(void) {
	int K, i, j, k;
	scanf("%d%d", &N, &K);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			scanf("%d", &G[i][j]);
	for(k=0 ; k<N ; k++)
		for(i=0 ; i<N ; i++)
			for(j=0 ; j<N ; j++)
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	visited[K]=1;
	dfs(1, K, 0);
	printf("%d", min);
	return 0;
}