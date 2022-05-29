# include <stdio.h>
# include <stdlib.h>

typedef struct { int h1, h2, k; }edge;

int parent[100001];

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
int edgecmp(const edge *a, const edge *b) {
	if(a->k>b->k)
		return -1;
	if(a->k<b->k)
		return 1;
	return 0;
}

int main(void) {
	int N, M, s, e, i;
	edge G[300000];
	scanf("%d%d%d%d", &N, &M, &s, &e);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=0 ; i<M ; i++)
		scanf("%d%d%d", &G[i].h1, &G[i].h2, &G[i].k);
	qsort(G, M, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<M&&find(s)!=find(e) ; i++)
		if(find(G[i].h1)!=find(G[i].h2))
			union_set(G[i].h1, G[i].h2);
	if(find(s)==find(e))
		printf("%d", G[i-1].k);
	else
		puts("0");
	return 0;
}
