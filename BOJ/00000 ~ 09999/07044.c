# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int s, d, c;
}edge;

int parent[1001];

int edgecmp(const edge *a, const edge *b) {
	if(a->c>b->c)return -1;
	else if(a->c<b->c)return 1;
	else	return 0;
}
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
	int N, M, i, cost=0, cou=0;
	edge arr[20000];
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=0 ; i<M ; i++)
		scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].c);
	qsort(arr, M, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<M ; i++)
		if(find(arr[i].s)!=find(arr[i].d)) {
			union_set(arr[i].s, arr[i].d);
			cost+=arr[i].c;
			if(++cou==N-1)break;
		}
	printf("%d", cou==N-1?cost:-1);
	return 0;
}
