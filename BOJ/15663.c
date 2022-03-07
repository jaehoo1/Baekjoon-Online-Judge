# include <stdio.h>
# include <stdlib.h>

int N, M, arr[8], tree[8], visited[8];

int intcmp(const int *a, const int *b) { return *a>*b; }

void dfs(int depth) {
	int i, pre=0;
	if(depth==M) {
		for(i=0 ; i<M ; i++)
			printf("%d ", tree[i]);
		puts("");
		return ;
	}
	for(i=0 ; i<N ; i++)
		if(!visited[i]&&arr[i]!=pre) {
			visited[i]=1;
			tree[depth]=pre=arr[i];
			dfs(depth+1);
			visited[i]=0;
		}
}

int main(void) {
	int i;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	dfs(0);
	return 0;
}
