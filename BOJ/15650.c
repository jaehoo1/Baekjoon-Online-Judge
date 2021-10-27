# include <stdio.h>

typedef enum { false, true }bool;

int N, M, arr[9];
bool visited[9];

void dfs(int N, int M, int depth) {
	int i;
	if(depth==M) {
		for(i=0 ; i<M ; i++)
			printf("%d ", arr[i]);
		puts("");
		return;
	}
	for(i=1 ; i<=N ; i++) {
		if(!visited[i])
			if(!depth||arr[depth-1]<i) {
				visited[i]=true;
				arr[depth]=i;
				dfs(N, M, depth+1);
				visited[i]=false;
			}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);
	dfs(N, M, 0);
	return 0;
}
