# include <stdio.h>

typedef enum { false, true }bool;

int parent[1024], D[1024];
bool visited[1024];

int dfs(int n, int depth) {
	int i, next;
	visited[n]=true;
	D[n]=depth;
	for(i=0 ; i<2 ; i++) {
		next=2*n+i;
		if(next>=1024)continue;
		if(visited[next])continue;
		parent[next]=n;
		dfs(next, n+1);
	}
}
int lca(int a, int b) {
	while(D[a]!=D[b])
		if(D[a]<D[b])
			b=parent[b];
		else
			a=parent[a];
	while(a!=b) {
		a=parent[a];
		b=parent[b];
	}
	return a;
}

int main(void) {
	int T, A, B;
	dfs(1, 0);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &A, &B);
		printf("%d0\n", lca(A, B));
	}
	return 0;
}
