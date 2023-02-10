# include <stdio.h>
# include <stdlib.h>

typedef struct { int s, d, c; }edge;

int parent[100001];

int edgecmp(const edge *a, const edge *b) { return a->c>b->c; }
int find(int x) {
	if(x==parent[x])
		return x;
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
	int n, m, i, max=0;
	edge arr[100000];
	scanf("%d%d", &n, &m);
	for(i=1 ; i<=n ; i++)
		parent[i]=i;
	for(i=0 ; i<m ; i++)
		scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].c);
	qsort(arr, m, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<m ; i++)
		if(find(arr[i].s)!=find(arr[i].d)) {
			union_set(arr[i].s, arr[i].d);
			if(arr[i].c>max)
				max=arr[i].c;
		}
	printf("%d", max);
	return 0;
}