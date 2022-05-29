# include <stdio.h>
# include <stdlib.h>

int N, M, arr[7], node[7];

int intcmp(const int *a, const int *b) { return *a>*b; }
void dfs(int depth) {
	int i;
	if(depth==M) {
		for(i=0 ; i<M ; i++)
			printf("%d ", node[i]);
		puts("");
		return;
	}
	for(i=0 ; i<N ; i++) {
		node[depth]=arr[i];
		dfs(depth+1);
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
