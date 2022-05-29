# include <stdio.h>
# include <stdlib.h>

int N, M, arr[8], tree[8];

void dfs(int depth);
int intcmp(const int *a, const int *b) { return *a>*b; }
void next(int depth, int num) {
	tree[depth]=num;
	dfs(depth+1);
}
void dfs(int depth) {
	int i;
	if(depth==M) {
		for(i=0 ; i<M ; i++)
			printf("%d ", tree[i]);
		puts("");
		return;
	}
	for(i=0 ; i<N ; i++) {
		if(depth) {
			if(i)
				if(arr[i]==arr[i-1])
					continue;
			if(arr[i]<tree[depth-1])
				continue;
			next(depth, arr[i]);
		} else if(i) {
			if(arr[i]==arr[i-1])
				continue;
			next(depth, arr[i]);
		} else
			next(depth, arr[i]);
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
