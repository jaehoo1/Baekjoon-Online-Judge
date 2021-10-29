# include <stdio.h>

int arr[7];

void dfs(int N, int M, int depth) {
	int i;
	if(depth==M) {
		for(i=0 ; i<M ; i++)
			printf("%d ", arr[i]);
		puts("");
		return;
	}
	for(i=1 ; i<=N ; i++) {
		arr[depth]=i;
		dfs(N, M, depth+1);
	}
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	dfs(N, M, 0);
	return 0;
}
