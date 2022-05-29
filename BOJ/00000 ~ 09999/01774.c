# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct { int x, y; }pos;
typedef struct {
	int s, d;
	double c;
}edge;

int parent[1001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=parent[a];
	else	parent[a]=parent[b];
}
double dist(pos a, pos b) {
	return sqrt((double)(((long long)a.x-b.x)*(a.x-b.x)+((long long)a.y-b.y)*(a.y-b.y)));
}
int edgecmp(const edge *a, const edge *b) {
	if(a->c<b->c)return -1;
	else if(a->c>b->c)return 1;
	else	return 0;
}

int main(void) {
	int N, M, i, j, ptr=0, a, b;
	double cost=0;
	pos node[1000];
	edge arr[1000000];
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=0 ; i<N ; i++)
		scanf("%d%d", &node[i].x, &node[i].y);
	for(i=0 ; i<N-1 ; i++)
		for(j=i+1 ; j<N ; j++) {
			arr[ptr].s=i+1;
			arr[ptr].d=j+1;
			arr[ptr++].c=dist(node[i], node[j]);
		}
	qsort(arr, ptr, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	while(M--) {
		scanf("%d%d", &a, &b);
		union_set(a, b);
	}
	for(i=0 ; i<ptr ; i++)
		if(find(arr[i].s)!=find(arr[i].d)) {
			union_set(arr[i].s, arr[i].d);
			cost+=arr[i].c;
		}
	printf("%.2lf", cost);
	return 0;
}
