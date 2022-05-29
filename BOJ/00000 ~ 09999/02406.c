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
	if(a->c<b->c)return -1;
	else if(a->c>b->c)return 1;
	else	return 0;
}

int main(void) {
	int n, m, i, j, cost, x, y, ptr=0, X=0, K=0, res[1000][2];
	edge arr[1000000];
	scanf("%d%d", &n, &m);
	for(i=1 ; i<=n ; i++)
		parent[i]=i;
	while(m--) {
		scanf("%d%d", &x, &y);
		union_set(x, y);
	}
	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=n ; j++) {
			scanf("%d", &cost);
			if(i==1||j==1)continue;
			arr[ptr].s=i;
			arr[ptr].d=j;
			arr[ptr++].c=cost;
		}
	qsort(arr, ptr, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<ptr ; i++)
		if(find(arr[i].s)!=find(arr[i].d)) {
			union_set(arr[i].s, arr[i].d);
			X+=arr[i].c;
			res[K][0]=arr[i].s;
			res[K++][1]=arr[i].d;
		}
	printf("%d %d\n", X, K);
	for(i=0 ; i<K ; i++)
		printf("%d %d\n", res[i][0], res[i][1]);
	return 0;
}
