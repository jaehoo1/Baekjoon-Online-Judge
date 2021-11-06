# include <stdio.h>
# include <stdlib.h>

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
int edgecmp(const edge *a, const edge *b) {
	if(a->c>b->c)return -1;
	else if(a->c<b->c)return 1;
	else	return 0;
}

int main(void) {
	int p, w, c, v, i, min;
	edge arr[50000];
	scanf("%d%d", &p, &w);
	for(i=0 ; i<p ; i++)
		parent[i]=i;
	scanf("%d%d", &c, &v);
	for(i=0 ; i<w ; i++)
		scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].c);
	qsort(arr, w, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<w ; i++) {
		if(find(arr[i].s)!=find(arr[i].d)) {
			union_set(arr[i].s, arr[i].d);
			min=arr[i].c;
		}
		if(find(c)==find(v))
			break;
	}
	printf("%d", min);
	return 0;
}
