# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct { int x, y, z, idx; }node;
typedef struct { int a, b, c; }edge;

int parent[100001];

//int abs(int x) { return x<0?-x:x; }
int xcmp(const node *a, const node *b) { return a->x<b->x; }
int ycmp(const node *a, const node *b) { return a->y<b->y; }
int zcmp(const node *a, const node *b) { return a->z<b->z; }
int edgecmp(const edge *a, const edge *b) {
	if(a->c<b->c)return -1;
	else if(a->c>b->c)return 1;
	else	return 0;
}
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

int main(void) {
	int N, i, ptr=0;
	long long cost=0;
	node arr[100001];
	edge line[300000];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].z);
		arr[i].idx=i+1;
	}
	qsort(arr, N, sizeof(node), (int(*)(const void*, const void*))xcmp);
	for(i=0 ; i<N-1 ; i++) {
		line[ptr].a=arr[i].idx;
		line[ptr].b=arr[i+1].idx;
		line[ptr++].c=abs(arr[i].x-arr[i+1].x);
	}
	qsort(arr, N, sizeof(node), (int(*)(const void*, const void*))ycmp);
	for(i=0 ; i<N-1 ; i++) {
		line[ptr].a=arr[i].idx;
		line[ptr].b=arr[i+1].idx;
		line[ptr++].c=abs(arr[i].y-arr[i+1].y);
	}
	qsort(arr, N, sizeof(node), (int(*)(const void*, const void*))zcmp);
	for(i=0 ; i<N-1 ; i++) {
		line[ptr].a=arr[i].idx;
		line[ptr].b=arr[i+1].idx;
		line[ptr++].c=abs(arr[i].z-arr[i+1].z);
	}
	qsort(line, ptr, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=0 ; i<ptr ; i++)
		if(find(line[i].a)!=find(line[i].b)) {
			union_set(line[i].a, line[i].b);
			cost+=line[i].c;
		}
	printf("%lld", cost);
	return 0;
}
