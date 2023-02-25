# include <stdio.h>
# include <stdlib.h>

typedef struct { int s, d, c; }edge;

int parent[21];

int edgecmp(const edge *a, const edge *b) { return a->c>b->c; }
int find(int x) {
	if(x==parent[x])
		return x;
	return x=find(parent[x]);
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
	int T, N, M, t, i, dist;
	edge arr[380];
	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		dist=0;
		scanf("%d%d", &N, &M);
		for(i=1 ; i<=N ; i++)
			parent[i]=i;
		for(i=0 ; i<M ; i++)
			scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].c);
		qsort(arr, M, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
		for(i=0 ; i<M ; i++)
			if(find(arr[i].s)!=find(arr[i].d)) {
				union_set(arr[i].s, arr[i].d);
				dist+=arr[i].c;
			}
		printf("Case #%d: %d meters\n", t, dist);
	}
	return 0;
}