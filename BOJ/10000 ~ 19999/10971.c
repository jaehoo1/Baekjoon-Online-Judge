# include <stdio.h>

int N, G[10][10], min=10000000, tree[10], visited[10];

void dfs(int depth, int sum) {
	int i;
	if(depth==N) {
		if(!G[tree[depth-1]][tree[0]])
			return;
		sum+=G[tree[depth-1]][tree[0]];
		if(sum<min)
			min=sum;
		return;
	}
	for(i=0 ; i<N ; i++)
		if(depth) {
			if(visited[i]||!G[tree[depth-1]][i])
				continue;
			visited[i]=1;
			tree[depth]=i;
			dfs(depth+1, sum+G[tree[depth-1]][i]);
			visited[i]=0;
		} else {
			visited[i]=1;
			tree[depth]=i;
			dfs(depth+1, 0);
			visited[i]=0;
		}
}

int main(void) {
	int i, j;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			scanf("%d", &G[i][j]);
	dfs(0, 0);
	printf("%d", min);
	return 0;
}
