# include <stdio.h>

int parent[1001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}

int main(void) {
	int T, N, M, a, b, i, cou;
	scanf("%d", &T);
	while(T--) {
		cou=0;
		scanf("%d%d", &N, &M);
		for(i=1 ; i<=N ; i++)
			parent[i]=i;
		while(M--) {
			scanf("%d%d", &a, &b);
			if(find(a)!=find(b)) {
				union_set(a, b);
				cou++;
			}
		}
		printf("%d\n", cou);
	}
	return 0;
}
