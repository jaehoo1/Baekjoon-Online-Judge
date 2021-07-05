# include <stdio.h>

typedef enum boolean {
	FALSE, TRUE
}bool;

bool visit[8];
int arr[8];
void dfs(int N, int M, int depth) {
	int i;
	if(depth==M) {
		for(i=0 ; i<M ; i++)
			printf("%d ", arr[i]);
		puts("");
		return;
	}
	for(i=0 ; i<N ; i++)
		if(!visit[i]) {
			visit[i]=TRUE;
			arr[depth]=i+1;
			dfs(N, M, depth+1);
			visit[i]=FALSE;
		}
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	dfs(N, M, 0);
	return 0;
}
