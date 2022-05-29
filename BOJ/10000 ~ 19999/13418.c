# include <stdio.h>

typedef struct { int s, d, c; }edge;

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
int edgecmp(const edge *a, const edge *b) { return a->c>b->c; }

int main(void) {
	int N, M, i, max=0, min=0;
	edge arr[500000];
	scanf("%d%d", &N, &M);
	for(i=0 ; i<M+1 ; i++)
		scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].c);
	for(i=0 ; i<=N ; i++)
		parent[i]=i;
	qsort(arr, M+1, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<M+1 ; i++)
		if(find(arr[i].s)!=find(arr[i].d)) {
			union_set(arr[i].s, arr[i].d);
			if(!arr[i].c)
				max++;
		}
	for(i=0 ; i<=N ; i++)
		parent[i]=i;
	for(i=M ; i!=-1 ; i--)
		if(find(arr[i].s)!=find(arr[i].d)) {
			union_set(arr[i].s, arr[i].d);
			if(!arr[i].c)
				min++;
		}
	printf("%d", max*max-min*min);
	return 0;
}
