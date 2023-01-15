# include <stdio.h>
# include <stdlib.h>

typedef struct { int s, d, c; }edge;

int P, parent[51];

int edgecmp(const edge *a, const edge *b) {
	if(a->c<b->c)
		return -1;
	else if(a->c>b->c)
		return 1;
	else
		return 0;
}
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
	int R, i, total;
	edge arr[100000];
	while(scanf("%d", &P)) {
		if(!P)
			break;
		total=0;
		for(i=1 ; i<=P ; i++)
			parent[i]=i;
		scanf("%d", &R);
		for(i=0 ; i<R ; i++)
			scanf("%d%d%d", &arr[i].s, &arr[i].d, &arr[i].c);
		qsort(arr, R, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
		for(i=0 ; i<R ; i++)
			if(find(arr[i].s)!=find(arr[i].d)) {
				union_set(arr[i].s, arr[i].d);
				total+=arr[i].c;
			}
		printf("%d\n", total);
	}
	return 0;
}