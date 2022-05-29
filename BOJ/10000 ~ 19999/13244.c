# include <stdio.h>

int parent[1001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=a;
	else	parent[a]=b;
}

int main(void) {
	int T, N, M, A, B, i, flag;
	scanf("%d", &T);
	while(T--) {
		flag=1;
		scanf("%d%d", &N, &M);
		for(i=1 ; i<=N ; i++)
			parent[i]=i;
		for(i=0 ; i<M ; i++) {
			scanf("%d%d", &A, &B);
			if(find(A)==find(B))
				flag=0;
			else
				union_set(A, B);
		}
		if(flag&&N-1==M)
			puts("tree");
		else
			puts("graph");
	}
	return 0;
}
